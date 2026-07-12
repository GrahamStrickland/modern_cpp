#include <cstdlib>
#include <vector>

struct too_small {};
struct too_large {};

template <typename Vector> class value_range_vector {
  using value_type = typename Vector::value_type;
  using size_type = typename Vector::size_type;

public:
  value_range_vector(Vector &vref, value_type minv, value_type maxv)
      : vref{vref}, minv{minv}, maxv{maxv} {}

  decltype(auto) operator[](size_type i) {
    decltype(auto) value = vref[i];
    if (value < minv)
      throw too_small{};
    if (value > maxv)
      throw too_large{};
    return value;
  }

private:
  Vector &vref;
  value_type minv, maxv;
};

int main(int argc, char *argv[]) {
  using Vec = std::vector<double>;
  Vec v = {2.3, 8.1, 9.2};

  value_range_vector<Vec> w{v, 1.0, 10.0};
  decltype(auto) val = w[1];

  return EXIT_SUCCESS;
}