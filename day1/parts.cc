#include "parts.h"

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

long part1(std::vector<long> items) {
  sort(items.begin(), items.end());

  auto begin = items.begin();
  auto end = std::lower_bound(items.begin(), items.end(), 2020 - begin[0]);

  while (begin != end) {
    auto res = *begin + *end;
    if (res == 2020) {
      return *begin * *end;
    }
    if (res > 2020) {
      end--;
    } else {
      begin++;
    }
  }

  return -1;
}

long part2(std::vector<long> items) {
  sort(items.begin(), items.end());

  for (auto it = items.begin(); it != items.end(); it++) {
    auto begin = it + 1;
    auto end = std::lower_bound(begin, items.end(), 2020 - (*it + it[1]));

    while (begin != end) {
      auto res = *begin + *end + *it;
      if (res == 2020) {
        return *begin * *end * *it;
      }
      if (res > 2020) {
        end--;
      } else {
        begin--;
      }
    }
  }

  return -1;
}
