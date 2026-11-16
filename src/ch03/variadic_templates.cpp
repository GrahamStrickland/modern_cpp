#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>

// template <typename T> inline T sum(T t) { return t; }

// template <typename... P> auto sum(const P &...p) { return (p + ...); }

template <typename... P> auto sum(const P &...p) { return (0 + ... + p); }

template <typename T, typename... P> inline T sum(T t, P... p) {
  return t + sum(p...);
}

template <typename... P> void count(P... p) {
  std::cout << "You have " << sizeof...(P) << " parameters.\n";
}

template <typename... Args> void dummy(Args...) {}

// template <typename... Args> void print1(std::ostream &os, const Args
// &...args) {
//   // (os << args << ", ")...; // Error: Can't expand here
//   dummy((os << args << ", ")...);
//   os << '\n';
// }

template <typename... Args> void print3(std::ostream &os, const Args &...args) {
  dummy((os << args << ", ", 0)...);
  os << '\n';
}

template <typename... Args> void print4(std::ostream &os, const Args &...args) {
  auto dummy [[maybe_unused]] = {(os << args << ", ", 0)...};
  os << '\n';
}

template <typename... Args> struct caller {
  caller(Args &&...args) : t(std::forward<Args>(args)...) {}

  // template <typename F> auto call(F f) const { f(/* t unpacked */); }
  template <typename F> auto call(F f) const {
    // call_help(f, std::make_index_sequence<sizeof...(Args)>{});
    std::apply(f, t);
  }

  // template <typename F, size_t... I>
  // auto call_help(F f, std::index_sequence<I...>) const {
  //   return f(std::get<I>(t)...);
  // }

  std::tuple<Args...> t;
};

int main() {
  // auto s = sum(-7, 3.7f, 9u, -2.6);
  auto s = -7 + 3.7f + 9u + -42.6;
  std::cout << "s is " << s << " and its type is " << typeid(s).name() << ".\n";

  auto s2 = sum(-7, 3.7f, 9u, -42.6);
  std::cout << "s2 is " << s2 << " and its type is " << typeid(s2).name()
            << ".\n";

  count(-7, 3.7f, 9u, -2.6);

  print3(std::cout, 3, 17.2, "Thingy");

  print4(std::cout, 3, 17.2, "Thingy");

  using seq1 = std::index_sequence<3, 9, 4, 11>;
  // using seq2 = std::index_sequence<0, 1, 2, 3>;
  using seq2 = std::make_index_sequence<4>;

  caller c{-7, 3.7f, 9u, -2.6};
  c.call(count<int, float, unsigned, double>);

  return EXIT_SUCCESS;
}
