#include <iostream>

int main(int argc, char *argv[]) {
  auto c1{4000000000u};
  auto c2{40000000000l}, c3{400000000000l}, c4{4000000000000000000l};

  std::cout << "c1 = " << c1 << '\n'
            << "c2 = " << c2 << '\n'
            << "c3 = " << c3 << '\n'
            << "c4 = " << c4 << '\n';

  auto n1{-400000000l}, n2{-999999999u};
  auto n3{-9999999999999999999l};
  auto n4{-8446744073709551617l};

  std::cout << "n1 = " << n1 << '\n'
            << "n2 = " << n2 << '\n'
            << "n3 = " << n3 << '\n'
            << "n4 = " << n4 << '\n';

  return EXIT_SUCCESS;
}
