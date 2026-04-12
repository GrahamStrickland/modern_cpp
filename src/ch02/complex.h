#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
public:
  friend std::ostream &operator<<(std::ostream &, const complex &);
  friend class complex_algebra;

  // complex(const complex &) = delete;
  // complex &operator=(const complex &) = default;
  complex(double r, double i) : r{r}, i{i} {}
  complex(double r) : r{r} {}
  complex() {}

  double get_r() { return r; }
  double &real() { return r; }
  friend const double &real(const complex &);

  double get_i() { return i; }
  double &imag() { return i; }
  friend const double &imag(const complex &);

  void set_r(double newr) { r = newr; }
  void set_i(double newi) { i = newi; }

  complex &operator=(const complex &src) {
    r = src.r;
    i = src.i;
    return *this;
  }

  complex &operator=(double nr) {
    r = nr;
    i = 0.0;
    return *this;
  }

  // complex operator+(const complex &c2) const {
  //   return complex(r + c2.r, i + c2.i);
  // }

  // complex operator+(double r2) const { return complex(r + r2, i); }

  complex operator-() const { return complex(-r, -i); }

  static complex subtract(const complex &c1, const complex &c2) {
    return {c1.r - c2.r, c1.i - c2.i};
  }

  ~complex() {
    // std::cout << "So long and thanks for all the fish.\n";
  }

private:
  double r = 0.0, i = 0.0;
};

// double inline real(complex c) { return c.get_r(); }

// double inline imag(complex c) { return c.get_i(); }

double inline complex_abs(complex c) {
  return std::sqrt(real(c) * real(c) + imag(c) * imag(c));
}

inline double &real(complex &c) { return c.real(); }
inline const double &real(const complex &c) { return c.r; }

inline double &imag(complex &c) { return c.imag(); }
inline const double &imag(const complex &c) { return c.i; }

inline complex operator+(const complex &c1, double d) {
  return complex(real(c1) + d, imag(c1));
}

inline complex operator+(double d, const complex &c2) {
  return complex(d + real(c2), imag(c2));
}

inline complex operator+(const complex &c1, const complex &c2) {
  return complex(real(c1) + real(c2), imag(c1) + imag(c2));
}

// inline complex operator-(const complex &c1) {
//   return complex(-real(c1), -imag(c1));
// }

#endif // COMPLEX_H
