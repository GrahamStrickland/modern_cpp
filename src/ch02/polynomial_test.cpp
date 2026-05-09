#include "polynomial.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  polynomial p1{1}, p2{3, {1.0, 2.0, 3.0, 4.0}}, p3{{1.0, 0.0, 2.0}},
      p4{{-1.2, 3.4, 0.0, -5.6}}, p5{p4};

  std::cout << "p1(x) = " << p1 << '\n'
            << "p2(x) = " << p2 << '\n'
            << "p3(x) = " << p3 << '\n'
            << "p4(x) = " << p4 << '\n'
            << "p5(x) = " << p5 << '\n';

  p1 = {1.0, 1.0, 1.0};
  std::cout << "p1(x) = " << p1 << '\n';

  std::cout << "p1(x) + p2(x) = (" << p1 << ") + (" << p2 << ") = " << p1 + p2
            << '\n';
  std::cout << "p4(x) + p2(x) = (" << p4 << ") + (" << p2 << ") = " << p4 + p2
            << '\n';

  return EXIT_SUCCESS;
}
