#ifndef RATIONAL_H
#define RATIONAL_H

#include <cassert>

struct zero_denominator {};

class rational {
public:
  rational(int p, int q) : p{p}, q{q} {
    if (q == 0)
      throw zero_denominator{};
  }

  bool operator==(const rational &r2) const {
    return p * ll(r2.q) == r2.p * ll(q);
  }

  rational operator+(rational right) {
    return rational(p * right.q + right.p * q, q * right.q);
  }
  rational operator-(rational right) {
    return rational(p * right.q - right.p * q, q * right.q);
  }

  double get_value() { return static_cast<double>(p) / static_cast<double>(q); }

private:
  static_assert(sizeof(long long) > sizeof(unsigned),
                "Correct comparison not guaranteed.");
  static long long ll(unsigned x) { return static_cast<long long>(x); }
  int p;
  int q;
};
#endif // RATIONAL_H
