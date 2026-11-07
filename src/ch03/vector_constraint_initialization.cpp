#include <cstdlib>
#include <iterator>
#include <list>
#include <memory>
#include <ranges>

namespace dmc2e {
template <typename Value> class vector {
public:
  explicit vector(int size) : my_size{size}, data{new Value[my_size]} {}

  template <std::ranges::forward_range Range>
  vector(Range &&r)
      : vector(begin(std::forward<Range>(r)), end(std::forward<Range>(r))) {}

  template <std::forward_iterator Iter>
  vector(Iter first, Iter last) : vector(distance(first, last)) {
    using std::copy;
    copy(first, last, &data[0]);
  }

private:
  int my_size;
  std::unique_ptr<Value[]> data;
};

template <std::forward_iterator Iter>
vector(Iter first, Iter last) -> vector<std::iter_value_t<Iter>>;

template <std::ranges::forward_range Range>
vector(Range &&r) -> vector<std::iter_value_t<decltype(std::begin(r))>>;
}; // namespace dmc2e

int main() {
  std::list l = {17, 4, 3, 9, 2};
  dmc2e::vector<int> v{begin(l), end(l)};
  dmc2e::vector x = l;
  // dmc2e::vector w = std::ranges::views::iota{1, 100};

  return EXIT_SUCCESS;
}
