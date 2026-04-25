#ifndef PARTIAL_H
#define PARTIAL_H

#include <compare>

class partial {
public:
  partial(int x, int y) : x{x}, y{y} {}

  bool operator==(const partial &) const = default;

  std::partial_ordering operator<=>(const partial &p2) const {
    using po = std::partial_ordering;
    if (x < p2.x && y < p2.y)
      return po::less;
    if (x > p2.x && y > p2.y)
      return po::greater;
    if (x == p2.x && y == p2.y)
      return po::equivalent;
    return po::unordered;
  }

private:
  int x, y;
};
#endif // PARTIAL_H
