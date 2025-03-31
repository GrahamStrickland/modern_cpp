#include <iostream>

#include "vector.h"

void lu_dcmp(vector A[], int n, int *indx, double *d);
vector lu_solve(vector A[], vector u);

int main(int argc, char *argv[]) {
  vector v1(4);
  v1[0] = v1[1] = 1.0;
  v1[2] = 2.0;
  v1[3] = -3.0;

  const vector v2{v1};
  std::cout << "v2[3] is " << v2[3] << '\n';

  v1[3] = 3.14;
  std::cout << "v2[3] is " << v2[3] << '\n';

  std::cout << "dot(v1, v2) is " << dot(v1, v2) << '\n';
  // std::cout << "dot(8, 8) is " << dot(8, 8) << '\n';

  v1 = v2;
  std::cout << "after v1 = v2, dot(v1, v2) is " << dot(v1, v2) << '\n';

  vector v3 = {1.0, 2.0, 3.0};
  vector v4{1.0, 2.0, 3.0};

  v3 = {1.0, 2.0, 3.0};

  vector A[3] = {{1.0, 2.0, 3.0}, {3.0, 2.0, 1.0}, {1.0, 0.0, -1.0}};
  vector x = lu_solve(A, vector{1.0, 2.0, 3.0});

  return EXIT_SUCCESS;
}

void lu_dcmp(vector A[], int n, int *indx, double *d) {
  int i, imax, j, k;
  double big, dum, sum, temp;
  vector vv = {1.0, 1.0, 1.0};

  *d = 1.0;
  for (i = 0; i < n; i++) {
    big = 0.0;
    for (j = 0; j < n; j++)
      if ((temp = fabs(A[i][j])) > big)
        big = temp;

    if (big == 0.0)
      throw std::runtime_error("Singular matrix in routine lu_solve");

    vv[i] = 1.0 / big;
  }

  for (j = 0; j < n; j++) {
    for (i = 0; i < j; i++) {
      sum = A[i][j];
      for (k = 0; k < i; k++)
        sum -= A[i][j] * A[k][j];
      A[i][j] = sum;
    }

    big = 0.0;
    for (i = j; i < n; i++) {
      sum = A[i][j];
      for (k = 0; k < j; k++)
        sum -= A[i][j] * A[k][j];
      A[i][j] = sum;

      if ((dum = vv[i] * fabs(sum)) >= big) {
        big = dum;
        imax = i;
      }
    }

    if (j != imax) {
      for (k = 0; k < n; k++) {
        sum = A[imax][k];
        A[imax][k] = A[j][k];
        A[j][k] = dum;
      }
      *d = -(*d);
      vv[imax] = vv[j];
    }
    indx[j] = imax;

    if (A[j][j] == 0.0)
      A[j][j] = 1.0e-20;

    if (j != n) {
      dum = 1.0 / A[j][j];
      for (i = j; i < n; i++)
        A[i][j] *= dum;
    }
  }
}

vector lu_solve(vector A[], vector u) {
  int i, ii = 0, ip, j;
  double sum;
  double *d = nullptr;
  int *indx = new int[3];
  vector x{};

  lu_dcmp(A, 3, indx, d);

  for (i = 0; i < 3; i++) {
    ip = indx[i];
    sum = u[ip];
    u[ip] = u[i];
    if (ii)
      for (j = ii; j <= i; j++)
        sum -= A[i][j] * u[j];
    else if (sum)
      ii = i;
    u[i] = sum;
  }

  for (i = 2; i >= 0; i--) {
    sum = u[i];
    for (j = i + 1; j < 3; j++)
      sum -= A[i][j] * u[j];
    x[i] = sum / A[i][i];
  }

  delete d;
  delete[] indx;

  return x;
}
