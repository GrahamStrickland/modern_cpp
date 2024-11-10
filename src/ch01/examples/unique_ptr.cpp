#include <iostream>
#include <memory>

std::unique_ptr<double> f() { return std::unique_ptr<double>{new double}; }

int main(int argc, char *argv[]) {
  std::unique_ptr<double> dp{new double};
  *dp = 7;

  std::cout << "The value of *dp is " << *dp << std::endl;

  // double d= 7.2;
  // std::unique_ptr<double> dd{&d}; // Error: causes illegal deletion

  // std::unique_ptr<double> dp2{dp};    // Error: no copy allowed
  // dp2= dp;                            // ditto

  std::unique_ptr<double> dp2{std::move(dp)}, dp3;
  std::cout << "The value of *dp2 is " << *dp2 << std::endl;

  dp3 = std::move(dp2);
  std::cout << "The value of *dp3 is " << *dp3 << std::endl;

  std::unique_ptr<double> dp4;
  dp4 = f();

  std::unique_ptr<double[]> da{new double[3]};
  for (unsigned i = 0; i < 3; ++i)
    da[i] = i + 2;

  for (unsigned i = 0; i < 3; ++i)
    std::cout << da[i] << " ";

  return EXIT_SUCCESS;
}
