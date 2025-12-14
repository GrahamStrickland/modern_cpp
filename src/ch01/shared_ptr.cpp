#include <cstdlib>
#include <iostream>
#include <memory>

std::shared_ptr<double> f() {
  std::shared_ptr<double> p1{new double};
  std::shared_ptr<double> p2{new double}, p3 = p1;
  std::cout << "p3.use_count() = " << p3.use_count() << std::endl;
  return p3;
}

int main(int argc, char *argv[]) {
  std::shared_ptr<double> p = f();
  std::cout << "p.use_count() = " << p.use_count() << std::endl;

  /*std::shared_ptr<double>*/ auto p1 = std::make_shared<double>();
  std::cout << "p1.use_count() = " << p1.use_count() << std::endl;

  return EXIT_SUCCESS;
}
