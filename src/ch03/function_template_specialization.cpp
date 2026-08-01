#include <cmath>
#include <cstdlib>
#include <iostream>

template <typename Base, typename Exponent>
Base inline power(const Base &x, const Exponent &y) {
  Base res = 1, base = x;
  Exponent exp = y;

  while (exp > 0) {
    if (exp & 1) {
      res = res * base;
    }
    base = base * base;
    exp >>= 1;
  }
  return res;
}

template <typename Base> Base inline power(const Base &x, int y) {
  Base res = 1, base = x;

  while (y > 0) {
    if (y & 1) {
      res = res * base;
    }
    base = base * base;
    y >>= 1;
  }
  return res;
}

template <typename Exponent> double inline power(double x, const Exponent &y) {
  double res = 1;
  Exponent exp = y;

  while (exp > 0) {
    if (exp & 1) {
      res = res * x;
    }
    x = x * x;
    exp >>= 1;
  }
  return res;
}

double inline power(double x, double y) { return std::pow(x, y); }
double inline power(double x, int y) { return std::pow(x, y); }

int main() {
  std::cout << power(3.0, 2u) << '\n';
  std::cout << power(3.0, 2) << '\n';

  return EXIT_SUCCESS;
}
