#pragma once

#include <memory>

#include "envoy/common/exception.h"
#include "envoy/common/pure.h"

namespace Envoy {
namespace Server {

class Wasm {
public:
  virtual ~Wasm() {}

  virtual void initialize(const std::string& file) PURE;
  virtual void configure(const std::string& configuration) PURE;
  virtual void start() PURE;
};

typedef std::unique_ptr<Wasm> WasmPtr;

} // namespace Server
} // namespace Envoy
