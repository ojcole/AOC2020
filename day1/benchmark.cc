#include <benchmark/benchmark.h>

#include <iostream>
#include <vector>

#include "parts.h"

static void BM_Part1(benchmark::State &state) {
  static std::vector<long> items;
  static bool callSetup = true;
  if (callSetup) {
    long inp;

    while (std::cin >> inp) {
      items.push_back(inp);
    }
  }
  callSetup = false;

  for (auto _ : state) {
    part1(items);
  }
}

static void BM_Part2(benchmark::State &state) {
  static std::vector<long> items;
  static bool callSetup = true;
  if (callSetup) {
    long inp;

    while (std::cin >> inp) {
      items.push_back(inp);
    }
  }
  callSetup = false;

  for (auto _ : state) {
    part2(items);
  }
}

// BENCHMARK(BM_Part1)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_Part2)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
