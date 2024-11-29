#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
public:
  friend std::ostream& operator<<(std::ostream&, const complex&);
  friend class complex_algebra;

  double get_r() { return r; }
  void set_r(double newr) { r = newr; }
  double get_i() { return i; }
  void set_i(double newi) { i = newi; }

  double r, i;
};
#endif // COMPLEX_H
