#ifndef VECTOR_COMPLEX_H
#define VECTOR_COMPLEX_H

#include "complex.h"
#include "vector.h"

class vector_complex : public vector {
public:
  explicit vector_complex(int size)
      : my_size{size}, complex_data{new complex[size]} {}

private:
  complex *complex_data;
};
#endif // VECTOR_COMPLEX_H
