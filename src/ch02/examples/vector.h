#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

class vector {
public:
  vector(int size) : my_size{size}, data{new double[size]} {}
  vector(const vector &v) : my_size{v.my_size}, data{new double[my_size]} {
    for (unsigned i = 0; i < my_size; i++)
      data[i] = v.data[i];
  }

  double &operator[](int index) const { return data[index]; }

private:
  int my_size;
  std::unique_ptr<double[]> data;
};
#endif // VECTOR_H
