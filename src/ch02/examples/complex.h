#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
public:
  friend std::ostream &operator<<(std::ostream &, const complex &);
  friend class complex_algebra;

  complex(double r, double i) : r{r}, i{i} {}
  complex(double r) : r{r} {}
  complex() {}

  double get_r() { return r; }
  void set_r(double newr) { r = newr; }
  double get_i() { return i; }
  void set_i(double newi) { i = newi; }

private:
  double r = 0.0, i = 0.0;
};

double inline real(complex c) { return c.get_r(); }

double inline imag(complex c) { return c.get_i(); }

double inline complex_abs(complex c) {
  return std::sqrt(real(c) * real(c) + imag(c) * imag(c));
}
#endif // COMPLEX_H
