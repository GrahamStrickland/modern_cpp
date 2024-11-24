#include <iostream>

double meter2km(double meters) {
  return meters / 1000.0;
}

double usgallons2liter(double gallons) {
  return gallons * 3.785411784;
}

int main(int argc, char *argv[]) {
  double meters = 314.5;

  std::cout << "meter2km(" << meters << "m) = " << meter2km(meters) << "km\n";

  double gallons = 12;

  std::cout << "usgallons2liter(" << gallons << "gal) = " << usgallons2liter(gallons) << "l\n";

  return EXIT_SUCCESS;
}
