#include "extensions/common/wasm/wasm.h"

#include "extensions/common/wasm/wasm.h"

#include "absl/types/optional.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace Envoy {
namespace Extensions {
namespace Wasm {

TEST(WasmTest, ComputesCorrectUsage) {
  Server::WasmPtr wasm(Common::Wasm::createWasmVm("test/extensions/wasm/test.wasm"));
  EXPECT_EQ(wasm, nullptr);
}

} // namespace Wasm
} // namespace Extensions
} // namespace Envoy
