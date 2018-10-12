#include "extensions/wasm/wavm/config.h"

#include "envoy/registry/registry.h"

#include "common/protobuf/utility.h"

#include "extensions/wasm/wavm/wavm.h"

namespace Envoy {
namespace Extensions {
namespace Wasm {
namespace Wavm {

Server::WasmPtr WavmFactory::createWasmFromProtoTyped(
    const envoy::config::wasm::v2::WasmConfig& config,
    Server::Configuration::WasmFactoryContext& /*unused_context*/) {
  return std::make_unique<Wavm>(config);
}

/**
 * Static registration for the wasm factory. @see RegistryFactory.
 */
static Registry::RegisterFactory<WavmFactory, Server::Configuration::WasmFactory> registered_;

} // namespace Wavm
} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
