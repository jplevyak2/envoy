#include "test/test_common/environment.h"

#include "envoy/config/wasm/v2/wasm.pb.validate.h"
#include "envoy/registry/registry.h"

#include "server/wasm_config_impl.h"

#include "extensions/wasm/config.h"

#include "test/mocks/event/mocks.h"

#include "gtest/gtest.h"

#include <stdio.h>

namespace Envoy {
namespace Extensions {
namespace Wasm {

TEST(WasmFactoryTest, CreateWasm) {
  auto factory =
      Registry::FactoryRegistry<Server::Configuration::WasmFactory>::getFactory("envoy.wasm");
  EXPECT_NE(factory, nullptr);
  envoy::config::wasm::v2::WasmConfig config;
  config.set_wasm_vm("envoy.wasm_vm.wavm");
  config.set_wasm_file(Envoy::TestEnvironment::getCheckedEnvVar("TEST_SRCDIR") +
      "/envoy/test/extensions/wasm/envoy_wasm_test.wasm");
  Event::MockDispatcher dispatcher;
  Server::Configuration::WasmFactoryContextImpl context(dispatcher);
  auto wasm = factory->createWasm(config, context);
  EXPECT_NE(wasm, nullptr);
}

} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
