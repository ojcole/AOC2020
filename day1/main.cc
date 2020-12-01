#include <algorithm>
#include <iostream>
#include <vector>

#include "parts.h"

int main() {
  std::vector<long> items;

  long inp;

  while (std::cin >> inp) {
    items.push_back(inp);
  }

  std::sort(items.begin(), items.end());

  std::cout << part1(items) << std::endl;
  std::cout << part2(items) << std::endl;
}
