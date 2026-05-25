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

  rational r4{2};
  std::cout << "r4 = " << r4 << std::endl;

  rational r5{57970, 10353};
  std::cout << "r5 = " << r5 << std::endl;

  rational r6{30, 21};
  std::cout << "r6 = " << r6 << std::endl;

  rational r7{-30, 21};
  std::cout << "r7 = " << r7 << std::endl;

  rational r8{30, -21};
  std::cout << "r8 = " << r8 << std::endl;

  rational r9{-30, -21};
  std::cout << "r9 = " << r9 << std::endl;

  std::cout << "r5 * r6 = " << r5 * r6 << std::endl;
  std::cout << "r5 / r6 = " << r5 / r6 << std::endl;

  r5 += r6;
  std::cout << "After r5 += r6, r5 = " << r5 << std::endl;

  r1 -= r2;
  std::cout << "After r1 -= r2, r1 =  " << r1 << std::endl;

  r3 *= r4;
  std::cout << "After r3 *= r4, r3 = " << r3 << std::endl;

  r8 /= r2;
  std::cout << "After r8 /= r2, r8 = " << r8 << std::endl;

  return EXIT_SUCCESS;
}
