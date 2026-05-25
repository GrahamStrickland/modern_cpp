#include <cassert>

#include "rational.h"

rational::rational(int a, int b) { normalize(a, b); }

rational::rational(int a) : p{a}, q{1} {}

bool rational::operator==(const rational &r2) const {
  return p * ll(r2.q) == r2.p * ll(q);
}

std::weak_ordering rational::operator<=>(const rational &r2) const {
  return p * ll(r2.q) <=> r2.p * ll(q);
}

rational rational::operator+(rational right) {
  return rational(p * right.q + right.p * q, q * right.q);
}

rational rational::operator-(rational right) {
  return rational(p * right.q - right.p * q, q * right.q);
}

rational rational::operator*(rational right) {
  return rational(p * right.p, q * right.q);
}

rational rational::operator/(rational right) {
  return rational(p * right.q, q * right.p);
}

void rational::operator+=(rational right) {
  int a = p * right.q + right.p * q, b = q * right.q;
  normalize(a, b);
}

void rational::operator-=(rational right) {
  int a = p * right.q - right.p * q, b = q * right.q;
  normalize(a, b);
}

void rational::operator*=(rational right) {
  int a = p * right.p, b = q * right.q;
  normalize(a, b);
}

void rational::operator/=(rational right) {
  int a = p * right.q, b = q * right.p;
  normalize(a, b);
}

double rational::get_value() {
  return static_cast<double>(p) / static_cast<double>(q);
}

int rational::denominator() { return q; }

std::ostream &operator<<(std::ostream &os, const rational &r) {
  os << r.p << "/" << r.q;

  return os;
}

/* @brief: Compute the greatest common denominator of a and b using Euclid's
 * algorithm.
 * @param: `int` a is a positive integer.
 * @param: `int` b is a positive integer.
 */
int euclid(int a, int b) {
  if (b == 0)
    return a;
  return euclid(b, a % b);
}

void rational::normalize(int a, int b) {
  if (b == 0)
    throw zero_denominator{};

  if (a == 0) {
    a = 0;
    b = 1;
    return;
  }

  auto gcd = euclid(abs(a), abs(b));
  p = (a / gcd) * (b < 0 ? -1 : 1);
  q = abs(b) / gcd;
}
