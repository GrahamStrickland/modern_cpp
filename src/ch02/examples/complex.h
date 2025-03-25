#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
public:
  friend std::ostream &operator<<(std::ostream &, const complex &);
  friend class complex_algebra;

  explicit complex(double nr = 0.0, double i = 0.0) : r{nr}, i{i} {}
  complex(const complex &c) = default;

  double get_r() { return r; }
  void set_r(double newr) { r = newr; }
  double get_i() { return i; }
  void set_i(double newi) { i = newi; }

private:
  double r, i;
};

double inline real(complex c) { return c.get_r(); }

double inline imag(complex c) { return c.get_i(); }

double inline complex_abs(complex c) {
  return std::sqrt(real(c) * real(c) + imag(c) * imag(c));
}
#endif // COMPLEX_H
