#include "complex.h"

std::ostream &operator<<(std::ostream &os, const complex &c) {
  return os << '(' << real(c) << ',' << imag(c) << ')';
}
