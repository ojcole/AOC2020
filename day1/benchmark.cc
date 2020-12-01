#include <benchmark/benchmark.h>

#include <iostream>
#include <vector>

#include "parts.h"

static void BM_Part1(benchmark::State &state) {
  std::vector<long> items;

  long inp;

  while (std::cin >> inp) {
    items.push_back(inp);
  }

  for (auto _ : state) {
    part1(items);
  }
}

static void BM_Part2(benchmark::State &state) {
  std::vector<long> items;

  long inp;

  while (std::cin >> inp) {
    items.push_back(inp);
  }

  for (auto _ : state) {
    part2(items);
  }
}

BENCHMARK(BM_Part1)->Iterations(10000000);
// BENCHMARK(BM_Part2)->Iterations(10000000);

BENCHMARK_MAIN();
