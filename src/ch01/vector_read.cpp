#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream ifs("some_array.dat");
  int size;
  ifs >> size;
  float *v = new float[size];
  for (int i = 0; i < size; ++i)
    ifs >> v[i];

  std::cout << '[';
  for (int i = 0; i < size; ++i)
    std::cout << v[i] << (i < size - 1 ? ", " : "]");
  std::cout << '\n';

  delete[] v;

  return EXIT_SUCCESS;
}
