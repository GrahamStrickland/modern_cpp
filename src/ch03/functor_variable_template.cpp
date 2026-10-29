#include <cmath>
#include <cstdlib>
#include <iostream>

// template <size_t N>
// auto derive = [](auto f, auto x, auto h) {
//   auto prev = [&](auto x2) { return derive<N - 1>(f, x2, h); };
//   return (prev(x + h) - prev(x)) / h;
// };

// template <> auto derive<0> = [](auto f, auto x, auto h) { return f(x); };

// template <size_t N>
// auto derive = [](auto f, auto h) {
//   auto prev = derive<N - 1>(f, h);
//   return [prev, h](auto x) { return (prev(x + h) - prev(x)) / h; };
// };

// template <>
// auto derive<0> = [](auto f, auto h) { return [f](auto x) { return f(x); }; };

template <size_t N>
auto derive = [](auto f, auto h) {
  if constexpr (N == 0) {
    return [f](auto x) { return f(x); };
  } else {
    auto prev = derive<N - 1>(f, h);
    return [=](auto x) { return (prev(x + h) - prev(x)) / h; };
  }
};

int main() {
  auto f = [](double x) { return 2.0 * std::cos(x) + x * x; };

  // std::cout << "f''(1) = " << derive<2>(f, 1.0, 1e-3) << std::endl;
  // std::cout << "f(5)(1) = " << derive<5>(f, 1.0, 1e-3) << std::endl;

  auto d2f = derive<2>(f, 1e-3);
  auto d5f = derive<5>(f, 1e-3);

  std::cout << "f''(1) = " << d2f(1.0) << std::endl;
  std::cout << "f(5)(1) = " << d5f(1.0) << std::endl;

  return EXIT_SUCCESS;
}
