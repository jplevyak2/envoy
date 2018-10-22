# BUILD file for locally installed https://github.com/WAVM/WAVM.

cc_library(
  name = "wavm",
  srcs = [
    "local/lib/WAVM/RelWithDebInfo/libEmscripten.a",
    "local/lib/WAVM/RelWithDebInfo/libRuntime.a",
    "local/lib/WAVM/RelWithDebInfo/libThreadTest.a",
    "local/lib/WAVM/RelWithDebInfo/libWASM.a",
    "local/lib/WAVM/RelWithDebInfo/libWASTParse.a",
    "local/lib/WAVM/RelWithDebInfo/libWASTPrint.a",
    "local/lib/WAVM/RelWithDebInfo/libIR.a",
    "local/lib/WAVM/RelWithDebInfo/libLLVMJIT.a",
    "local/lib/WAVM/RelWithDebInfo/libRegExp.a",
    "local/lib/WAVM/RelWithDebInfo/libNFA.a",
    "local/lib/WAVM/RelWithDebInfo/libLogging.a",
    "local/lib/WAVM/RelWithDebInfo/libPlatform.a",
    "local/lib/WAVM/libWAVMUnwind.a",
    "lib/llvm-6.0/lib/libLLVMLTO.a",
    "lib/llvm-6.0/lib/libLLVMPasses.a",
    "lib/llvm-6.0/lib/libLLVMObjCARCOpts.a",
    "lib/llvm-6.0/lib/libLLVMMIRParser.a",
    "lib/llvm-6.0/lib/libLLVMSymbolize.a",
    "lib/llvm-6.0/lib/libLLVMDebugInfoPDB.a",
    "lib/llvm-6.0/lib/libLLVMDebugInfoDWARF.a",
    "lib/llvm-6.0/lib/libLLVMCoverage.a",
    "lib/llvm-6.0/lib/libLLVMTableGen.a",
    "lib/llvm-6.0/lib/libLLVMDlltoolDriver.a",
    "lib/llvm-6.0/lib/libLLVMOrcJIT.a",
    "lib/llvm-6.0/lib/libLLVMAVRDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMAVRCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMAVRAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMAVRDesc.a",
    "lib/llvm-6.0/lib/libLLVMAVRInfo.a",
    "lib/llvm-6.0/lib/libLLVMAVRAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMWebAssemblyDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMWebAssemblyCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMWebAssemblyDesc.a",
    "lib/llvm-6.0/lib/libLLVMWebAssemblyInfo.a",
    "lib/llvm-6.0/lib/libLLVMWebAssemblyAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMXCoreDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMXCoreCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMXCoreDesc.a",
    "lib/llvm-6.0/lib/libLLVMXCoreInfo.a",
    "lib/llvm-6.0/lib/libLLVMXCoreAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMSystemZDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMSystemZCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMSystemZAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMSystemZDesc.a",
    "lib/llvm-6.0/lib/libLLVMSystemZInfo.a",
    "lib/llvm-6.0/lib/libLLVMSystemZAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMSparcDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMSparcCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMSparcAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMSparcDesc.a",
    "lib/llvm-6.0/lib/libLLVMSparcInfo.a",
    "lib/llvm-6.0/lib/libLLVMSparcAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMPowerPCDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMPowerPCCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMPowerPCAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMPowerPCDesc.a",
    "lib/llvm-6.0/lib/libLLVMPowerPCInfo.a",
    "lib/llvm-6.0/lib/libLLVMPowerPCAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMNVPTXCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMNVPTXDesc.a",
    "lib/llvm-6.0/lib/libLLVMNVPTXInfo.a",
    "lib/llvm-6.0/lib/libLLVMNVPTXAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMMSP430CodeGen.a",
    "lib/llvm-6.0/lib/libLLVMMSP430Desc.a",
    "lib/llvm-6.0/lib/libLLVMMSP430Info.a",
    "lib/llvm-6.0/lib/libLLVMMSP430AsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMMipsDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMMipsCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMMipsAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMMipsDesc.a",
    "lib/llvm-6.0/lib/libLLVMMipsInfo.a",
    "lib/llvm-6.0/lib/libLLVMMipsAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMLanaiDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMLanaiCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMLanaiAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMLanaiDesc.a",
    "lib/llvm-6.0/lib/libLLVMLanaiAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMLanaiInfo.a",
    "lib/llvm-6.0/lib/libLLVMHexagonDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMHexagonCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMHexagonAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMHexagonDesc.a",
    "lib/llvm-6.0/lib/libLLVMHexagonInfo.a",
    "lib/llvm-6.0/lib/libLLVMBPFDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMBPFCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMBPFAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMBPFDesc.a",
    "lib/llvm-6.0/lib/libLLVMBPFInfo.a",
    "lib/llvm-6.0/lib/libLLVMBPFAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMARMDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMARMCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMARMAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMARMDesc.a",
    "lib/llvm-6.0/lib/libLLVMARMInfo.a",
    "lib/llvm-6.0/lib/libLLVMARMAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMARMUtils.a",
    "lib/llvm-6.0/lib/libLLVMAMDGPUDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMAMDGPUCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMAMDGPUAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMAMDGPUDesc.a",
    "lib/llvm-6.0/lib/libLLVMAMDGPUInfo.a",
    "lib/llvm-6.0/lib/libLLVMAMDGPUAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMAMDGPUUtils.a",
    "lib/llvm-6.0/lib/libLLVMAArch64Disassembler.a",
    "lib/llvm-6.0/lib/libLLVMAArch64CodeGen.a",
    "lib/llvm-6.0/lib/libLLVMAArch64AsmParser.a",
    "lib/llvm-6.0/lib/libLLVMAArch64Desc.a",
    "lib/llvm-6.0/lib/libLLVMAArch64Info.a",
    "lib/llvm-6.0/lib/libLLVMAArch64AsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMAArch64Utils.a",
    "lib/llvm-6.0/lib/libLLVMObjectYAML.a",
    "lib/llvm-6.0/lib/libLLVMLibDriver.a",
    "lib/llvm-6.0/lib/libLLVMOption.a",
    "lib/llvm-6.0/lib/libLLVMWindowsManifest.a",
    "lib/llvm-6.0/lib/libLLVMX86Disassembler.a",
    "lib/llvm-6.0/lib/libLLVMX86AsmParser.a",
    "lib/llvm-6.0/lib/libLLVMX86CodeGen.a",
    "lib/llvm-6.0/lib/libLLVMGlobalISel.a",
    "lib/llvm-6.0/lib/libLLVMSelectionDAG.a",
    "lib/llvm-6.0/lib/libLLVMAsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMDebugInfoCodeView.a",
    "lib/llvm-6.0/lib/libLLVMDebugInfoMSF.a",
    "lib/llvm-6.0/lib/libLLVMX86Desc.a",
    "lib/llvm-6.0/lib/libLLVMMCDisassembler.a",
    "lib/llvm-6.0/lib/libLLVMX86Info.a",
    "lib/llvm-6.0/lib/libLLVMX86AsmPrinter.a",
    "lib/llvm-6.0/lib/libLLVMX86Utils.a",
    "lib/llvm-6.0/lib/libLLVMMCJIT.a",
    "lib/llvm-6.0/lib/libLLVMLineEditor.a",
    "lib/llvm-6.0/lib/libLLVMFuzzMutate.a",
    "lib/llvm-6.0/lib/libLLVMInterpreter.a",
    "lib/llvm-6.0/lib/libLLVMExecutionEngine.a",
    "lib/llvm-6.0/lib/libLLVMRuntimeDyld.a",
    "lib/llvm-6.0/lib/libLLVMCodeGen.a",
    "lib/llvm-6.0/lib/libLLVMTarget.a",
    "lib/llvm-6.0/lib/libLLVMCoroutines.a",
    "lib/llvm-6.0/lib/libLLVMipo.a",
    "lib/llvm-6.0/lib/libLLVMInstrumentation.a",
    "lib/llvm-6.0/lib/libLLVMVectorize.a",
    "lib/llvm-6.0/lib/libLLVMScalarOpts.a",
    "lib/llvm-6.0/lib/libLLVMLinker.a",
    "lib/llvm-6.0/lib/libLLVMIRReader.a",
    "lib/llvm-6.0/lib/libLLVMAsmParser.a",
    "lib/llvm-6.0/lib/libLLVMInstCombine.a",
    "lib/llvm-6.0/lib/libLLVMTransformUtils.a",
    "lib/llvm-6.0/lib/libLLVMBitWriter.a",
    "lib/llvm-6.0/lib/libLLVMAnalysis.a",
    "lib/llvm-6.0/lib/libLLVMProfileData.a",
    "lib/llvm-6.0/lib/libLLVMObject.a",
    "lib/llvm-6.0/lib/libLLVMMCParser.a",
    "lib/llvm-6.0/lib/libLLVMMC.a",
    "lib/llvm-6.0/lib/libLLVMBitReader.a",
    "lib/llvm-6.0/lib/libLLVMCore.a",
    "lib/llvm-6.0/lib/libLLVMBinaryFormat.a",
    "lib/llvm-6.0/lib/libLLVMSupport.a",
    "lib/llvm-6.0/lib/libLLVMDemangle.a",
    "lib/x86_64-linux-gnu/libtinfo.a",
    "lib/x86_64-linux-gnu/libz.a",
  ],
  hdrs = [
    "local/include/WAVM/Emscripten/Emscripten.h",
    "local/include/WAVM/Inline/Assert.h",
    "local/include/WAVM/Inline/BasicTypes.h",
    "local/include/WAVM/Inline/CLI.h",
    "local/include/WAVM/Inline/ConcurrentHashMap.h",
    "local/include/WAVM/Inline/Config.h",
    "local/include/WAVM/Inline/DenseStaticIntSet.h",
    "local/include/WAVM/Inline/Errors.h",
    "local/include/WAVM/Inline/FloatComponents.h",
    "local/include/WAVM/Inline/Hash.h",
    "local/include/WAVM/Inline/HashMap.h",
    "local/include/WAVM/Inline/HashMapImpl.h",
    "local/include/WAVM/Inline/HashSet.h",
    "local/include/WAVM/Inline/HashSetImpl.h",
    "local/include/WAVM/Inline/HashTable.h",
    "local/include/WAVM/Inline/HashTableImpl.h",
    "local/include/WAVM/Inline/IndexMap.h",
    "local/include/WAVM/Inline/IntrusiveSharedPtr.h",
    "local/include/WAVM/Inline/IsNameChar.h",
    "local/include/WAVM/Inline/Lock.h",
    "local/include/WAVM/Inline/OptionalStorage.h",
    "local/include/WAVM/Inline/Serialization.h",
    "local/include/WAVM/Inline/Timing.h",
    "local/include/WAVM/Inline/Unicode.h",
    "local/include/WAVM/Inline/xxhash/xxhash.h",
    "local/include/WAVM/IR/IR.h",
    "local/include/WAVM/IR/Module.h",
    "local/include/WAVM/IR/OperatorPrinter.h",
    "local/include/WAVM/IR/Operators.h",
    "local/include/WAVM/IR/OperatorTable.h",
    "local/include/WAVM/IR/Types.h",
    "local/include/WAVM/IR/Validate.h",
    "local/include/WAVM/IR/Value.h",
    "local/include/WAVM/LLVMJIT/LLVMJIT.h",
    "local/include/WAVM/Logging/Logging.h",
    "local/include/WAVM/NFA/NFA.h",
    "local/include/WAVM/Platform/Defines.h",
    "local/include/WAVM/Platform/Diagnostics.h",
    "local/include/WAVM/Platform/Event.h",
    "local/include/WAVM/Platform/Exception.h",
    "local/include/WAVM/Platform/File.h",
    "local/include/WAVM/Platform/Intrinsic.h",
    "local/include/WAVM/Platform/Memory.h",
    "local/include/WAVM/Platform/Mutex.h",
    "local/include/WAVM/Platform/Thread.h",
    "local/include/WAVM/RegExp/RegExp.h",
    "local/include/WAVM/Runtime/Intrinsics.h",
    "local/include/WAVM/Runtime/Linker.h",
    "local/include/WAVM/Runtime/RuntimeData.h",
    "local/include/WAVM/Runtime/Runtime.h",
    "local/include/WAVM/ThreadTest/ThreadTest.h",
    "local/include/WAVM/WASM/WASM.h",
    "local/include/WAVM/WASTParse/TestScript.h",
    "local/include/WAVM/WASTParse/WASTParse.h",
    "local/include/WAVM/WASTPrint/WASTPrint.h",
  ],
  visibility = ["//visibility:public"],
)
