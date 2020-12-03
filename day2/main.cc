#include <iostream>
#include <string>

using namespace std;

bool Part1(string &pass, char ch, int min, int max) {
  int count{};

  for (const auto &c : pass) {
    if (c == ch) {
      count++;
    }
  }

  return count >= min && count <= max;
}

bool Part2(string &pass, char ch, int min, int max) {
  return pass[min - 1] == ch ^ pass[max - 1] == ch;
}

int main() {
  int total{};

  while (true) {
    int min;
    int max;
    char ch, ch1;

    if (!(cin >> min)) {
      break;
    }

    cin >> ch1 >> max >> ch >> ch1;

    string input;

    cin >> input;

    if (Part1(input, ch, min, max)) {
      total++;
    }
  }

  cout << total << endl;
}
