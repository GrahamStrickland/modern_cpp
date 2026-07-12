#include <algorithm>
#include <cstdlib>
#include <string>
#include <tuple>

template <typename Value> struct vec {
  vec(std::initializer_list<Value> values) : s(values.size()), d(new Value[s]) {
    std::copy(begin(values), end(values), d);
  }

  std::size_t s;
  Value *d;
};

int main(int argc, char *argv[]) {
  using namespace std::literals;

  std::tuple<int, float, std::string> t1(3, 3.2f, "text"s);
  std::tuple t2(3, 3.2f, "text"s);

  vec v = {2.3, 3.4, 4.5, 5.6};

  return EXIT_SUCCESS;
}