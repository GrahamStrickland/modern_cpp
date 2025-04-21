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

  rational r4(1, 0);
  std::cout << "r4.get_value() = " << r4.get_value() << '\n'; 

  return EXIT_SUCCESS;
}
