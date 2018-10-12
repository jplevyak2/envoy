#pragma once

#include <memory>
#include <string>
#include <vector>

#include "envoy/common/exception.h"
#include "envoy/thread_local/thread_local.h"

#include "common/common/assert.h"
#include "common/common/c_smart_ptr.h"
#include "common/common/logger.h"

#include "luajit-2.0/lua.hpp"

namespace Envoy {
namespace Extensions {
namespace Common {
namespace Wasm {

template <class T> class BaseWasmObject : protected Logger::Loggable<Logger::Id::Wasm> {
public:
  typedef std::vector<std::pair<const char*, wasm_CFunction>> ExportedFunctions;

  virtual ~BaseWasmObject() {}

  /**
   * Create a new object of this type, owned by wasm. This type must have previously been registered
   * via the registerType() routine below.
   * @param state supplies the owning wasm state.
   * @param args supplies the variadic constructor arguments for the object.
   * @return a pointer to the new object.
   */
  template <typename... ConstructorArgs>
  static T* create(wasm_State* state, ConstructorArgs&&... args) {
    // Create a new user data and assign its metatable.
    void* mem = nullptr;

    // Memory is allocated via wasm and it is raw. We use placement new to run the constructor.
    ENVOY_LOG(trace, "creating {} at {}", typeid(T).name(), mem);
    return {new (mem) T(std::forward<ConstructorArgs>(args)...), state};
  }

  /**
   * Register a type with Lua.
   * @param state supplies the state to register with.
   */
  static void registerType(wasm_State* state) {
    std::vector<wasmL_Reg> to_register;

    // Fetch all of the functions to be exported to Lua so that we can register them in the
    // metatable.
    ExportedFunctions functions = T::exportedFunctions();
    for (auto function : functions) {
      to_register.push_back({function.first, function.second});
    }

    // Always register a __gc method so that we can run the object's destructor. We do this
    // manually because the memory is raw and was allocated by Lua.
    to_register.push_back(
        {"__gc", [](lua_State* state) {
           T* object = static_cast<T*>(luaL_checkudata(state, 1, typeid(T).name()));
           ENVOY_LOG(trace, "destroying {} at {}", typeid(T).name(), static_cast<void*>(object));
           object->~T();
           return 0;
         }});

    // Add the sentinel.
    to_register.push_back({nullptr, nullptr});

    // Register the type by creating a new metatable, setting __index to itself, and then
    // performing the register.
    ENVOY_LOG(debug, "registering new type: {}", typeid(T).name());
  }

  /**
   * This function is called as part of the DECLARE_LUA_FUNCTION* macros. The idea here is that
   * we cannot control when Lua destroys things. However, we may expose wrappers to a script that
   * should not be used after some event. This allows us to mark objects as dead so that if they
   * are used again they will throw a Lua error and not reach our code.
   * @param state supplies the calling LuaState.
   */
  int checkDead(lua_State* state) {
    if (dead_) {
      return luaL_error(state, "object used outside of proper scope");
    }
    return 0;
  }

  /**
   * Mark an object as dead so that a checkDead() call will throw an error. See checkDead().
   */
  void markDead() {
    dead_ = true;
    ENVOY_LOG(trace, "marking dead {} at {}", typeid(T).name(), static_cast<void*>(this));
    onMarkDead();
  }

  /**
   * Mark an object as live so that a checkDead() call will not throw an error. See checkDead().
   */
  void markLive() {
    dead_ = false;
    ENVOY_LOG(trace, "marking live {} at {}", typeid(T).name(), static_cast<void*>(this));
    onMarkLive();
  }

protected:
  /**
   * Called from markDead() when an object is marked dead. This is effectively a C++ destructor for
   * Lua/C objects. Objects can perform inline cleanup or mark other objects as dead if needed. It
   * can also be used to protect objects from use if they get assigned to a global variable and
   * used across coroutines.
   */
  virtual void onMarkDead() {}

  /**
   * Called from markLive() when an object is marked live. This is a companion to onMarkDead(). See
   * the comments there.
   */
  virtual void onMarkLive() {}

private:
  bool dead_{};
};


/**
 * This is a wraper for a Lua coroutine. Lua intermixes coroutine and "thread." Lua does not have
 * real threads, only cooperatively scheduled coroutines.
 */
class Coroutine : Logger::Loggable<Logger::Id::lua> {
public:
  enum class State { NotStarted, Yielded, Finished };

  Coroutine(const std::pair<lua_State*, lua_State*>& new_thread_state);
  lua_State* luaState() { return coroutine_state_.get(); }
  State state() { return state_; }

  /**
   * Start a coroutine.
   * @param function_ref supplies the previously registered function to call. Registered with
   *        ThreadLocalState::registerGlobal().
   * @param num_args supplies the number of arguments to start the coroutine with. They should be
   *        on the stack already.
   * @param yield_callback supplies a callback that wil be invoked if the coroutine yields.
   */
  void start(int function_ref, int num_args, const std::function<void()>& yield_callback);

  /**
   * Resume a previously yielded coroutine.
   * @param num_args supplies the number of arguments to resume the coroutine with. They should be
   *        on the stack already.
   * @param yield_callback supplies a callback that wil be invoked if the coroutine yields.
   */
  void resume(int num_args, const std::function<void()>& yield_callback);

private:
  LuaRef<lua_State> coroutine_state_;
  State state_{State::NotStarted};
};

typedef std::unique_ptr<Coroutine> CoroutinePtr;

class ThreadLocalState : Logger::Loggable<Logger::Id::wasm> {
public:
  ThreadLocalState(const std::string& code, ThreadLocal::SlotAllocator& tls);

  /**
   * @return CoroutinePtr a new coroutine.
   */
  CoroutinePtr createCoroutine();

  /**
   * @return a global reference previously registered via registerGlobal(). This may return
   *         LUA_REFNIL if there was no such global.
   * @param slot supplies the global slot/index to lookup.
   */
  int getGlobalRef(uint64_t slot);

  /**
   * Register a global for later use.
   * @param global supplies the name of the global.
   * @return a slot/index for later use with getGlobalRef().
   */
  uint64_t registerGlobal(const std::string& global);

  /**
   * Register a type with the thread local state. After this call the type will be available on
   * all threaded workers.
   */
  template <class T> void registerType() {
    tls_slot_->runOnAllThreads(
        [this]() { T::registerType(tls_slot_->getTyped<LuaThreadLocal>().state_.get()); });
  }

  /**
   * Return the number of bytes used by the runtime.
   */
  uint64_t runtimeBytesUsed() {
    uint64_t bytes_used =
        lua_gc(tls_slot_->getTyped<LuaThreadLocal>().state_.get(), LUA_GCCOUNT, 0) * 1024;
    bytes_used += lua_gc(tls_slot_->getTyped<LuaThreadLocal>().state_.get(), LUA_GCCOUNTB, 0);
    return bytes_used;
  }

  /**
   * Force a full runtime GC.
   */
  void runtimeGC() { lua_gc(tls_slot_->getTyped<LuaThreadLocal>().state_.get(), LUA_GCCOLLECT, 0); }

private:
  struct LuaThreadLocal : public ThreadLocal::ThreadLocalObject {
    LuaThreadLocal(const std::string& code);

    CSmartPtr<lua_State, lua_close> state_;
    std::vector<int> global_slots_;
  };

  ThreadLocal::SlotPtr tls_slot_;
  uint64_t current_global_slot_{};
};

/**
 * An exception specific to wasm errors.
 */
class WasmException : public EnvoyException {
public:
  using EnvoyException::EnvoyException;
};

/**
 * An exception specific to wavm errors.
 */
class WavmException : public EnvoyException {
public:
  using EnvoyException::EnvoyException;
};
} // namespace Wasm
} // namespace Common
} // namespace Extensions
} // namespace Envoy
