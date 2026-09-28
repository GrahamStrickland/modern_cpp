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

template <typename F, typename T>
T inline fin_diff(F f, const T &x, const T &h) {
  return (f(x + h) - f(x)) / h;
}

template <typename F, typename T> class derivative {
public:
  derivative(const F &f, const T &h) : f{f}, h{h} {}

  T operator()(const T &x) const { return (f(x + h) - f(x)) / h; }

private:
  const F &f;
  T h;
};

template <typename F, typename T> class second_derivative {
public:
  second_derivative(const F &f, const T &h) : h{h}, fp{f, h} {}

  T operator()(const T &x) const { return (fp(x + h) - fp(x)) / h; }

private:
  T h;
  derivative<F, T> fp;
};

int main() {
  std::cout << fin_diff(sin_plus_cos, 1., 0.001) << '\n';
  std::cout << fin_diff(sin_plus_cos, 0., 0.001) << '\n';

  psc_f psc_o{1.0};
  std::cout << fin_diff(psc_o, 1., 0.001) << std::endl;
  std::cout << fin_diff(psc_f{2.0}, 1., 0.001) << std::endl;
  std::cout << fin_diff(sin_plus_cos, 0., 0.001) << std::endl;

  using d_psc_f = derivative<psc_f, double>;

  // psc_f psc_o{1.0};
  d_psc_f d_psc_o{psc_o, 0.001};

  std::cout << "der. of sin(x) + cos(x) at 0 is " << d_psc_o(0.0) << '\n';

  using dd_psc_f = derivative<d_psc_f, double>;

  dd_psc_f dd_psc_o{d_psc_o, 0.001};
  std::cout << "2nd der. of sin(x) + cos(x) at 0 is " << dd_psc_o(0.0) << '\n';

  second_derivative<psc_f, double> dd_psc_2_o{psc_f(1.0), 0.001};
  std::cout << "2nd der. of sin(x) + cos(x) at 0 is " << dd_psc_2_o(0.0)
            << '\n';

  return EXIT_SUCCESS;
}