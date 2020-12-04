#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void ParseLine2(string &line, map<string, string> &items) {
  istringstream stream(line);

  string cred;

  while (stream >> cred) {
    auto index = cred.find(':');
    auto key = cred.substr(0, index);
    auto val = cred.substr(index + 1, string::npos);

    if (key == "byr") {
      int x = stoi(val);
      if (x >= 1920 && x <= 2002) {
        items[key] = val;
      }
    } else if (key == "iyr") {
      int x = stoi(val);
      if (x >= 2010 && x <= 2020) {
        items[key] = val;
      }
    } else if (key == "eyr") {
      int x = stoi(val);
      if (x >= 2020 && x <= 2030) {
        items[key] = val;
      }
    } else if (key == "hgt") {
      if (val.size() > 2) {
        auto unit = val.substr(val.size() - 2, 2);
        auto x = stoi(val.substr(0, val.size() - 2));

        if ((unit == "cm" && x >= 150 && x <= 193) ||
            (unit == "in" && x >= 59 && x <= 76)) {
          items[key] = val;
        }
      }
    } else if (key == "hcl") {
      if (val.size() == 7 && val[0] == '#') {
        auto y = true;
        for (auto i{1}; i < 7; i++) {
          if (!((val[i] >= '0' && val[i] <= '9') ||
                (val[i] >= 'a' && val[i] <= 'f'))) {
            y = false;
            break;
          }
        }

        if (y) {
          items[key] = val;
        }
      }
    } else if (key == "ecl") {
      unordered_set<string> clrs{"amb", "blu", "brn", "gry",
                                 "grn", "hzl", "oth"};

      if (clrs.find(val) != clrs.end()) {
        items[key] = val;
      }
    } else if (key == "pid") {
      if (val.size() == 9) {
        bool x = true;
        for (int i{}; i < 9; i++) {
          if (!(val[i] >= '0' && val[i] <= '9')) {
            x = false;
            break;
          }
        }

        if (x) {
          items[key] = val;
        }
      }
    } else {
      items[key] = val;
    }
  }
}

void ParseLine(string &line, map<string, string> &items) {
  istringstream stream(line);

  string cred;

  while (stream >> cred) {
    auto index = cred.find(':');
    auto key = cred.substr(0, index);
    auto val = cred.substr(index + 1, string::npos);

    items[key] = val;
  }
}

int main() {
  string line;
  vector<string> keys{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
  long valid{};

  while (getline(cin, line)) {
    map<string, string> items;

    ParseLine2(line, items);

    while (line.size() != 0 && getline(cin, line)) {
      ParseLine2(line, items);
    }

    bool is_valid = true;

    for (auto key : keys) {
      if (items.find(key) == items.end()) {
        is_valid = false;
        break;
      }
    }

    if (is_valid) {
      valid++;
    }
  }

  cout << valid << endl;
}
