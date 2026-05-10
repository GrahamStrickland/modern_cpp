#include "polynomial.h"

#include <ostream>

std::ostream &operator<<(std::ostream &os, const polynomial &p) {
  if (p.degree == 0)
    return os;

  bool nonzero = false;
  bool leading_minus = true;

  for (std::size_t i = 0; i <= p.degree; i++) {
    if (p.coeffs[i] != 0.0) {
      nonzero = true;

      if (i == 0) {
        os << p.coeffs[i];
        leading_minus = false;
      } else {
        os << (p.coeffs[i] > 0.0 ? " + " : (leading_minus ? "-" : " - "));

        if (fabs(p.coeffs[i]) != 1.0)
          os << fabs(p.coeffs[i]);

        os << 'x';

        if (i > 1)
          os << '^' << i;

        leading_minus = false;
      }
    }
  }

  if (!nonzero)
    os << '0';

  return os;
}
