#include <cstdlib>
#include <iostream>

template <typename T, unsigned N> T sum(const T (&array)[N]) {
  T sum(0);
  for (int i = 0; i < N; ++i)
    sum += array[i];
  return sum;
}

template <typename T> inline T accumulate_array(T *a, T *a_end) {
  T sum(0);
  for (; a != a_end; ++a)
    sum += *a;
  return sum;
}

int main(int argc, char *argv[]) {
  int ai[] = {2, 4, 7};
  double ad[] = {2., 4.5, 7.};

  std::cout << "sum ai is " << sum(ai) << '\n';
  std::cout << "sum ad is " << sum(ad) << '\n';

  std::cout << "sum ai is " << accumulate_array(ai, &ai[3]) << '\n';
  std::cout << "sum ad is " << accumulate_array(ad, ad + 3) << '\n';

  return EXIT_SUCCESS;
}
