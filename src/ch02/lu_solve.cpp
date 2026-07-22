#include "matrix_type.h"
#include "vector.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>

void lu_dcmp(matrix_type &A, int n, std::shared_ptr<int[]> indx);
vector lu_solve(const matrix_type &A, const vector &u);

int main() {
  matrix_type A(3, 3);
  A = {{1.0, 2.0, -3.0}, {2.0, -1.0, 4.0}, {1.0, -1.0, 1.0}};
  vector u{6.0, 1.0, 3.0};

  std::cout << "u = " << u << ",\nA = " << A << '\n';
  vector x = lu_solve(A, u);
  std::cout << "Solution = " << x << '\n';

  return EXIT_SUCCESS;
}

// Crout's algorithm with implicit partial pivoting: A is overwritten in place
// with its LU decomposition, indx records the row permutation.
void lu_dcmp(matrix_type &A, int n, std::shared_ptr<int[]> indx) {
  int imax = 0;
  double big, dum, sum, temp;
  vector vv(static_cast<unsigned>(n)); // implicit scaling of each row

  for (int i = 0; i < n; i++) {
    big = 0.0;
    for (int j = 0; j < n; j++)
      if ((temp = fabs(A(i, j))) > big)
        big = temp;

    if (big == 0.0)
      throw std::runtime_error("Singular matrix in routine lu_dcmp");

    vv[i] = 1.0 / big;
  }

  for (int j = 0; j < n; j++) {
    // Upper triangle: elements above the diagonal (i < j).
    for (int i = 0; i < j; i++) {
      sum = A(i, j);
      for (int k = 0; k < i; k++)
        sum -= A(i, k) * A(k, j);
      A(i, j) = sum;
    }

    // Lower triangle and diagonal, tracking the best pivot.
    big = 0.0;
    for (int i = j; i < n; i++) {
      sum = A(i, j);
      for (int k = 0; k < j; k++)
        sum -= A(i, k) * A(k, j);
      A(i, j) = sum;

      if ((dum = vv[i] * fabs(sum)) >= big) {
        big = dum;
        imax = i;
      }
    }

    if (j != imax) {
      for (int k = 0; k < n; k++) {
        temp = A(imax, k);
        A(imax, k) = A(j, k);
        A(j, k) = temp;
      }
      vv[imax] = vv[j];
    }
    indx[j] = imax;

    if (A(j, j) == 0.0)
      A(j, j) = 1.0e-20;

    // Divide the column below the diagonal by the pivot.
    if (j != n - 1) {
      dum = 1.0 / A(j, j);
      for (int i = j + 1; i < n; i++)
        A(i, j) *= dum;
    }
  }
}

// Solves A * x = u by LU decomposition, leaving both arguments untouched.
vector lu_solve(const matrix_type &A, const vector &u) {
  constexpr int n = 3;
  int ip, ii = -1; // index of the first non-zero element of x, if any
  double sum;
  std::shared_ptr<int[]> indx{new int[n]};
  matrix_type LU(n, n);
  vector x{u};

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      LU(i, j) = A(i, j);

  lu_dcmp(LU, n, indx);

  // Forward substitution, unscrambling the permutation as we go.
  for (int i = 0; i < n; i++) {
    ip = indx[i];
    sum = x[ip];
    x[ip] = x[i];
    if (ii >= 0)
      for (int j = ii; j < i; j++)
        sum -= LU(i, j) * x[j];
    else if (sum != 0.0)
      ii = i;
    x[i] = sum;
  }

  // Back substitution.
  for (int i = n - 1; i >= 0; i--) {
    sum = x[i];
    for (int j = i + 1; j < n; j++)
      sum -= LU(i, j) * x[j];
    x[i] = sum / LU(i, i);
  }

  return x;
}
