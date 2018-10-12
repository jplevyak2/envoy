#pragma once

#include <memory>
#include <string>
#include <vector>

#include "envoy/common/exception.h"
#include "envoy/server/wasm.h"
#include "envoy/config/wasm/v2/wasm.pb.validate.h"
#include "envoy/thread_local/thread_local.h"

#include "common/common/assert.h"
#include "common/common/c_smart_ptr.h"
#include "common/common/logger.h"

namespace Envoy {
namespace Extensions {
namespace Common {
namespace Wasm {
namespace Wavm {

class Wavm : public Server::Wasm {
 public:
  Wavm(const envoy::config::wasm::v2::WasmConfig&) {}
  ~Wavm() override;

  void initialize() override;

 private:
};


} // namespace Wavm
} // namespace Wasm
} // namespace Common
} // namespace Extensions
} // namespace Envoy
