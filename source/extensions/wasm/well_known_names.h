#pragma once

#include "common/singleton/const_singleton.h"

namespace Envoy {
namespace Extensions {
namespace Wasm {

/**
 * Well-known wasm VM names.
 * NOTE: New wasm VMs should use the well known name: envoy.wasm_vm.name.
 */
class WasmVmValues {
public:
  // WAVM (https://github.com/WAVM/WAVM) Wasm VM.
  const std::string Wavm = "envoy.wavm_wasm_vm";
};

typedef ConstSingleton<WasmVmWValues> WasmVms;

} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
