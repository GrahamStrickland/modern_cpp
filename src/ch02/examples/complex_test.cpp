#include <iostream>

#include "complex.h"

int main(int argc, char *argv[]) {
  complex z, c;
  z.r = 3.5; z.i = 2;
  c.r = 2; c.i = -3.5;
  std::cout << "z is (" << z.r << ", " << z.i << ")\n";

  complex *p = &c;

  // *p.r = 3.5;
  // (*p).r = 3.5;
  p->r = 3.5;
  std::cout << "*p is (" << p->r << ", " << p->i << ")\n";

  complex c1, c2;
  // set c1
  c1.set_r(3.0);
  c1.set_i(2.0);
  std::cout << "c1 is (" << c1.get_r() << ", " << c1.get_i() << ")\n";

  // copy c1 to c2
  c2.set_r(c1.get_r());
  c2.set_i(c1.get_i());
  std::cout << "c2 is (" << c2.get_r() << ", " << c2.get_i() << ")\n";

  return EXIT_SUCCESS;
}
