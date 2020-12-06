#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Part1() {
  string inp;

  long count;

  while (getline(cin, inp)) {
    unordered_set<char> items;

    do {
      for (char ch : inp) {
        items.insert(ch);
      }

      getline(cin, inp);
    } while (inp != "");

    count += items.size();
  }

  cout << count << endl;
}

void Part2() {
  string inp;

  long count;

  while (getline(cin, inp)) {
    unordered_map<char, int> items;
    int tot{};

    do {
      tot++;
      for (char ch : inp) {
        items[ch]++;
      }

      getline(cin, inp);
    } while (inp != "");

    for (const auto &pair : items) {
      if (pair.second == tot) count++;
    }
  }

  cout << count << endl;
}

int main() { Part2(); }
