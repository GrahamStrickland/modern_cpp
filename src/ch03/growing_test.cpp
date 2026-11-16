#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <tuple>

using small_test = std::tuple<int, float>;

template <typename... Tuples>
using tuple_cat_type = decltype(std::tuple_cat(std::declval<Tuples>()...));

using compact_set = tuple_cat_type<small_test, std::tuple<short, double>>;

template <typename Fun> void foreach_type(std::tuple<>, Fun) {}

template <typename First, typename... Others, typename Fun>
void foreach_type(std::tuple<First, Others...>, Fun f) {
  Fun::template eval<First>();
  foreach_type(std::tuple<Others...>{}, f);
}

struct identity_test {
  template <typename T> static void eval() {
    T zero{0}, one{1}, nine{9};
    if (zero + nine != nine)
      throw std::logic_error{"Addition wrong"};
    if (one * nine != nine)
      throw std::logic_error{"Multiplication wrong"};
    std::cout << "Test passed for " << typeid(T).name() << std::endl;
  }
};

int main() {
  foreach_type(compact_set{}, identity_test{});

  return EXIT_SUCCESS;
}
