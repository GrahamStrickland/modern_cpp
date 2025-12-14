#include <iostream>

#include "length.h"

int main(int argc, char *argv[]) {
  length len1{13.5};
  length len2{14.2_km}, len3 = 14.2_km;

  auto l1 = 13.5_m, l2 = 14.2_km, l3 = 3 * l2, l4 = 7.2_nm;

  std::cout << "2km + 30m = " << 2._km + 30.0_m << std::endl;
  std::cout << "2.5miles + 3.2nm = " << 2.5_miles + 3.2_nm << std::endl;

  return EXIT_SUCCESS;
}
