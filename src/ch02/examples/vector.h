#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

class vector {
public:
  explicit vector(int size) : my_size{size}, data{new double[size]} {}
  vector(const vector &v) : my_size{v.my_size}, data{new double[my_size]} {
    for (unsigned i = 0; i < my_size; i++)
      data[i] = v.data[i];
  }

  double &operator[](int index) const { return data[index]; }

  friend double dot(const vector &, const vector &);

private:
  int my_size;
  std::unique_ptr<double[]> data;
};

inline double dot(const vector &v, const vector &w) {
  double result = 0.0;

  for (int i = 0; i < v.my_size; i++) {
    result += v[i] * w[i];
  }

  return result;
}
#endif // VECTOR_H
