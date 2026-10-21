#include <cstdlib>
#include <iostream>
#include <vector>

template <typename Iter, typename T, typename BinaryFunction>
T accumulate(Iter it, Iter end, T init, BinaryFunction op) {
  for (; it != end; ++it)
    init = op(init, *it);
  return init;
}

template <typename T> struct add {
  T operator()(const T &x, const T &y) const { return x + y; }
};

struct times {
  template <typename T> T operator()(const T &x, const T &y) const {
    return x * y;
  }
};

int main(int argc, char *argv[]) {
  std::vector<double> v = {7.0, 8.0, 11.0};
  double s = accumulate(v.begin(), v.end(), 0.0, add<double>{});
  double p = accumulate(v.begin(), v.end(), 1.0, times{});

  std::cout << "s = " << s << '\n' << "p = " << p << '\n';

  return EXIT_SUCCESS;
}
