#pragma once

#include "envoy/config/wasm/v2/wasm.pb.validate.h"
#include "envoy/server/wasm_config.h"

#include "extensions/wasm/wavm/wavm.h"

namespace Envoy {
namespace Extensions {
namespace Wasm {
namespace Wavm {

class WavmFactory : public Server::Configuration::WasmFactory {
public:
  Server::WasmPtr
  createWasm(const Protobuf::Message& config,
             Server::Configuration::WasmFactoryContext& context) override;
  ProtobufTypes::MessagePtr createEmptyConfigProto() override;
  std::string name() override;

private:
  Server::WasmPtr
  createWasmFromProtoTyped(const envoy::config::wasm::v2::WasmConfig& config,
                           Server::Configuration::WasmFactoryContext& context);
};

} // namespace Wavm
} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
