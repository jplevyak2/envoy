#include "extensions/wasm/config.h"

#include "envoy/registry/registry.h"

#include "common/protobuf/utility.h"

#include "extensions/common/wasm/wasm.h"

namespace Envoy {
namespace Extensions {
namespace Wasm {

Server::WasmPtr WasmFactory::createWasmFromProtoTyped(
    const envoy::config::wasm::v2::WasmConfig& config,
    Server::Configuration::WasmFactoryContext& /*unused_context*/) {
  auto vm = Common::Wasm::createWasmVm(config.wasm_vm());
  vm->initialize(config.wasm_file());
  vm->configure(config.wasm_configuration());
  return vm;
}

/**
 * Static registration for the wasm factory. @see RegistryFactory.
 */
static Registry::RegisterFactory<WavmFactory, Server::Configuration::WasmFactory> registered_;

} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
