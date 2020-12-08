#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

pair<long, bool> Part1(vector<pair<string, int>> &program) {
  unordered_set<int> items;

  long pc{};
  long acc{};

  while (pc < program.size()) {
    if (items.find(pc) != items.end()) {
      return {acc, false};
    }

    items.insert(pc);

    auto &instruction = program[pc];

    if (instruction.first == "acc") {
      acc += instruction.second;
      pc++;
    } else if (instruction.first == "jmp") {
      pc += instruction.second;
    } else if (instruction.first == "nop") {
      pc++;
    }
  }

  return {acc, true};
}

void Part2(vector<pair<string, int>> program) {
  for (auto &p : program) {
    pair<long, bool> res;
    if (p.first == "jmp") {
      p.first = "nop";
      res = Part1(program);
      p.first = "jmp";
    } else if (p.first == "nop") {
      p.first = "jmp";
      res = Part1(program);
      p.first = "nop";
    }

    if (res.second) {
      cout << res.first << endl;
      break;
    }
  }
}

int main() {
  vector<pair<string, int>> program;
  string inp;
  int num;

  while (cin >> inp >> num) {
    program.push_back({inp, num});
  }

  auto res = Part1(program);
  cout << res.first << endl;
  Part2(program);
}
