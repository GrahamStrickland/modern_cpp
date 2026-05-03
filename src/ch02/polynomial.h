#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <cassert>
#include <vector>

class polynomial {
public:
  polynomial(std::size_t degree) : degree{degree} {
    coeffs = std::vector<double>();
    for (int i = 0; i <= degree; i++)
      coeffs.push_back(0.0);
  };
  polynomial(std::size_t degree, std::vector<double> coeffs)
      : coeffs{coeffs}, degree{degree} {
    assert(degree == coeffs.size() - 1);
  };
  polynomial(std::vector<double> coeffs)
      : coeffs{coeffs}, degree{coeffs.size() - 1} {};
  polynomial(polynomial &p) : coeffs{p.coeffs}, degree{p.degree} {};
  polynomial(polynomial &&p) noexcept
      : coeffs{std::move(p.coeffs)}, degree{p.degree} {
    p.degree = 0;
  };

  polynomial &operator=(const std::vector<double> src) {
    assert(degree == coeffs.size() - 1);

    coeffs.reserve(src.size());
    for (std::size_t i = 0; i <= coeffs.size(); i++)
      coeffs[i] = src[i];

    return *this;
  }
  polynomial &operator=(polynomial &&p) noexcept {
    assert(degree == p.degree);
    std::swap(coeffs, p.coeffs);
    std::swap(degree, p.degree);
    return *this;
  }

  ~polynomial() {}

  friend std::ostream &operator<<(std::ostream &os, const polynomial &p);

private:
  std::vector<double> coeffs;
  std::size_t degree;
};
#endif // POLYNOMIAL_H
