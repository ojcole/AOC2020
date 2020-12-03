#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int CheckSlope(vector<vector<int>> &grid, int row_cross, int col_cross) {
  int row{};
  int col{};

  int count{};
  int row_size{static_cast<int>(grid.back().size())};

  row += row_cross;
  col += col_cross;
  col %= row_size;

  while (row < grid.size()) {
    if (grid[row][col] == 1) {
      count++;
    }

    row += row_cross;
    col += col_cross;
    col %= row_size;
  }

  return count;
}

int main() {
  string line;

  vector<vector<int>> grid;

  while (getline(cin, line)) {
    istringstream stream(line);
    grid.push_back({});

    char inp;

    while (stream >> inp) {
      if (inp == '.') {
        grid.back().push_back(0);
      } else {
        grid.back().push_back(1);
      }
    }
  }

  long slope_total = CheckSlope(grid, 1, 3);

  cout << slope_total << endl;

  slope_total *= CheckSlope(grid, 1, 1);
  slope_total *= CheckSlope(grid, 1, 5);
  slope_total *= CheckSlope(grid, 1, 7);
  slope_total *= CheckSlope(grid, 2, 1);

  cout << slope_total << endl;
}
