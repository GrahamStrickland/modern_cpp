#include "value.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  value v{1.0}, v2{2.0}, v3{-1.0};

  std::cout << "v <=> v2: " << (v <=> v2) << std::endl;
  std::cout << "v <=> v3: " << (v <=> v3) << std::endl;
  std::cout << "v2 <=> v3: " << (v2 <=> v3) << std::endl;
  std::cout << "v2 <=> v: " << (v2 <=> v) << std::endl;
  std::cout << "v3 <=> v: " << (v3 <=> v) << std::endl;
  std::cout << "v3 <=> v2: " << (v3 <=> v2) << std::endl;

  return EXIT_SUCCESS;
}
