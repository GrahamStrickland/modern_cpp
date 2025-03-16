#ifndef SOLVER_H
#define SOLVER_H

#include "matrix_type.h"

class solver {
public:
  solver(const matrix_type &A) : A{A} {}

private:
  const matrix_type &A;
};
#endif // SOLVER_H
