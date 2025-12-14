#ifndef LENGTH_H
#define LENGTH_H

#include <ostream>

class length {
public:
  explicit length(double l) : l{l} {}

  friend length operator+(length len1, length len2) {
    return length{len1.l + len2.l};
  }

  friend length operator*(double scalar, length len) {
    return length{scalar * len.l};
  }

  friend std::ostream &operator<<(std::ostream &os, length len) {
    os << len.l / 1000.0 << "km";
    return os;
  }

  double get_value() const { return l; }

private:
  double l;
};

length operator"" _m(long double l);
length operator"" _m(unsigned long long l);
length operator"" _km(long double l);
length operator"" _km(unsigned long long l);
length operator"" _nm(long double l);
length operator"" _nm(unsigned long long l);
length operator"" _miles(long double l);
length operator"" _miles(unsigned long long l);

#endif // LENGTH_H
