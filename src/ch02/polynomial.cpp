#include "polynomial.h"

#include <ostream>

polynomial::polynomial(std::size_t degree) : degree{degree} {
  coeffs = std::vector<double>();
  for (int i = 0; i <= degree; i++)
    coeffs.push_back(0.0);
};

polynomial::polynomial(std::size_t degree, std::vector<double> coeffs)
    : coeffs{coeffs}, degree{degree} {
  assert(degree == coeffs.size() - 1);
};

polynomial::polynomial(std::vector<double> coeffs)
    : coeffs{coeffs}, degree{coeffs.size() - 1} {};

polynomial::polynomial(polynomial &&p) noexcept
    : coeffs{std::move(p.coeffs)}, degree{p.degree} {
  p.degree = 0;
};

polynomial &polynomial::operator=(const std::vector<double> src) {
  assert(degree == coeffs.size() - 1);

  coeffs.reserve(src.size());
  for (std::size_t i = 0; i < coeffs.size(); i++)
    coeffs[i] = src[i];

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
