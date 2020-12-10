#include <benchmark/benchmark.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "parts.h"

using namespace std;

void BM_Part1(benchmark::State &state) {
  for (auto _ : state) {
    ifstream file("day9/input.txt", ifstream::in);
    Part1(file);
    file.close();
  }
}

void BM_Part2(benchmark::State &state) {
  for (auto _ : state) {
    ifstream file("day9/input.txt", ifstream::in);
    Part2(file);
    file.close();
  }
}

void BM_Reading(benchmark::State &state) {
  for (auto _ : state) {
    long inp;
    ifstream file("day9/input.txt", ifstream::in);
    while (file >> inp)
      ;
    file.close();
  }
}

BENCHMARK(BM_Part1)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_Part2)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_Reading)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
