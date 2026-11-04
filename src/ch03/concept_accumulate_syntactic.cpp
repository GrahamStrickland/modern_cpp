#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

// template <typename Iter, typename Value>
// concept Summable = requires(Iter it, Value init) {
//   requires std::input_iterator<Iter>;
//   // requires std::is_copy_constructible_v<Value>;
//   requires std::is_move_constructible_v<Value>;
//   // Value{init}; // Attempt a copy
//   Value{std::move(init)};
//   init += *it;
// };

template <typename T>
concept Returnable =
    std::is_move_constructible_v<T> || std::is_copy_constructible_v<T>;

template <typename Iter, typename Value>
concept Summable = requires(Iter it, Value init) {
  requires std::input_iterator<Iter>;
  requires Returnable<Value>;
  init += *it;
};

// template <typename Iter, typename Value, typename Op>
// concept Accumulatable = requires(Iter it, Value init, Op op) {
//   requires std::input_iterator<Iter>;
//   requires Returnable<Value>;
//   init = op(init, *it);
// };

// template <typename Iter, typename Value>
//   requires Summable<Iter, Value>
// Value accumulate(Iter first, Iter last, Value init)
// // requires Summable<Iter, Value>
// {
//   for (; first != last; ++first)
//     init += *first;
//   return init;
// }

// template <typename Iter, typename Value, typename Op>
// Value accumulate(Iter first, Iter last, Value init, Op op)
//   requires Accumulatable<Iter, Value, Op>
// {
//   for (; first != last; ++first)
//     init = op(init, *first);
//   return init;
// }

template <typename Iter, typename Value, typename Op>
Value accumulate(Iter first, Iter last, Value init, Op op)
  requires requires(Iter it, Value init, Op op) {
    requires std::input_iterator<Iter>;
    requires Returnable<Value>;
    init = op(init, *it);
  }
{
  for (; first != last; ++first)
    init = op(init, *first);
  return init;
}

struct uncopyable {
  uncopyable(int v) : v{v} {}
  uncopyable(const uncopyable &) = delete;
  uncopyable(uncopyable &&) = default;

  uncopyable &operator+=(const uncopyable &rhs) & {
    v += rhs.v;
    return *this;
  }

  operator int() const { return v; }
  int v;
};

struct unmovable {
  unmovable(int v) : v{v} {}
  unmovable(const unmovable &) = default;
  unmovable(unmovable &&) = delete;

  unmovable &operator+=(const unmovable &rhs) & {
    v += rhs.v;
    return *this;
  }

  operator int() const { return v; }
  int v;
};

int main() {
  // uncopyable arr[] = {1, 2, 3};

  // auto sum = accumulate(std::begin(arr), std::end(arr), uncopyable{0});
  // std::cout << "sum = " << sum << '\n';

  // unmovable arr2[] = {1, 2, 3};

  // auto sum2 = accumulate(std::begin(arr2), std::end(arr2), unmovable{0});
  // std::cout << "sum2 = " << sum2 << '\n';

  std::vector<int> v;
  v.reserve(4);

  for (int i = 0; i < 4; i++) {
    v.push_back(i);
  }

  auto sum3 = accumulate(v.begin(), v.end(), 0, std::plus<int>());
  std::cout << "sum3 = " << sum3 << '\n';

  return EXIT_SUCCESS;
}
