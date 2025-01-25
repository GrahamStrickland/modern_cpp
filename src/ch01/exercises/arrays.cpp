#include <iostream>

int main(int argc, char *argv[]) {
  int a[] = {1, 2, 3, 4, 5};

  std::cout << "a = [ ";
  for (int i = 0; i < 5; i++)
    std::cout << a[i] << (i < 4 ? ", " : " ]\n");

  int *b = new int[5];

  for (int i = 0; i < 5; i++)
    b[i] = 2 * i;

  std::cout << "b = [ ";
  for (int i = 0; i < 5; i++)
    std::cout << b[i] << (i < 4 ? ", " : " ]\n");

  delete[] b;

  return EXIT_SUCCESS;
}
