#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename Vector1, typename Vector2>
auto operator+(const Vector1 &v1, const Vector2 &v2)
    -> std::vector<decltype(v1[0] + v2[0])>;

int main(int argc, char *argv[]) {
  auto i = 2 * 7.5, j = std::sqrt(3.7); // okay: both are double
  // auto i = 2 * 4, j = std::sqrt(3.7);                   // Error: i is int, j
  // double auto i = 2 * 4, j;                                    // Error: j
  // not initialized

  std::cout << "i = " << i << '\n';
  std::cout << "j = " << j << '\n';

  auto &ri = i;        // reference on i
  const auto &cri = i; // constant reference on i

  return EXIT_SUCCESS;
}