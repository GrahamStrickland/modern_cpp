#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  int x = 19;
  while (x != 1) {
    std::cout << x << '\n';
    if (x % 2 == 1) // odd
      x = 3 * x + 1;
    else // even
      x = x / 2;
  }

  return EXIT_SUCCESS;
}
