#include <algorithm>
#include <cstdlib>
// #include <iterator>
#include <string>
#include <tuple>

template <typename Value> struct vec {
  vec(std::initializer_list<Value> values) : s(values.size()), d(new
  Value[s]) {
    std::copy(begin(values), end(values), d);
  }
  // template <class Iter>
  // vec(Iter beg, Iter end)
  //     ->vec<typename std::iterator_traits<Iter>::value_type>
  //     : s(std::distance(beg, end)),
  //     d(new Value[s]) {
  //   std::copy(beg, end, d);
  // }

  std::size_t s;
  Value *d;
};

int main(int argc, char *argv[]) {
  using namespace std::literals;

  std::tuple<int, float, std::string> t1(3, 3.2f, "text"s);
  std::tuple t2(3, 3.2f, "text"s);

  vec v = {2.3, 3.4, 4.5, 5.6};

  // int array[] = {3, 4, 5, 6};
  // vec w(std::begin(array), std::end(array));

  return EXIT_SUCCESS;
}
