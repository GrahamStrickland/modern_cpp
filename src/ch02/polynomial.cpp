#include "polynomial.h"

#include <ostream>

std::ostream &operator<<(std::ostream &os, const polynomial &p) {
  if (p.degree == 0)
    return os;

  bool nonzero = false;

  for (std::size_t i = 0; i <= p.degree; i++) {
    if (p.coeffs[i] != 0.0) {
      nonzero = true;

      if (i == 0)
        os << p.coeffs[i];
      else {
        os << (p.coeffs[i] > 0.0 ? " + " : " - ");

        if (p.coeffs[i] != 1.0)
          os << fabs(p.coeffs[i]);

        os << 'x';

        if (i > 1)
          os << '^' << i;
      }
    }
  }

  if (!nonzero)
    os << '0';

  return os;
}
