#include "complex.h"

std::ostream &operator<<(std::ostream &outs, const complex &c) {
  outs << c.r << " + " << c.i << "i";
  return outs;
}

