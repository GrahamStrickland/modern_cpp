#include <cstdlib>
#include <iostream>

template <typename Value>
constexpr Value pi{3.141'592'653'589'793'238'462'643'383'279l};

template<class T>
T circular_area(const T &r) {
  return pi<T> * r * r;
}

int main() {
  double r = 2.0;

  std::cout << "circular_area(" << r << ") = " << circular_area(r) << '\n';

  return EXIT_SUCCESS;
}
