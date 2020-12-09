load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "lib",
    srcs = ["parts.cc"],
    hdrs = ["parts.h"],
    data = ["input.txt"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "day9",
    srcs = ["main.cc"],
    copts = ["-O3"],
    data = ["input.txt"],
    deps = ["//day9:lib"],
)

cc_binary(
    name = "bench",
    srcs = ["benchmark.cc"],
    copts = ["-O3"],
    data = ["input.txt"],
    deps = [
        "//day9:lib",
        "@bench//:benchmark",
    ],
)
