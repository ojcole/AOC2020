#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void Part1(vector<vector<int>> input) {
  bool change = true;

  while (change) {
    change = false;
    vector<vector<int>> new_input(input);

    for (size_t i{}; i < input.size(); i++) {
      for (size_t j{}; j < input[i].size(); j++) {
        int adjacent{};

        if (i != 0 && input[i - 1][j] == 2) {
          adjacent++;
        }
        if (i != input.size() - 1 && input[i + 1][j] == 2) {
          adjacent++;
        }
        if (i != input.size() - 1 && j != 0 && input[i + 1][j - 1] == 2) {
          adjacent++;
        }
        if (i != 0 && j != 0 && input[i - 1][j - 1] == 2) {
          adjacent++;
        }
        if (i != input.size() - 1 && j != input[i].size() - 1 &&
            input[i + 1][j + 1] == 2) {
          adjacent++;
        }
        if (i != 0 && j != input[i].size() - 1 && input[i - 1][j + 1] == 2) {
          adjacent++;
        }
        if (j != 0 && input[i][j - 1] == 2) {
          adjacent++;
        }
        if (j != input[i].size() - 1 && input[i][j + 1] == 2) {
          adjacent++;
        }

        if (adjacent == 0 && input[i][j] == 1) {
          new_input[i][j] = 2;
          change = true;
        }
        if (adjacent >= 4 && input[i][j] == 2) {
          new_input[i][j] = 1;
          change = true;
        }
      }
    }

    input = new_input;
  }

  int occupied{};

  for (size_t i{}; i < input.size(); i++) {
    for (size_t j{}; j < input[i].size(); j++) {
      if (input[i][j] == 2) occupied++;
    }
  }

  cout << occupied << endl;
}

pair<int, int> PosPosDiag(vector<vector<int>> &input, size_t i, size_t j) {
  i++;
  j++;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0;
       i++, j++) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}

pair<int, int> PosNegDiag(vector<vector<int>> &input, size_t i, size_t j) {
  i++;
  j--;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0;
       i++, j--) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}

pair<int, int> NegPosDiag(vector<vector<int>> &input, size_t i, size_t j) {
  i--;
  j++;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0;
       i--, j++) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}

pair<int, int> NegNegDiag(vector<vector<int>> &input, size_t i, size_t j) {
  i--;
  j--;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0;
       i--, j--) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}

pair<int, int> PosNeuDiag(vector<vector<int>> &input, size_t i, size_t j) {
  i++;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0; i++) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}

pair<int, int> NegNeuDiag(vector<vector<int>> &input, size_t i, size_t j) {
  i--;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0; i--) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}
pair<int, int> NeuPosDiag(vector<vector<int>> &input, size_t i, size_t j) {
  j++;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0; j++) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}

pair<int, int> NeuNegDiag(vector<vector<int>> &input, size_t i, size_t j) {
  j--;
  for (; i < input.size() && i >= 0 && j < input[i].size() && j >= 0; j--) {
    if (input[i][j] != 0) return {i, j};
  }

  return {-1, -1};
}

void Part2(vector<vector<int>> input) {
  bool change = true;

  vector<vector<set<pair<int, int>>>> locations;

  for (size_t i{}; i < input.size(); i++) {
    vector<set<pair<int, int>>> row;
    for (size_t j{}; j < input[i].size(); j++) {
      set<pair<int, int>> cell;

      auto res1 = NegNegDiag(input, i, j);
      auto res2 = NegNeuDiag(input, i, j);
      auto res3 = NegPosDiag(input, i, j);
      auto res4 = NeuNegDiag(input, i, j);
      auto res5 = NeuPosDiag(input, i, j);
      auto res6 = PosNegDiag(input, i, j);
      auto res7 = PosNeuDiag(input, i, j);
      auto res8 = PosPosDiag(input, i, j);

      vector<pair<int, int>> tmp{res1, res2, res3, res4,
                                 res5, res6, res7, res8};

      for (auto t : tmp) {
        if (t.first != -1 && t.second != -1) {
          cell.insert(t);
        }
      }

      row.push_back(cell);
    }

    locations.push_back(row);
  }

  while (change) {
    change = false;
    vector<vector<int>> new_input(input);

    for (size_t i{}; i < input.size(); i++) {
      for (size_t j{}; j < input[i].size(); j++) {
        int adjacent{};

        // if (input[i][j] == 0) continue;

        for (auto loc : locations[i][j]) {
          if (input[loc.first][loc.second] == 2) {
            adjacent++;
          }
        }

        if (adjacent == 0 && input[i][j] == 1) {
          new_input[i][j] = 2;
          change = true;
        }
        if (adjacent >= 5 && input[i][j] == 2) {
          new_input[i][j] = 1;
          change = true;
        }
      }
    }

    input = new_input;
  }

  int occupied{};

  for (size_t i{}; i < input.size(); i++) {
    for (size_t j{}; j < input[i].size(); j++) {
      if (input[i][j] == 2) occupied++;
    }
  }

  cout << occupied << endl;
}

int main() {
  string inp;
  vector<vector<int>> input;

  while (getline(cin, inp)) {
    vector<int> line;

    istringstream stream(inp);

    char ch;

    while (stream >> ch) {
      if (ch == '.') {
        line.push_back(0);
      } else if (ch == 'L') {
        line.push_back(1);

      } else if (ch == '#') {
        line.push_back(2);
      }
    }

    input.push_back(line);
  }

  Part1(input);
  Part2(input);
}
