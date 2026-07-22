#include <cstdlib>
#include <iostream>

template <unsigned Order, typename Value> class tensor {};

template <typename Value> using vector = tensor<1, Value>;

template <typename Value> using matrix = tensor<2, Value>;

int main() {
  std::cout << "The type of vector<float> is " << typeid(vector<float>).name()
            << ".\n";
  std::cout << "The type of matrix<float> is " << typeid(matrix<float>).name()
            << ".\n";

  return EXIT_SUCCESS;
}
