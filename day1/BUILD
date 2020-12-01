load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "lib",
    srcs = ["parts.cc"],
    hdrs = ["parts.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "day1",
    srcs = ["main.cc"],
    copts = ["-O3"],
    deps = ["//day1:lib"],
)

cc_binary(
    name = "bench",
    srcs = ["benchmark.cc"],
    copts = ["-O3"],
    deps = [
        "//day1:lib",
        "@bench//:benchmark",
    ],
)
