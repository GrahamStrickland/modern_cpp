#include <cstddef>
#include <cstdlib>
#include <tuple>
#include <type_traits>

// void complex_fixture();

namespace dmc {
template <typename T, typename U = T> class complex {
public:
  explicit complex(T rn = 0.0, U in = 0.0) : r{rn}, i{in} {}

  T const &real() const { return r; }
  U const &imag() const { return i; }

  template <std::size_t N> decltype(auto) get() const {
    if constexpr (N == 0)
      return r;
    else
      return i;
  }

private:
  // auto uncover_members() const { return std::tuple{r, i}; }
  // friend complex_fixture;

  T r;
  U i;
};

template <std::size_t N, typename T> decltype(auto) get(const complex<T> &z) {
  if constexpr (N == 0)
    return z.real();
  else
    return z.imag();
}

template <std::size_t N, typename T> decltype(auto) get(const complex<T> &z);

// template <typename T>
// decltype(auto) get<0, T>(const complex<T> &z) {
//   return z.real();
// }
//
// template <typename T>
// decltype(auto) get<1, T>(const complex<T> &z) {
//   return z.imag();
// }

template <> decltype(auto) get<0, int>(const complex<int> &z) {
  return z.real();
}

template <> decltype(auto) get<1, int>(const complex<int> &z) {
  return z.imag();
}
} // namespace dmc

namespace std {
template <typename T, typename U>
struct tuple_size<dmc::complex<T, U>>
    : public std::integral_constant<std::size_t, 2> {};

template <std::size_t N, typename T, typename U>
struct tuple_element<N, dmc::complex<T, U>> {
  using type = decltype(std::declval<dmc::complex<T, U>>().template get<N>());
};
} // namespace std

// void complex_fixture() {
//   using namespace dmc;
//   complex<int, short> z{3, 7};
//   auto [re, im] = z.uncover_members();
// }

int main(int argc, char *argv[]) {
  using namespace dmc;

  complex<int, short> z{3, 7};
  auto [re, im] = z;

  return EXIT_SUCCESS;
}
