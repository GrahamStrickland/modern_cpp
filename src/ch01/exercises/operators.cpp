#include <iostream>
#include <math.h>

double circ_area(double r) { return M_PI * r * r; }

int main(int argc, char *argv[]) {
  double r{2};

  std::cout << "Circumference of a circle of radius " << r << ": "
            << circ_area(r) << '\n';

  return EXIT_SUCCESS;
}
