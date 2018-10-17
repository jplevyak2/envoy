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

Install both the dynamic and static version:
  cmake -DWAVME_ENABLE_STGATIC_LINKING=OFF .
  make
  sudo make install
  cmake -DWAVM_ENABLE_STATIC_LINKING=ON ...
  make
  sudo make install

# TODO

  - Check if the thread is running in the VM in the WAVM Runtime signal handlers and
    if not call the underlying signal handler from Envoy or add the WAVM signal handler
    as a pre-check to the Envoy signal handler with the same check.
  - Add support to WAVM for multple stacks for coroutines/streams with thread shared state.
  - Add support for shared global state.
  - Intercept logging messages from WAVM and send to Envoy logs.
