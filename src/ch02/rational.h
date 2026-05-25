#ifndef RATIONAL_H
#define RATIONAL_H

#include <compare>
#include <ostream>

struct zero_denominator {};

class rational {
public:
  rational(int a, int b);
  rational(int a);

  bool operator==(const rational &r2) const;

  std::weak_ordering operator<=>(const rational &r2) const;

  rational operator+(rational right);
  rational operator-(rational right);
  rational operator*(rational right);
  rational operator/(rational right);

  void operator+=(rational right);
  void operator-=(rational right);
  void operator*=(rational right);
  void operator/=(rational right);

  double get_value();
  int denominator();

  friend std::ostream &operator<<(std::ostream &os, const rational &r);

private:
  void normalize(int a, int b);

  static_assert(sizeof(long long) > sizeof(unsigned),
                "Correct comparison not guaranteed.");
  static long long ll(unsigned x) { return static_cast<long long>(x); }

  int p;
  int q;
};
#endif // RATIONAL_H
