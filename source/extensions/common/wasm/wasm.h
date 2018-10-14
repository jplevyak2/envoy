#pragma once

#include <memory>
#include <string>
#include <vector>

#include "envoy/common/exception.h"
#include "envoy/server/wasm.h"
#include "envoy/config/wasm/v2/wasm.pb.validate.h"
#include "envoy/thread_local/thread_local.h"

#include "common/common/assert.h"
#include "common/common/c_smart_ptr.h"
#include "common/common/logger.h"

namespace Envoy {
namespace Extensions {
namespace Common {
namespace Wasm {

#define wasmL_checkudata(a, b, c) nullptr

#define DECLARE_WASM_FUNCTION_EX(Class, Name, Index)                                                \
  static int static_##Name(wasm_State* state) {                                                     \
    Class* object = static_cast<Class*>(wasmL_checkudata(state, Index, typeid(Class).name()));      \
    /* object->checkDead(state);  */                                                                \
    return object->Name(state);                                                                     \
  }                                                                                                 \
  int Name(wasm_State* state);

#define wasm_upvalueindex(x) x

#define DECLARE_WASM_FUNCTION(Class, Name) DECLARE_WASM_FUNCTION_EX(Class, Name, 1)

#define DECLARE_WASM_CLOSURE(Class, Name) DECLARE_WASM_FUNCTION_EX(Class, Name, wasm_upvalueindex(1))


class Coroutine {
  public:
};
using CoroutinePtr = std::unique_ptr<Coroutine>;
template <typename T> class WasmRef {
   public:
     void reset() {}
};
class wasm_State;

class BufferWrapper;
class ConnectionWrapper;
class MetadataMapWrapper;

class ThreadLocalState : Logger::Loggable<Logger::Id::wasm> {
  public:
    ThreadLocalState(const std::string& code, ThreadLocal::SlotAllocator& tls);
    CoroutinePtr createCoroutine() { return nullptr; }
    int getGlobalRef(uint64_t slot);
    uint64_t registerGlobal(const std::string& global);
    uint64_t runtimeBytesUsed() { return 0; }
    void runtimeGC() {}
};

typedef int (*wasm_CFunction)(wasm_State*);
typedef std::vector<std::pair<const char*, wasm_CFunction>> ExportedFunctions;

Server::WasmPtr createWasmVm(const std::string& wasm_vm);

class WasmException : public EnvoyException {
  public:
    using EnvoyException::EnvoyException;
};

class WasmVmException : public EnvoyException {
  public:
    using EnvoyException::EnvoyException;
};

} // namespace Wasm
} // namespace Common
} // namespace Extensions
} // namespace Envoy
