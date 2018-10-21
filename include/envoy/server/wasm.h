#pragma once

#include <memory>

#include "envoy/common/exception.h"
#include "envoy/common/pure.h"
#include "envoy/event/dispatcher.h"

namespace Envoy {
namespace Server {

class Wasm {
public:
  virtual ~Wasm() {}

  virtual void initialize(const std::string& file) PURE;
  virtual void configure(const std::string& configuration) PURE;
  virtual void start(Event::Dispatcher& dispatcher) PURE;
  virtual void tick() PURE;
};

typedef std::unique_ptr<Wasm> WasmPtr;

} // namespace Server
} // namespace Envoy
