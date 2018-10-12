#pragma once

#include <memory>

#include "envoy/common/exception.h"
#include "envoy/common/pure.h"

namespace Envoy {
namespace Server {

/*
 * Implemented by WASM VMs for all use case.
 */
class Wasm {
public:
  virtual ~Wasm() {}

  /**
   * Initialize.
   */
  virtual void initialize() PURE;
};

typedef std::unique_ptr<Wasm> WasmPtr;

} // namespace Server
} // namespace Envoy
