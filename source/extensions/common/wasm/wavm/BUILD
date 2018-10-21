licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)

envoy_package()

envoy_cc_library(
    name = "wavm_lib",
    srcs = ["wavm.cc"],
    hdrs = ["wavm.h"],
    copts = [
        "-I/usr/local/include",
        '-DPLATFORM_API=""',
        '-DRUNTIME_API=""',
        '-DLOGGING_API=""',
        '-DWASM_API=""',
        '-DWASTPARSE_API=""',
        '-DIR_API=""',
        '-Wno-non-virtual-dtor',
    ],
    deps = [
        "@wavm//:wavm",
        "//include/envoy/server:wasm_interface",
        "//include/envoy/thread_local:thread_local_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:c_smart_ptr_lib",
        "//source/common/protobuf",
        "@envoy_api//envoy/config/wasm/v2:wasm_cc",
    ],
)
