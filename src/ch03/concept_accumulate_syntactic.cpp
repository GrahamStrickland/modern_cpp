#include <cstdlib>
#include <iterator>
#include <type_traits>

template <typename Iter, typename Value>
concept Summable = requires(Iter it, Value init) {
  requires std::input_iterator<Iter>;
  requires std::is_copy_constructible_v<Value>;
  Value{init}; // Attempt a copy
  init += *it;
};

template <typename Iter, typename Value>
  requires Summable<Iter, Value>
Value accumulate(Iter first, Iter last, Value init)
// requires Summable<Iter, Value>
{
  for (; first != last; ++first)
    init += *first;
  return init;
}

int main() {
  return EXIT_SUCCESS;
}
