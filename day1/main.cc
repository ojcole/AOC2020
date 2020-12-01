#include <iostream>
#include <vector>

#include "parts.h"

int main() {
  std::vector<long> items;

  long inp;

  while (std::cin >> inp) {
    items.push_back(inp);
  }

  std::cout << part1(items) << std::endl;
  std::cout << part2(items) << std::endl;
}
