#include "polynomial.h"

#include <algorithm>
#include <ostream>

polynomial::polynomial(std::vector<double> src)
    : coeffs{src}, degree{src.size() - 1} {};

polynomial::polynomial(std::initializer_list<double> src)
    : coeffs{std::vector<double>()}, degree{src.size() - 1} {
  coeffs.reserve(src.size());
  for (auto coeff : src)
    coeffs.emplace_back(coeff);
};

polynomial::polynomial(polynomial &&p) noexcept
    : coeffs{std::move(p.coeffs)}, degree{p.degree} {
  p.degree = 0;
};

polynomial &polynomial::operator=(const std::vector<double> src) {
  assert(degree == src.size() - 1);

  for (std::size_t i = 0; i < src.size(); i++)
    coeffs[i] = src[i];

  return *this;
}

polynomial &polynomial::operator=(std::initializer_list<double> src) {
  assert(degree == src.size() - 1);

  std::size_t i = 0;
  for (auto coeff : src) {
    coeffs[i] = coeff;
    i++;
  }

  return *this;
}

polynomial &polynomial::operator=(polynomial &&p) noexcept {
  assert(degree == p.degree);
  std::swap(coeffs, p.coeffs);
  std::swap(degree, p.degree);
  return *this;
}

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

std::size_t polynomial::get_degree() const { return degree; }

double polynomial::get_coeff(std::size_t index) const {
  assert(index <= degree);
  return coeffs[index];
}

polynomial::~polynomial() {}
