#include <iostream>

void print_middle(double a, double b, double c) {
  std::cout << (a < b ? (b < c ? b : (a < c ? c : a)) : (a < c ? a : (b < c ? c : b))) << '\n';
}

int main(int argc, char *argv[]) {
  print_middle(1.0, 2.0, 3.0);
  print_middle(2.1, 1.34, 3.56);
  print_middle(3.34, 3.33, 3.32);
  print_middle(-1.0, 2.0, -3.0);
  print_middle(1.0, 0.9, -0.8);
  print_middle(1.0, 200.1234, 14.56);
  print_middle(10.0, 2.0, 0.3);

  return EXIT_SUCCESS;
}
