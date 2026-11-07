#include <cstdlib>
#include <iostream>
#include <ostream>

template <typename T> inline T sum(T t) { return t; }

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

  return EXIT_SUCCESS;
}
