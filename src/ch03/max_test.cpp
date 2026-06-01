#include <cstdlib>
#include <iostream>

template <typename T> T max(T a, T b) {
  if (a > b)
    return a;
  else
    return b;
}

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

  return EXIT_SUCCESS;
}
