#include <iostream>

#include "matrix_type.h"
#include "vector.h"

void lu_dcmp(matrix_type A, int n, int *indx, double *d);
vector lu_solve(matrix_type A, vector u);

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

  matrix_type A(3, 3);
  vector x = lu_solve(A, vector{1.0, 2.0, 3.0});

  return EXIT_SUCCESS;
}
