#include <fstream>
#include <iostream>

#include "parts.h"

int main() {
  std::ifstream file("day9/input.txt", std::ifstream::in);
  std::cout << Part1(file) << std::endl;
  file.close();
  file.open("day9/input.txt");
  std::cout << Part2(file) << std::endl;
  file.close();
}
