#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <cassert>

class matrix_type {
public:
  matrix_type(int nrows, int ncols) : nrows{nrows}, ncols{ncols} {
    for (int i = 0; i < nrows; i++)
      for (int j = 0; j < ncols; j++)
        data[i][j] = 0.0;
  }

  double &operator[](int index) const {
    assert(index < nrows);
    return *data[index];
  }

  ~matrix_type() {
    for (int i = 0; i < nrows; i++)
      delete[] data[i];
    delete[] data;
  }

private:
  int nrows, ncols;
  double **data;
};
#endif // MATRIX_TYPE_H
