#include <cstdlib>
#include <iostream>

// #include "matrix_type.h"
#include "vector.h"

// void lu_dcmp(matrix_type A, int n, int *indx, double *d);
// vector lu_solve(matrix_type A, vector u);

vector f();
inline vector ones(int n) {
  vector v(n);
  for (unsigned i = 0; i < n; ++i)
    v[i] = 1.0;
  return v;
}

int main() {
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

  // matrix_type A(3, 3);
  // vector x = lu_solve(A, vector{1.0, 2.0, 3.0});

  vector v5 = {{1.0, 2.0, 3.0}}, v6{3, 4, 5};

  double d = dot({3, 4, 5}, {7, 8, 9});
  std::cout << "dot({3, 4, 5}), {7, 8, 9}) = " << d << '\n';

  vector v7(3);
  v7 = f(); // f returns v8

  std::cout << "v7 = f(), v7 = " << v7 << '\n';

  vector w(ones(7));

  std::cout << "w = " << w << '\n';

  vector x(std::move(w));
  std::cout << "After move, w = " << w << ", x = " << x << '\n';

  v7 = std::move(v6);
  std::cout << "After move, v7 = " << v7 << ", v6 = " << v6 << '\n';

  return EXIT_SUCCESS;
}

vector f() {
  vector v8{1.0, 2.0, 3.0};
  return v8;
}
