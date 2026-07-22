#include <cmath>
#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <tuple>

#include "../ch02/matrix_type.h"
#include "../ch02/vector.h"

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

// Returns the LU decomposition of A together with its row permutation.
auto lu(const matrix_type &A) {
  constexpr int n = 3;
  std::shared_ptr<int[]> indx{new int[n]};
  vector p(static_cast<unsigned>(n));
  matrix_type LU(n, n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      LU(i, j) = A(i, j);

  lu_dcmp(LU, n, indx);

  for (int i = 0; i < n; i++)
    p[i] = indx[i];

  return std::tuple<matrix_type, vector>(std::move(LU), std::move(p));
}

int main() {
  matrix_type A(3, 3);
  A = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 10.0}};

  auto [LU, p] = lu(A);

  std::cout << "A = " << A << "\nLU = " << LU << "\npermutation = " << p
            << '\n';

  return EXIT_SUCCESS;
}
