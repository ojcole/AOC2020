#include <algorithm>
#include <iostream>
#include <list>
#include <set>

using namespace std;

void Part1() {
  long inp;
  list<long> prevs;
  multiset<long> prev_set;

  for (int i{}; i < 25; i++) {
    cin >> inp;
    prevs.push_back(inp);
    prev_set.insert(inp);
  }

  while (cin >> inp) {
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
      cout << inp << endl;
      return;
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
}

int main() {
  long num{1930745883};

  long inp;

  list<long> window{};
  long window_total{};

  while (cin >> inp) {
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

  cout << *min_element(window.begin(), window.end()) +
              *max_element(window.begin(), window.end())
       << endl;
}
