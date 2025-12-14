#include <cstdlib>
#include <iomanip>
#include <iostream>

const double START = 0.0;
const double END = 1.0;
const double EPS = 1e-12;

double find_zero(double a, double b, double prev) {
  double mid = (a + b) / 2.0;
  double res = sin(5.0 * mid) + cos(mid);

  if (abs(res - prev) < EPS)
    return mid;

  if (signbit(res))
    return find_zero(a, mid, res);
  else
    return find_zero(mid, b, res);
}

int main(int args, char *argv[]) {
  std::cout << std::setprecision(11);
  std::cout << find_zero(START, END, END) << '\n';

  return EXIT_SUCCESS;
}
