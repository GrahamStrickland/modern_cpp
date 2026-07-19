#include <cmath>
#include <cstdlib>
#include <memory>

#include "../ch02/matrix_type.h"
#include "../ch02/vector.h"

auto lu(const matrix_type &A);
void lu_dcmp(matrix_type &A, int n, std::shared_ptr<int[]> indx);

int main(int argc, char *argv[]) {
  matrix_type A(3, 3);
  A = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  auto [LU, p] = lu(A);

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

auto lu(const matrix_type &A) {
  int ii = 0, ip;
  double sum;
  std::shared_ptr<int[]> indx{new int[3]};
  vector p{0.0, 0.0, 0.0};
  matrix_type LU(3, 3);
  LU = A;

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
    p[i] = sum / A(i, i);
  }

  return tuple<matrix_type, vector>(LU, p);
}
