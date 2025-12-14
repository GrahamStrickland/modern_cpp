#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
  double pi = std::numbers::pi;
  int old_precision = std::cout.precision();

  std::cout << "pi is " << pi << '\n';
  std::cout << "pi is " << std::setprecision(16) << pi << '\n';

  std::cout << "pi is " << std::setw(30) << pi << '\n';

  std::cout << "pi is " << std::setfill('-') << std::left << std::setw(30) << pi
            << '\n';

  std::cout.setf(std::ios_base::showpos);
  std::cout << "pi is " << std::scientific << pi << '\n';

  std::cout << std::noshowpos << "63 octal is " << std::oct << 63 << ".\n";
  std::cout << "63 hexadecimal is " << std::hex << 63 << ".\n";
  std::cout << "63 decimal is " << std::dec << 63 << ".\n";

  std::cout << "pi < 3 is " << (pi < 3) << '\n';
  std::cout << "pi < 3 is " << std::boolalpha << (pi < 3) << '\n';

  std::cout.unsetf(std::ios_base::adjustfield | std::ios_base::basefield |
                   std::ios_base::floatfield | std::ios_base::showpos |
                   std::ios_base::boolalpha);
  std::cout.precision(old_precision);

  return EXIT_SUCCESS;
}
