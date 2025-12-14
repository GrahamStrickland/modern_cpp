#include <cstdlib>
#include <iostream>

#include <fmt/core.h>
#include <fmt/ostream.h>

int main(int argc, char *argv[]) {
  fmt::print("Decimal:\t{} {} {:06} {} {:0} {:+} {:d}\n", 1, 2, 3, 0, 0, 4, -1);
  fmt::print("Hexadecimal:\t{:x} {:x} {:X} {:#x}\n", 5, 10, 10, 6);
  fmt::print("Octal:\t\t{:o} {:#o}\n", 10, 10, 4);
  fmt::print("Binary:\t\t{:b} {:#b} {:#b}\n\n", 10, 10, 4);

  fmt::print("Default:\t{} {:g} {:g}\n", 1.5, 1.5, 1e20);
  fmt::print("Rounding:\t{:f} {:.0f} {:.22f}\n", 1.5, 1.5, 1.3);
  fmt::print("Padding:\t{:05.2f} {:.2f} {:5.2f}\n", 1.5, 1.5, 1.5);
  fmt::print("Scientific:\t{:E} {:e}\n", 1.5, 1.5);
  fmt::print("Hexadecimal:\t{:a} {:A}\n\n", 1.5, 1.3);

  fmt::print(std::cerr, "System error code = {}\n", 7);

  std::ofstream error_file("error_file.txt");
  fmt::print(error_file, "System error code = {}\n", 7);

  fmt::print("I'd rather be {1} than {0}.\n", "right", "happy");

  std::string name = "Graham";
  int number = 42;
  fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
             fmt::arg("name", name), fmt::arg("number", number));

  return EXIT_SUCCESS;
}
