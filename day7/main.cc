#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using Trans = unordered_map<string, vector<pair<int, string>>>;

void Part1(Trans &transformer) {
  unordered_map<string, bool> can_contain;

  for (const auto &item : transformer) {
    can_contain[item.first] = false;
  }

  for (size_t i{}; i < transformer.size(); i++) {
    for (const auto &item : transformer) {
      if (can_contain[item.first]) continue;
      auto &items = item.second;

      for (auto x : items) {
        if (can_contain[x.second] || x.second == "shiny gold") {
          can_contain[item.first] = true;
          break;
        }
      }
    }
  }

  int count{};

  for (const auto &item : transformer) {
    if (can_contain[item.first]) count++;
  }

  cout << count << endl;
}

long Part2(Trans &transformer, string bag) {
  auto &items = transformer[bag];

  if (items.size() == 0) return 0;

  long total{};

  for (const auto &item : items) {
    total += item.first * (1 + Part2(transformer, item.second));
  }

  return total;
}

vector<pair<int, string>> GetItems(istringstream &stream) {
  vector<pair<int, string>> items;

  int num;

  while (stream >> num) {
    string color, desc, ign;

    stream >> desc >> color >> ign;

    items.push_back({num, desc + " " + color});
  }

  return items;
}

int main() {
  string line;

  Trans transformer;

  while (getline(cin, line)) {
    istringstream stream(line);

    string desc, color, ig;

    stream >> desc >> color >> ig >> ig;

    auto items = GetItems(stream);
    transformer[desc + " " + color] = items;
  }

  cout << Part2(transformer, "shiny gold") << endl;
}
