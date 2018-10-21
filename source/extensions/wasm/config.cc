#include "extensions/wasm/config.h"

#include "envoy/registry/registry.h"

#include "common/protobuf/utility.h"

#include "extensions/common/wasm/wasm.h"

namespace Envoy {
namespace Extensions {
namespace Wasm {

Server::WasmPtr WasmFactory::createWasm(
    const envoy::config::wasm::v2::WasmConfig& config,
    Server::Configuration::WasmFactoryContext& context) {
  auto vm = Common::Wasm::createWasmVm(config.wasm_vm());
  if (vm) {
    vm->initialize(config.wasm_file());
    vm->configure(config.wasm_configuration());
    vm->start(context.dispatcher());
  }
  return vm;
}

/**
 * Static registration for the wasm factory. @see RegistryFactory.
 */
static Registry::RegisterFactory<WasmFactory, Server::Configuration::WasmFactory> registered_;

} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
