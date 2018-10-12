licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)

envoy_package()

envoy_cc_library(
    name = "wasm_lib",
    srcs = ["wasm.cc"],
    hdrs = ["wasm.h"],
    external_deps = [
        "luajit",
    ],
    deps = [
        "//include/envoy/thread_local:thread_local_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:c_smart_ptr_lib",
        "//source/common/protobuf",
    ],
)

envoy_cc_library(
    name = "wrappers_lib",
    srcs = ["wrappers.cc"],
    hdrs = ["wrappers.h"],
    deps = [
        ":wasm_lib",
        "//include/envoy/buffer:buffer_interface",
        "//source/common/protobuf",
    ],
)
