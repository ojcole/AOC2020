#include "parts.h"

#include <iostream>
#include <list>
#include <set>

using namespace std;

long Part1(istream &strm) {
  long inp;
  list<long> prevs;
  multiset<long> prev_set;

  for (int i{}; i < 25; i++) {
    strm >> inp;
    prevs.push_back(inp);
    prev_set.insert(inp);
  }

  while (strm >> inp) {
    auto begin = prev_set.begin();
    auto end = prev_set.end();

    end--;

    bool found = false;

    while (begin != end) {
      auto res = *begin + *end;
      if (res == inp) {
        found = true;
        break;
      } else if (res > inp) {
        end--;
      } else if (res < inp) {
        begin++;
      }
    }

    if (!found) {
      return inp;
    }

    auto front = prevs.front();
    prevs.pop_front();

    auto it = prev_set.find(front);
    if (it != prev_set.end()) {
      prev_set.erase(it);
    }

    prevs.push_back(inp);
    prev_set.insert(inp);
  }

  return -1;
}

long Part2(istream &strm) {
  long num{1930745883};

  long inp;

  list<long> window{};
  long window_total{};

  while (strm >> inp) {
    window.push_back(inp);
    window_total += inp;

    while (window_total > num) {
      auto front = window.front();
      window_total -= front;

      window.pop_front();
    }

    if (window_total == num) {
      break;
    }
  }

  return *min_element(window.begin(), window.end()) +
         *max_element(window.begin(), window.end());
}
