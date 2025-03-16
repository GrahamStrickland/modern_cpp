#include <iostream>

#include "complex.h"

int main(int argc, char *argv[]) {
  // complex z, c;
  // z.r = 3.5;
  // z.i = 2;
  // c.r = 2;
  // c.i = -3.5;
  // std::cout << "z is (" << z.r << ", " << z.i << ")\n";

  // complex *p = &c;

  // *p.r = 3.5;
  // (*p).r = 3.5;
  // p->r = 3.5;
  // std::cout << "*p is (" << p->r << ", " << p->i << ")\n";

  complex c1(2.0, 3.0);
  complex c2{2.0};
  complex c3;

  // set c1
  c1.set_r(3.0);
  c1.set_i(2.0);
  std::cout << "c1 is (" << c1.get_r() << ", " << c1.get_i() << ")\n";

  // copy c1 to c2
  c2.set_r(c1.get_r());
  c2.set_i(c1.get_i());
  std::cout << "c2 is (" << c2.get_r() << ", " << c2.get_i() << ")\n";

  // test operator<< implementation
  std::cout << "c1 = " << c1 << "\nc2 = " << c2 << "\nc3 = " << c3 << '\n';

  complex z1, z2{}, z3{4}, z4 = 4, z5{0, 1};

  std::cout << "z1 = " << z1 << "\nz2 = " << z2 << "\nz3 = " << z3
            << "\nz4 = " << z4 << "\nz5 = " << z5 << '\n';

  return EXIT_SUCCESS;
}
