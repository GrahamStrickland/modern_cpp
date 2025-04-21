#include "matrix_type.h"
#include "vector.h"

#include <cmath>
#include <iostream>
#include <memory>
#include <stdexcept>

void lu_dcmp(matrix_type &A, int n, std::shared_ptr<int[]> indx);
vector lu_solve(matrix_type &A, vector &u);

int main() {
  matrix_type A(3, 3);
  A = {{1.0, 2.0, -3.0}, {2.0, -1.0, 4.0}, {1.0, -1.0, 1.0}};
  vector u{6.0, 1.0, 3.0};

  std::cout << "u = " << u << ",\nA = " << A << '\n';
  vector x = lu_solve(A, u);
  std::cout << "Solution = " << x << '\n';

  return EXIT_SUCCESS;
}

void lu_dcmp(matrix_type &A, int n, std::shared_ptr<int[]> indx) {
  int imax;
  double big, dum, sum, temp;
  vector vv{1.0, 1.0, 1.0};

  for (int i = 0; i < n; i++) {
    big = 0.0;
    for (int j = 0; j < n; j++)
      if ((temp = fabs(A(i, j))) > big)
        big = temp;

    if (big == 0.0)
      throw std::runtime_error("Singular matrix in routine lu_solve");

    vv[i] = 1.0 / big;
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < j; i++) {
      sum = A(i, j);
      for (int k = 0; k < i; k++)
        sum -= A(i, j) * A(k, j);
      A(i, j) = sum;
    }

    big = 0.0;
    for (int i = j; i < n; i++) {
      sum = A(i, j);
      for (int k = 0; k < j; k++)
        sum -= A(i, j) * A(k, j);
      A(i, j) = sum;

      if ((dum = vv[i] * fabs(sum)) >= big) {
        big = dum;
        imax = i;
      }
    }

    if (j != imax) {
      for (int k = 0; k < n; k++) {
        sum = A(imax, k);
        A(imax, k) = A(j, k);
        A(j, k) = dum;
      }
      vv[imax] = vv[j];
    }
    indx[j] = imax;

    if (A(j, j) == 0.0)
      A(j, j) = 1.0e-20;

    if (j != n) {
      dum = 1.0 / A(j, j);
      for (int i = j; i < n; i++)
        A(i, j) *= dum;
    }
  }
}

vector lu_solve(matrix_type &A, vector &u) {
  int ii = 0, ip;
  double sum;
  std::shared_ptr<int[]> indx{new int[3]};
  vector x{0.0, 0.0, 0.0};

  lu_dcmp(A, 3, indx);

  for (int i = 0; i < 3; i++) {
    ip = indx[i];
    sum = u[ip];
    u[ip] = u[i];
    if (ii > 0)
      for (int j = ii; j <= i; j++)
        sum -= A(i, j) * u[j];
    else if (sum > 0)
      ii = i;
    u[i] = sum;
  }

  for (int i = 2; i >= 0; i--) {
    sum = u[i];
    for (int j = i + 1; j < 3; j++)
      sum -= A(i, j) * u[j];
    x[i] = sum / A(i, i);
  }

  return x;
}
