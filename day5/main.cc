#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void Part1() {
  string line;

  long m{-1};

  while (getline(cin, line)) {
    istringstream stream(line);

    int row_top = 127;
    int row_bot = 0;
    int col_top = 7;
    int col_bot = 0;

    char ch;

    while (stream >> ch) {
      int row_tot = row_top + row_bot;
      int col_tot = col_top + col_bot;
      if (ch == 'F') {
        row_top = row_tot / 2;
      } else if (ch == 'B') {
        row_bot = row_tot / 2 + 1;
      } else if (ch == 'L') {
        col_top = col_tot / 2;
      } else if (ch == 'R') {
        col_bot = col_tot / 2 + 1;
      }
    }

    long id = row_top * 8 + col_top;

    m = max(id, m);
  }

  cout << m << endl;
}

void Part2() {
  string line;

  vector<long> ids;

  while (getline(cin, line)) {
    istringstream stream(line);

    int row_top = 127;
    int row_bot = 0;
    int col_top = 7;
    int col_bot = 0;

    char ch;

    while (stream >> ch) {
      int row_tot = row_top + row_bot;
      int col_tot = col_top + col_bot;
      if (ch == 'F') {
        row_top = row_tot / 2;
      } else if (ch == 'B') {
        row_bot = row_tot / 2 + 1;
      } else if (ch == 'L') {
        col_top = col_tot / 2;
      } else if (ch == 'R') {
        col_bot = col_tot / 2 + 1;
      }
    }

    long id = row_top * 8 + col_top;

    ids.push_back(id);
  }

  sort(ids.begin(), ids.end());

  for (size_t i{1}; i < ids.size(); i++) {
    if (ids[i - 1] + 1 == ids[i]) continue;

    cout << ids[i - 1] + 1 << endl;
  }
}

int main() { Part2(); }
