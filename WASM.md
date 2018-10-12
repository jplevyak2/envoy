Proof of Concept Webassembly Support.

# Webassembly VM

The Webassembly VM is https://github.com/WAVM/WAVM.  This VM was chosen for the
proof of concept because:

  - It is OSS with a permissive licencse.
  - It compiles with LLVM for high performance.
  - It can attach pre-compiled code to the WASM files (e.g. during distribution
      from a central controller) for faster startup and reduced load on a pool
      of proxies.

# Dependencies

WAVM requires LLVM 6+.

# Installation

Install as per the instructions in https://github.com/WAVM/WAVM.
This is temporary until we can make the build hygentic.
