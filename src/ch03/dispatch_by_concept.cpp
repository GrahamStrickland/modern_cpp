#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

namespace dmc2e {
// template <typename Iter>
// void advance(Iter &it, unsigned n)
//   requires std::bidirectional_iterator<
//       Iter> // std::input_or_output_iterator<Iter>
// {
//   if (n >= 0) {
//     while (n-- > 0)
//       ++it;
//   } else {
//     while (n++ > 0)
//       --it;
//   }
// }

// template <typename Iter>
// void advance(Iter &it, int n)
//   requires std::random_access_iterator<Iter>
// {
//   it += n;
// }

// template <std::random_access_iterator Iter> void advance(Iter &it, int n) {
//   it += n;
// }

void advance(std::random_access_iterator auto &it, int n) { it += n; }
}; // namespace dmc2e

int main() {
  std::vector<int> v;
  v.reserve(101);

  for (int i = 0; i <= 100; i++) {
    v.push_back(i);
  }

  auto it = v.begin();
  for (int i = 0; i < 100; i += 3) {
    std::cout << *it << ' ';
    dmc2e::advance(it, 3);
  }
  std::cout << '\n';

  it = v.end();
  it--;
  for (int i = 100; i >= 0; i -= 2) {
    std::cout << *it << ' ';
    dmc2e::advance(it, -2);
  }
  std::cout << '\n';

  return EXIT_SUCCESS;
}
