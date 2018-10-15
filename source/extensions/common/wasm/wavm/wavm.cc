#include "extensions/common/wasm/wavm/wavm.h"

#include "envoy/common/exception.h"

#include "common/common/assert.h"

#include "WAVM/Runtime/Runtime.h"

namespace Envoy {
namespace Extensions {
namespace Common {
namespace Wasm {
namespace Wavm {

Wavm::~Wavm() {
}

void Wavm::initialize(const std::string& ) {
}

void Wavm::configure(const std::string& ) {
}

} // namespace Wavm
} // namespace Wasm
} // namespace Common
} // namespace Extensions
} // namespace Envoy
