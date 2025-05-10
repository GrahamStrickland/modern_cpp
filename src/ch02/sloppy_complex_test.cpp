#include <cstdlib>

struct sloppy_complex {
  double r, i;
};

int main() {
  sloppy_complex z1{.r = 3.66, .i = 2.33}, z2 = {.i = 1};
  sloppy_complex z3{.i = 4.4, .r = 0.9};

  return EXIT_SUCCESS;
}
