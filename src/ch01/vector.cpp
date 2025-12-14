#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  // std::vector<float> v(3), w(3);
  // v[0]= 1; v[1]= 2; v[2]= 3;
  // w[0]= 7; w[1]= 8; w[2]= 9;
  std::vector<float> v = {1, 2, 3}, w = {7, 8, 9};

  std::cout << "v = [";
  for (int i = 0; i < 3; ++i)
    std::cout << v[i] << (i < 2 ? ", " : "]");
  std::cout << '\n';

  std::cout << "w = [";
  for (int i = 0; i < 3; ++i)
    std::cout << w[i] << (i < 2 ? ", " : "]");
  std::cout << '\n';

  return EXIT_SUCCESS;
}
