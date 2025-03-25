#include <iostream>

#include "vector.h"

int main(int argc, char *argv[]) {
  vector v1(4);
  v1[0] = v1[1] = 1.0;
  v1[2] = 2.0;
  v1[3] = -3.0;

  const vector v2{v1};
  std::cout << "v2[3] is " << v2[3] << '\n';

  v1[3] = 3.14;
  std::cout << "v2[3] is " << v2[3] << '\n';

  return EXIT_SUCCESS;
}
