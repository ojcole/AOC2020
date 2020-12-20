#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void Part2(vector<pair<char, int>> &instr) {
  pair<int, int> waypoint{10, 1};
  pair<int, int> loc{0, 0};

  for (auto &entry : instr) {
    if (entry.first == 'N') {
      waypoint.second += entry.second;
    } else if (entry.first == 'S') {
      waypoint.second -= entry.second;
    } else if (entry.first == 'E') {
      waypoint.first += entry.second;
    } else if (entry.first == 'W') {
      waypoint.first -= entry.second;
    } else if (entry.first == 'L') {
      if (entry.second == 180) {
        waypoint.first = -waypoint.first;
        waypoint.second = -waypoint.second;
      }

      if (entry.second == 90) {
        waypoint.second = -waypoint.second;
        swap(waypoint.first, waypoint.second);
      }
    } else if (entry.first == 'R') {
      if (entry.second == 180) {
        waypoint.first = -waypoint.first;
        waypoint.second = -waypoint.second;
      }

      if (entry.second == 90) {
        waypoint.first = -waypoint.first;
        swap(waypoint.first, waypoint.second);
      }
    } else if (entry.first == 'F') {
      loc.first += entry.second * waypoint.first;
      loc.second += entry.second * waypoint.second;
    }

    // cout << loc.first << " " << loc.second << endl;
    cout << waypoint.first << " " << waypoint.second << endl;
  }

  cout << abs(loc.first) + abs(loc.second) << endl;
}

void Part1(vector<pair<char, int>> &instr) {
  int angle{90};
  pair<int, int> loc{0, 0};

  for (auto &entry : instr) {
    if (entry.first == 'N') {
      loc.second += entry.second;
    } else if (entry.first == 'S') {
      loc.second -= entry.second;
    } else if (entry.first == 'E') {
      loc.first += entry.second;
    } else if (entry.first == 'W') {
      loc.first -= entry.second;
    } else if (entry.first == 'L') {
      angle = (angle - entry.second + 360) % 360;
    } else if (entry.first == 'R') {
      angle = (angle + entry.second) % 360;
    } else if (entry.first == 'F') {
      // double rad = angle * M_PI / 180.0;

      if (angle == 90) {
        loc.first += entry.second;
      } else if (angle == 180) {
        loc.second -= entry.second;
      } else if (angle == 270) {
        loc.first -= entry.second;
      } else if (angle == 0) {
        loc.second += entry.second;
      }
    }
  }

  cout << abs(loc.first) + abs(loc.second) << endl;
}

int main() {
  vector<pair<char, int>> instr;

  char ch;
  int inp;

  while (cin >> ch >> inp) {
    if (ch == 'L' && inp == 270) {
      ch = 'R';
      inp = 90;
    }
    if (ch == 'R' && inp == 270) {
      ch = 'L';
      inp = 90;
    }
    instr.push_back({ch, inp});
  }

  Part1(instr);
  Part2(instr);
}
