// #include <complex>
#include <cstdlib>
#include <iostream>
// #include <vector>

// template <typename T, typename U> auto max(T a, U b) { return a > b ? a : b; }
auto max(auto a, auto b) { return a > b ? a : b; }

// template <typename T>
// inline T max(T x, T y) {
//   return x > y ? x.value : y.value;
// }

int main(int argc, char *argv[]) {
  std::cout << "The maximum of 3 and 5 is " << max(3, 5) << '\n';
  std::cout << "The maximum of 3l and 5l is " << max(3l, 5l) << '\n';
  std::cout << "The maximum of 3.0 and 5.0 is " << max(3.0, 5.0) << '\n';

  unsigned u1 = 2, u2 = 8;

  std::cout << "The maximum of u1 and u2 is " << max(u1, u2) << '\n';
  std::cout << "The maximum of u1*u2 and u1+u2 is " << max(u1 * u2, u1 + u2)
            << '\n';

  std::cout << max<float>(8.1, 9.3) << '\n';

  // std::complex<float> z(3, 2), c(4, 8);
  // std::cout << "The maximum of c and z is " << ::max(c, z) << '\n';

  // std::vector<std::complex<float>> v;
  // std::sort(v.begin(), v.end());

  unsigned u3 = 2;
  int i = 3;

  std::cout << "The maximum of u3 and i is " << max(int(u3), i) << '\n';
  std::cout << "The maximum of u3 and i is " << max<int>(u3, i) << '\n';

  return EXIT_SUCCESS;
}
