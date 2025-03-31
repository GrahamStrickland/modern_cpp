#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <cassert>
#include <initializer_list>

class vector {
public:
  explicit vector(int size) : my_size{size}, data{new double[size]} {}
  vector(const vector &v) : my_size{v.my_size}, data{new double[my_size]} {
    for (unsigned i = 0; i < my_size; i++)
      data[i] = v.data[i];
  }
  vector(std::initializer_list<double> values)
      : my_size{static_cast<int>(values.size())}, data{new double[my_size]} {
    std::copy(begin(values), end(values), data);
  }

  double &operator[](int index) const { return data[index]; }
  vector &operator=(const vector &src) {
    if (this == &src)
      return *this;
    assert(my_size == src.my_size);
    for (int i = 0; i < my_size; ++i)
      data[i] = src.data[i];
    return *this;
  }
  vector &operator=(std::initializer_list<double> values) {
    assert(my_size == values.size());
    std::copy(begin(values), end(values), data);
    return *this;
  }

  friend double dot(const vector &, const vector &);

  ~vector() { delete[] data; }

private:
  int my_size;
  double *data;
};

inline double dot(const vector &v, const vector &w) {
  assert(v.my_size == w.my_size);
  double result = 0.0;

  for (int i = 0; i < v.my_size; i++) {
    result += v[i] * w[i];
  }

  return result;
}
#endif // VECTOR_H
