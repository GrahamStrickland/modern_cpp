#include <cstdlib>
#include <iostream>
#include <valarray>

int main(int argc, char *argv[]) {
  std::valarray<float> v = {1, 2, 3}, w = {7, 8, 9}, s = v + 2.0f * w;

  std::cout << "v + 2.0w = [";
  for (int i = 0; i < 3; ++i)
    std::cout << v[i] << (i < 2 ? ", " : "] + []");
  for (int i = 0; i < 3; ++i)
    std::cout << w[i] << (i < 2 ? ", " : "] = [");
  for (int i = 0; i < 3; ++i)
    std::cout << s[i] << (i < 2 ? ", " : "]\n");

  v = sin(s);
  for (float x : v)
    std::cout << x << ' ';
  std::cout << '\n';

  return EXIT_SUCCESS;
}
