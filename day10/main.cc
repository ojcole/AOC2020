#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Part1(vector<long> &nums) {
  long ones{};
  long threes{};

  for (size_t i{1}; i < nums.size(); i++) {
    size_t diff = nums[i] - nums[i - 1];
    if (diff == 1) {
      ones++;
    } else if (diff == 3) {
      threes++;
    }
  }

  threes++;

  cout << ones * threes << endl;
}

void Part2(vector<long> &nums) {
  long total{};

  vector<long> arrangements;
  arrangements.push_back(1);

  for (size_t i{1}; i < nums.size(); i++) {
    long tot{};
    for (size_t j{i - 1}; j + 1 > 0; j--) {
      if (nums[i] - nums[j] <= 3) {
        tot += arrangements[j];
      }
    }

    arrangements.push_back(tot);
  }

  cout << arrangements.back() << endl;
}

int main() {
  long inp;
  vector<long> nums;
  nums.push_back(0);

  while (cin >> inp) {
    nums.push_back(inp);
  }

  sort(nums.begin(), nums.end());

  Part1(nums);
  Part2(nums);
}
