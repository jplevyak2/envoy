#pragma once

#include "envoy/common/pure.h"
#include "envoy/event/dispatcher.h"
#include "envoy/server/wasm.h"

#include "common/protobuf/protobuf.h"

namespace Envoy {
namespace Server {
namespace Configuration {

class WasmFactoryContext {
public:
  virtual ~WasmFactoryContext() {}

  /**
   * @return Event::Dispatcher& the main thread's dispatcher. This dispatcher should be used
   *         for all singleton processing.
   */
  virtual Event::Dispatcher& dispatcher() PURE;
};

/**
 * Implemented by wasm and registered via Registry::registerFactory()
 * or the convenience class RegistryFactory.
 */
class WasmFactory {
public:
  virtual ~WasmFactory() {}

  /**
   * Create a particular wasm VM.
   * @param config const ProtoBuf::Message& supplies the config for the resource monitor
   *        implementation.
   * @param context WasmFactoryContext& supplies the resource monitor's context.
   * @return WasmPtr the resource monitor instance. Should not be nullptr.
   * @throw EnvoyException if the implementation is unable to produce an instance with
   *        the provided parameters.
   */
  virtual WasmPtr createWasm(const Protobuf::Message& config, WasmFactoryContext& context) PURE;

  /**
   * @return ProtobufTypes::MessagePtr create empty config proto message. The resource monitor
   *         config, which arrives in an opaque google.protobuf.Struct message, will be converted
   *         to JSON and then parsed into this empty proto.
   */
  virtual ProtobufTypes::MessagePtr createEmptyConfigProto() PURE;

  /**
   * @return std::string the identifying name for a particular wasm VM produced by the factory.
   */
  virtual std::string name() PURE;
};

} // namespace Configuration
} // namespace Server
} // namespace Envoy
