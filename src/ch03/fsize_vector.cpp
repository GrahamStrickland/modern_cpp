#include <algorithm>
#include <cassert>
#include <cstdlib>

template <typename T, int Size = 3> class fsize_vector {
  using self = fsize_vector;

public:
  using value_type = T;
  static constexpr int my_size = Size;

  fsize_vector(int s = Size) { assert(s == Size); }

  self &operator=(const self &that) {
    std::copy(that.data, that.data + Size, data);
    return *this;
  }

  self operator+(const self &that) const {
    self sum;
    for (int i = 0; i < my_size; ++i)
      sum[i] = data[i] + that[i];
    return sum;
  }

private:
  T data[my_size];
};

int main(int argc, char *argv[]) {
  // fsize_vector<float, 3> v;
  // fsize_vector<float, 4> w;
  // vector<float> x(3), y(4);

  // v = w; // Error at compile time
  // x = y; // Error at run time

  fsize_vector<float> v, w, x, y;

  fsize_vector<float, 4> space_time;
  fsize_vector<float, 11> string;

  return EXIT_SUCCESS;
}
