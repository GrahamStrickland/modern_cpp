#ifndef VALUE_H
#define VALUE_H

#include <compare>

class value {
public:
  explicit value(double x) : x{x} {}
  auto operator<=>(const value &v2) const = default;

private:
  double x;
};
#endif // VALUE_H
