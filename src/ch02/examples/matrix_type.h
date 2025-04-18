#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <cassert>
#include <iostream>

class matrix_type {
public:
  matrix_type(int nrows, int ncols) : nrows{nrows}, ncols{ncols} {
    for (int row = 0; row < nrows; row++)
      for (int col = 0; col < ncols; col++)
        data[row + col] = 0.0;
  }

  double &operator()(int row, int col) const {
    assert(row < nrows && col < ncols);
    return data[row + col];
  }
  matrix_type &
  operator=(std::initializer_list<std::initializer_list<double>> values) {
    assert(nrows * ncols == values.size());
    int i = 0;

    for (const auto &row : values) {
      int j = 0;

      for (const auto &element : row) {
        data[i + j] = element;
        ++j;
      }
      ++i;
      ncols = j;
    }
    nrows = i;

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &out, const matrix_type &m);

  ~matrix_type() { delete[] data; }

private:
  int nrows, ncols;
  double *data;
};

inline std::ostream &operator<<(std::ostream &out, const matrix_type &m) {
  out << '[';

  for (int row = 0; row < m.nrows; row++) {
    if (row == 0)
      out << '[';
    for (int col = 0; col < m.ncols; col++)
      out << m.data[row + col] << (col < m.ncols - 1 ? ", " : "]")
          << (row < m.nrows - 1 ? "\n" : "");
  }

  return out << ']';
}
#endif // MATRIX_TYPE_H
