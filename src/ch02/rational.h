#ifndef RATIONAL_H
#define RATIONAL_H

#include <cassert>

class rational {
public:
  rational(int p, int q) : p(p) {
    assert(q != 0);
    this->q = q < 0 ? -q : q;
  }

  double get_value() { return static_cast<double>(p) / static_cast<double>(q); }

  rational operator+(rational right) {
    return rational(p * right.q + right.p * q, q * right.q);
  }
  rational operator-(rational right) {
    return rational(p * right.q - right.p * q, q * right.q);
  }

private:
  int p;
  int q;
};
#endif // RATIONAL_H
