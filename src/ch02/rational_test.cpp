#include <cstdlib>
#include <iostream>

#include "rational.h"

int main(int argc, char *argv[]) {
  rational r1(1, 2), r2(2, 3);

  std::cout << "r1.get_value() = " << r1.get_value() << '\n'
            << "r2.get_value() = " << r2.get_value() << '\n'
            << "r1 + r2 = " << (r1 + r2).get_value() << '\n'
            << "r1 - r2 = " << (r1 - r2).get_value() << '\n';

  rational r3(-4, -5);
  std::cout << "r3.get_value() = " << r3.get_value() << '\n';

  // rational r4(1, 0);
  // std::cout << "r4.get_value() = " << r4.get_value() << '\n';

  rational half{1, 2}, third{1, 3};

  std::cout << "half == third: " << std::boolalpha << (half == third)
            << std::endl;
  std::cout << "half != third: " << std::boolalpha << (half != third)
            << std::endl;

  rational half1{1, 2}, half2{2, 4};

  std::cout << "half1 == half2: " << std::boolalpha << (half1 == half2)
            << std::endl;
  std::cout << "half1.denominator() == half2.denominator(): "
            << (half1.denominator() == half2.denominator()) << std::endl;

  return EXIT_SUCCESS;
}
