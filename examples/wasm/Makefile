
envoy_wasm_test.wasm: envoy_wasm_test.cc envoy_wasm_intrinsics.h envoy_library.js
	em++ --js-library envoy_library.js envoy_wasm_test.cc -s WASM=1 -o envoy_wasm_test.js
