#include "envoy/config/wasm/v2/wasm.pb.validate.h"
#include "envoy/registry/registry.h"

#include "server/wasm_config_impl.h"

#include "extensions/wasm/config.h"

#include "test/mocks/event/mocks.h"

#include "gtest/gtest.h"

namespace Envoy {
namespace Extensions {
namespace Wasm {

TEST(FixedHeapMonitorFactoryTest, CreateMonitor) {
  auto factory =
      Registry::FactoryRegistry<Server::Configuration::WasmFactory>::getFactory("envoy.wasm");
  EXPECT_NE(factory, nullptr);

  envoy::config::wasm::v2::WasmConfig config;
  Event::MockDispatcher dispatcher;
  Server::Configuration::WasmFactoryContextImpl context(dispatcher);
  auto wasm = factory->createWasm(config, context);
  EXPECT_EQ(wasm, nullptr);
}

} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
