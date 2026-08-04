#include <complex>
#include <cstdlib>
#include <iostream>

namespace dmc {
// template <typename T> inline T abs(const T &x) {
//   std::cout << "T\n";
//   return x < T(0) ? -x : x;
// }

template <typename T> inline T abs(const std::complex<T> &x) {
  // std::cout << "complex<T>\n";
  return sqrt(real(x) * real(x) + imag(x) * imag(x));
}

template <typename T> struct abs_functor {
  // typedef T result_type;
  T operator()(const T &x) {
    // std::cout << "T\n";
    return x < T(0) ? -x : x;
  }
};

template <typename T> struct abs_functor<std::complex<T>> {
  // typedef T result_type;

  T operator()(const std::complex<T> &x) {
    return sqrt(real(x) * real(x) + imag(x) * imag(x));
  }
};

template <typename T> decltype(auto) abs(const T &x) {
  return abs_functor<T>{}(x);
}

// template <typename T>
// auto abs(const T &x) -> decltype(abs_functor<T>{}(x)) {
//   return abs_functor<T>{}(x);
// }

// template <typename T> typename abs_functor<T>::result_type abs(const T &x) {
//   return abs_functor<T>{}(x);
// }
} // end namespace dmc

int main(int argc, char *argv[]) {
  double a = -1.0;
  double *b = &a;
  std::complex<double> z{1.0, 2.0};

  std::cout << "abs(" << a << ") = " << dmc::abs(a) << '\n';
  std::cout << "abs(" << *b << ") = " << dmc::abs(*b) << '\n';
  std::cout << "abs(" << z << ") = " << dmc::abs(z) << '\n';

  return EXIT_SUCCESS;
}
