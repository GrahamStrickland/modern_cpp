#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <cassert>
#include <iostream>
#include <memory>

class matrix_type {
public:
  matrix_type(int nrows, int ncols)
      : nrows{nrows}, ncols{ncols}, data{new double[nrows * ncols]} {
    for (int row = 0; row < nrows; row++)
      for (int col = 0; col < ncols; col++)
        data[row * nrows + col] = 0.0;
  }

  double &operator()(int row, int col) const {
    assert(row < nrows && col < ncols);
    return data[row * nrows + col];
  }

  matrix_type &
  operator=(std::initializer_list<std::initializer_list<double>> values) {
    assert(static_cast<unsigned int>(nrows) == values.size());
    int i = 0;

    for (const auto &row : values) {
      assert(static_cast<unsigned int>(ncols) == row.size());
      int j = 0;

      for (const auto &element : row) {
        data[i * nrows + j] = element;
        j++;
      }
      i++;
      ncols = j;
    }
    nrows = i;

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &out, const matrix_type &m);

  ~matrix_type() {}

private:
  int nrows, ncols;
  std::unique_ptr<double[]> data;
};

inline std::ostream &operator<<(std::ostream &out, const matrix_type &m) {
  out << "\n[";

  for (int row = 0; row < m.nrows; row++) {
    out << (row == 0 ? "" : " ") << '[';
    for (int col = 0; col < m.ncols; col++)
      out << m.data[row * m.nrows + col] << (col < m.ncols - 1 ? ", " : "]");
    out << (row < m.nrows - 1 ? ",\n" : "");
  }

  return out << ']';
}
#endif // MATRIX_TYPE_H
