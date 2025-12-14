#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  const unsigned c1{4000000000};
  const long c2{40000000000}, c3{400000000000}, c4{4000000000000000000};

  std::cout << "c1 = " << c1 << '\n'
            << "c2 = " << c2 << '\n'
            << "c3 = " << c3 << '\n'
            << "c4 = " << c4 << '\n';

  const int n1{-400000000}, n2{-999999999};
  const long n3{-9999999999999999999};
  const long n4{-8446744073709551617};

  std::cout << "n1 = " << n1 << '\n'
            << "n2 = " << n2 << '\n'
            << "n3 = " << n3 << '\n'
            << "n4 = " << n4 << '\n';

  return EXIT_SUCCESS;
}
