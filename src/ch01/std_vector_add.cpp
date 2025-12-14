#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

void vector_add(const std::vector<float> &v1, const std::vector<float> &v2,
                std::vector<float> &s) {
  assert(v1.size() == v2.size());
  assert(v1.size() == v2.size());
  for (unsigned i = 0; i < v1.size(); ++i)
    s[i] = v1[i] + v2[i];
}

int main(int argc, char *argv[]) {
  std::vector<float> v = {1, 2, 3}, w = {7, 8, 9}, s(3);

  std::cout << "v + w = [";
  for (int i = 0; i < 3; ++i)
    std::cout << v[i] << (i < 2 ? ", " : "] + [");
  for (int i = 0; i < 3; ++i)
    std::cout << w[i] << (i < 2 ? ", " : "] = [");

  vector_add(v, w, s);
  for (int i = 0; i < 3; ++i)
    std::cout << s[i] << (i < 2 ? ", " : "]\n");

  return EXIT_SUCCESS;
}
