#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

template <typename T> std::string to_string(const T &value) {
  std::stringstream sstream;
  sstream << value;
  return sstream.str();
}

int main() {
  std::cout << to_string(1) << '\n'
            << to_string(1.234f) << '\n'
            << to_string('s') << '\n';

  return EXIT_SUCCESS;
}
