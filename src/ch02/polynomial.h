#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <cassert>
#include <cmath>
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
    for (std::size_t i = 0; i < coeffs.size(); i++)
      coeffs[i] = src[i];

    return *this;
  }
  polynomial &operator=(polynomial &&p) noexcept {
    assert(degree == p.degree);
    std::swap(coeffs, p.coeffs);
    std::swap(degree, p.degree);
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const polynomial &p);

  std::size_t get_degree() const { return degree; }

  double get_coeff(std::size_t index) const {
    assert(index <= degree);
    return coeffs[index];
  }

  ~polynomial() {}

private:
  std::vector<double> coeffs;
  std::size_t degree;
};

inline polynomial operator+(const polynomial &p1, const polynomial &p2) {
  auto new_degree = std::max(p1.get_degree(), p2.get_degree());
  std::vector<double> coeffs;
  coeffs.reserve(new_degree);

  for (std::size_t i = 0; i <= new_degree; i++) {
    if (i <= p1.get_degree() && i <= p2.get_degree()) {
      coeffs.emplace_back(p1.get_coeff(i) + p2.get_coeff(i));
    } else if (i <= p1.get_degree()) {
      coeffs.emplace_back(p1.get_coeff(i));
    } else {
      coeffs.emplace_back(p2.get_coeff(i));
    }
  }

  return polynomial(coeffs);
}
#endif // POLYNOMIAL_H
