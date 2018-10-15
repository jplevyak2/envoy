# BUILD file for locally installed https://github.com/WAVM/WAVM.

cc_library(
  name = "lib",
  srcs = [
    "lib/WAVM/RelWithDebInfo/libEmscripten.so",
    "lib/WAVM/RelWithDebInfo/libIR.so",
    "lib/WAVM/RelWithDebInfo/libLLVMJIT.so",
    "lib/WAVM/RelWithDebInfo/libLogging.so",
    "lib/WAVM/RelWithDebInfo/libNFA.so",
    "lib/WAVM/RelWithDebInfo/libPlatform.so",
    "lib/WAVM/RelWithDebInfo/libRegExp.so",
    "lib/WAVM/RelWithDebInfo/libRuntime.so",
    "lib/WAVM/RelWithDebInfo/libThreadTest.so",
    "lib/WAVM/RelWithDebInfo/libWASM.so",
    "lib/WAVM/RelWithDebInfo/libWASTParse.so",
    "lib/WAVM/RelWithDebInfo/libWASTPrint.so",
    "lib/WAVM/RelWithDebInfo/libEmscripten.a",
    "lib/WAVM/RelWithDebInfo/libIR.a",
    "lib/WAVM/RelWithDebInfo/libLLVMJIT.a",
    "lib/WAVM/RelWithDebInfo/libLogging.a",
    "lib/WAVM/RelWithDebInfo/libNFA.a",
    "lib/WAVM/RelWithDebInfo/libPlatform.a",
    "lib/WAVM/RelWithDebInfo/libRegExp.a",
    "lib/WAVM/RelWithDebInfo/libRuntime.a",
    "lib/WAVM/RelWithDebInfo/libThreadTest.a",
    "lib/WAVM/RelWithDebInfo/libWASM.a",
    "lib/WAVM/RelWithDebInfo/libWASTParse.a",
    "lib/WAVM/RelWithDebInfo/libWASTPrint.a",
  ],
  hdrs = [
    "include/WAVM/Emscripten/Emscripten.h",
    "include/WAVM/Inline/Assert.h",
    "include/WAVM/Inline/BasicTypes.h",
    "include/WAVM/Inline/CLI.h",
    "include/WAVM/Inline/ConcurrentHashMap.h",
    "include/WAVM/Inline/Config.h",
    "include/WAVM/Inline/DenseStaticIntSet.h",
    "include/WAVM/Inline/Errors.h",
    "include/WAVM/Inline/FloatComponents.h",
    "include/WAVM/Inline/Hash.h",
    "include/WAVM/Inline/HashMap.h",
    "include/WAVM/Inline/HashMapImpl.h",
    "include/WAVM/Inline/HashSet.h",
    "include/WAVM/Inline/HashSetImpl.h",
    "include/WAVM/Inline/HashTable.h",
    "include/WAVM/Inline/HashTableImpl.h",
    "include/WAVM/Inline/IndexMap.h",
    "include/WAVM/Inline/IntrusiveSharedPtr.h",
    "include/WAVM/Inline/IsNameChar.h",
    "include/WAVM/Inline/Lock.h",
    "include/WAVM/Inline/OptionalStorage.h",
    "include/WAVM/Inline/Serialization.h",
    "include/WAVM/Inline/Timing.h",
    "include/WAVM/Inline/Unicode.h",
    "include/WAVM/Inline/xxhash/xxhash.h",
    "include/WAVM/IR/IR.h",
    "include/WAVM/IR/Module.h",
    "include/WAVM/IR/OperatorPrinter.h",
    "include/WAVM/IR/Operators.h",
    "include/WAVM/IR/OperatorTable.h",
    "include/WAVM/IR/Types.h",
    "include/WAVM/IR/Validate.h",
    "include/WAVM/IR/Value.h",
    "include/WAVM/LLVMJIT/LLVMJIT.h",
    "include/WAVM/Logging/Logging.h",
    "include/WAVM/NFA/NFA.h",
    "include/WAVM/Platform/Defines.h",
    "include/WAVM/Platform/Diagnostics.h",
    "include/WAVM/Platform/Event.h",
    "include/WAVM/Platform/Exception.h",
    "include/WAVM/Platform/File.h",
    "include/WAVM/Platform/Intrinsic.h",
    "include/WAVM/Platform/Memory.h",
    "include/WAVM/Platform/Mutex.h",
    "include/WAVM/Platform/Thread.h",
    "include/WAVM/RegExp/RegExp.h",
    "include/WAVM/Runtime/Intrinsics.h",
    "include/WAVM/Runtime/Linker.h",
    "include/WAVM/Runtime/RuntimeData.h",
    "include/WAVM/Runtime/Runtime.h",
    "include/WAVM/ThreadTest/ThreadTest.h",
    "include/WAVM/WASM/WASM.h",
    "include/WAVM/WASTParse/TestScript.h",
    "include/WAVM/WASTParse/WASTParse.h",
    "include/WAVM/WASTPrint/WASTPrint.h",
  ],
  visibility = ["//visibility:public"],
)
