#include "partial.h"
#include <array>
#include <cstdlib>
#include <iostream>

void compare_pairs(partial p1, partial p2);

int main(int argc, char *argv[]) {
  std::array<partial, 5> pairs = {partial{1, 2}, partial{3, 4}, partial{1, 3},
                                  partial{3, 2}, partial{1, 2}};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cout << "pairs[" << i << "] <=> pairs[" << j << "]: ";
      compare_pairs(pairs[i], pairs[j]);
    }
  }

  return EXIT_SUCCESS;
}

void compare_pairs(partial p1, partial p2) {
  if (p1 <=> p2 > 0) {
    std::cout << "greater" << std::endl;
  } else if (p1 <=> p2 < 0) {
    std::cout << "less" << std::endl;
  } else if (p1 <=> p2 == 0) {
    std::cout << "equivalent" << std::endl;
  } else {
    std::cout << "unordered" << std::endl;
  }
}
