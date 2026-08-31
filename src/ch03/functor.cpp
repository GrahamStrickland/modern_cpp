#include <cmath>
#include <cstdlib>
#include <iostream>

double fin_diff(double f(double), double x, double h) {
  return (f(x + h) - f(x)) / h;
}

double sin_plus_cos(double x) { return sin(x) + cos(x); }

struct sc_f {
  double operator()(double x) const { return sin(x) + cos(x); }
};

class psc_f {
public:
  psc_f(double alpha) : alpha{alpha} {}

  double operator()(double x) const { return sin(alpha * x) + cos(x); }

private:
  double alpha;
};

int main() {
  std::cout << fin_diff(sin_plus_cos, 1., 0.001) << '\n';
  std::cout << fin_diff(sin_plus_cos, 0., 0.001) << '\n';

  return EXIT_SUCCESS;
}
