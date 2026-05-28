#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <vector>

class polynomial {
public:
  polynomial(std::vector<double> coeffs);
  polynomial(std::initializer_list<double> coeffs);
  polynomial(polynomial &p) = default;
  polynomial(polynomial &&p) noexcept;

  polynomial &operator=(const std::vector<double> src);
  polynomial &operator=(std::initializer_list<double> coeffs);
  polynomial &operator=(const polynomial &p);
  polynomial &operator=(polynomial &&p) noexcept;

  friend std::ostream &operator<<(std::ostream &os, const polynomial &p);

  std::size_t get_degree() const;

  double get_coeff(std::size_t index) const;

  ~polynomial();

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

inline polynomial operator-(const polynomial &p1, const polynomial &p2) {
  auto new_degree = std::max(p1.get_degree(), p2.get_degree());
  std::vector<double> coeffs;
  coeffs.reserve(new_degree);

  for (std::size_t i = 0; i <= new_degree; i++) {
    if (i <= p1.get_degree() && i <= p2.get_degree()) {
      coeffs.emplace_back(p1.get_coeff(i) - p2.get_coeff(i));
    } else if (i <= p1.get_degree()) {
      coeffs.emplace_back(p1.get_coeff(i));
    } else {
      coeffs.emplace_back(-p2.get_coeff(i));
    }
  }

  return polynomial(coeffs);
}

inline polynomial operator-(const polynomial &p) {
  auto new_degree = p.get_degree();
  std::vector<double> coeffs;
  coeffs.reserve(new_degree);

  for (std::size_t i = 0; i <= new_degree; i++) {
    coeffs.emplace_back(-p.get_coeff(i));
  }

  return polynomial(coeffs);
}

inline polynomial operator*(const polynomial &p, double c) {
  std::vector<double> coeffs;
  coeffs.reserve(p.get_degree());

  for (std::size_t i = 0; i <= p.get_degree(); i++) {
    coeffs.emplace_back(p.get_coeff(i) * c);
  }

  return polynomial(coeffs);
}

inline polynomial operator*(double c, const polynomial &p) {
  return operator*(p, c);
}

inline polynomial operator*(const polynomial &p1, const polynomial &p2) {
  auto new_degree = p1.get_degree() * p2.get_degree() + 1;
  std::vector<double> coeffs;
  coeffs.reserve(new_degree);

  for (std::size_t i = 0; i <= new_degree; i++) {
    coeffs.emplace_back(0.0);
  }

  for (std::size_t i = 0; i <= p1.get_degree(); i++) {
    for (std::size_t j = 0; j <= p2.get_degree(); j++) {
      coeffs[i + j] += p1.get_coeff(i) * p2.get_coeff(j);
    }
  }

  return polynomial(coeffs);
}
#endif // POLYNOMIAL_H
