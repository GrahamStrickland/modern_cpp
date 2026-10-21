#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numbers>

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

template <unsigned N, typename F, typename T> class nth_derivative {
  using prev_derivative = nth_derivative<N - 1, F, T>;

public:
  nth_derivative(const F &f, const T &h) : h{h}, fp{f, h} {}

  T operator()(const T &x) const {
    return N & 1 ? (fp(x + h) - fp(x)) / h : (fp(x) - fp(x - h)) / h;
  }

private:
  T h;
  prev_derivative fp;
};

// template <typename F, typename T> class nth_derivative<1, F, T> {
// public:
//   nth_derivative(const F &f, const T &h) : f{f}, h{h} {}

//   T operator()(const T &x) const { return (f(x + h) - f(x)) / h; }

// private:
//   const F &f;
//   T h;
// };

template <typename F, typename T>
class nth_derivative<1, F, T> : public derivative<F, T> {
  using derivative<F, T>::derivative;
};

template <unsigned N, typename F, typename T>
nth_derivative<N, F, T> derive(const F &f, const T &h) {
  return nth_derivative<N, F, T>{f, h};
}

struct lambda_f {
  lambda_f(double phi, double xi) : phi{phi}, xi{xi} {}
  double operator()(double x) const { return sin(phi * x) + cos(x) * xi; }
  double phi, xi;
};

struct lambda_ref_type {
  lambda_ref_type(double &phi, double &xi) : phi{phi}, xi{xi} {}
  double operator()(double x) const { return sin(phi * x) + cos(x) * xi; }
  double &phi;
  double &xi;
};

template <typename Matrix>
/*typename Matrix::value_type*/ inline auto frobenius_norm(const Matrix &A) {
  using std::abs;
  using std::sqrt;
  // using value_type = typename Matrix::value_type;
  /*value_type*/ decltype(abs(A[0][0])) ss = 0;
  on_each_nonzero(A, [&ss](/*value_type*/ auto x) { ss += abs(x) * abs(x); });
  return sqrt(ss);
}

struct s {
  int f(int x) const { return 2 * x; }
  int g(int y) const {
    auto l = [this](int z) { return f(z + i); };
    return l(y);
  }
  int i = 3;
};

template <typename C> void reverse_sort(C &c) {
  sort(begin(c), end(c), [](auto x, auto y) { return x > y; });
}

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

  nth_derivative<22, psc_f, double> d22_psc_o{psc_f(1.0), 0.00001};

  // nth_derivative<7, psc_f, double> d7_psc_o{psc_o, 0.00001};

  // auto d7_psc_o = nth_derivative<7, psc_f, double>{psc_o, 0.00001};
  // nth_derivative<decltype(psc_o), decltype(0.00001), 7> d7_psc_o{psc_o,
  //                                                                0.00001};

  // auto d7_psc_o = derive<psc_f, double, 7>(psc_o, 0.00001);

  auto d7_psc_o = derive<7>(psc_o, 0.00001);

  std::cout << "7th der. of sin(x) + cos(x) at 0 is " << d7_psc_o(0.0) << '\n';

  std::cout << fin_diff([](double x) { return sin(x) + cos(x); }, 1., 0.001)
            << '\n';

  std::cout << fin_diff([](double x) { return sin(2.5 * x) + cos(x); }, 1.,
                        0.001)
            << '\n';

  auto sc_l = [](double x) { return sin(x) + cos(x); };
  std::cout << sc_l(1.0) << '\n';

  auto sc_l2 = [](double x) -> double { return sin(x) + cos(x); };
  std::cout << sc_l2(1.0) << '\n';

  auto d7_psc_l =
      derive<7>([](double x) { return sin(2.5 * x) + cos(x); }, 0.0001);
  std::cout << "7th der. of sin(2.5x) + cos(x) at pi/2 is "
            << d7_psc_l(std::numbers::pi_v<double> / 2.0) << '\n';

  auto a = fin_diff([](double x) { return sin(2.5 * x); }, 1., 0.001);
  auto b = fin_diff([](double x) { return sin(3.0 * x); }, 1., 0.001);
  auto c = fin_diff([](double x) { return sin(3.5 * x); }, 1., 0.001);
  std::cout << "a = " << a << ", b = " << b << ", c = " << c << '\n';

  double phi = 2.5;
  // auto sin_phi = [](double x) { return sin(phi * x); };
  auto sin_phi = [phi](double x) { return sin(phi * x); };
  std::cout << "sin(" << phi << "x) at 1.0 is " << sin_phi(1.0) << '\n';

  double /*phi = 2.5,*/ xi = 0.2;
  auto sin2 = [phi, xi](double x) { return sin(phi * x) + cos(x) * xi; };
  std::cout << "sin(" << phi << "x) + " << xi << "cos(x) at 1.0 is "
            << sin2(1.0) << '\n';

  lambda_f sin3{phi, xi};
  std::cout << "sin(" << phi << "x) + " << xi << "cos(x) at 1.0 is "
            << sin3(1.0) << '\n';

  // double phi = 2.5, xi = 0.2;
  auto px = [phi, xi](double x) { return sin(phi * x) + cos(x) * xi; };
  phi = 3.5;
  xi = 1.2;
  a = fin_diff(px, 1., 0.001); // still uses phi = 2.5 and xi = 0.2
  std::cout << "a = " << a << '\n';

  // auto l_inc = [phi](double x) { phi += 0.6; return phi; }; // Error
  auto l_mut = [phi](double x) mutable {
    phi += 0.6;
    return phi;
  };

  std::cout << "phi = " << l_mut(1.0) << '\n';

  /*double*/ phi = 2.5;
  xi = 0.2;
  auto pxr = [&phi, &xi](double x) { return sin(phi * x) + cos(x) * xi; };
  phi = 3.5;
  xi = 1.2;
  a = fin_diff(pxr, 1., 0.001); // now uses phi = 3.5 and xi = 1.2
  std::cout << "a = " << a << '\n';

  int x = 4;
  auto l = [&r = x, i = x + 1] /*()*/ {
    r += 2;
    return i + 1;
  };
  std::cout << "l() = " << l() << '\n';
  std::cout << "x = " << x << '\n';

  // auto F = make_unique<Mat>(Mat{{1., 0.5}, {0.5, 1. / 3.}});
  // auto apply_f = [F = move(F)](const Vec &x) { return Vec(*F * x); };

  return EXIT_SUCCESS;
}
