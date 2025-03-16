#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

class matrix_type {
public:
  matrix_type(int nrows, int ncols) : nrows{nrows}, ncols{ncols} {
    for (int i = 0; i < nrows; i++)
      for (int j = 0; j < ncols; j++)
        data[i][j] = 0;
  }

private:
  int nrows, ncols;
  int **data;
};
#endif // MATRIX_TYPE_H
