#include <cassert>
#include <cstdlib>

const double EPS = 1E-4;

double meter2km(double meters) { return meters / 1000.0; }

double usgallons2liter(double gallons) { return gallons * 3.785411784; }

int main(int argc, char *argv[]) {
  double m = 314.5;

  assert(abs(meter2km(m) - 0.3145) <= EPS);

  double gal = 12;

  assert(abs(usgallons2liter(gal) - 45.4249) <= EPS);

  return EXIT_SUCCESS;
}
