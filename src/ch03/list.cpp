#include <cstdlib>
#include <iostream>

template <typename T> struct list_entry {
  list_entry(const T &value) : value{value}, next{nullptr} {}

  T value;
  list_entry<T> *next;
};

template <typename T> struct list {
  list() : first{nullptr}, last{nullptr} {}
  ~list() {
    while (first) {
      list_entry<T> *tmp = first->next;
      delete first;
      first = tmp;
    }
  }
  void append(const T &x) {
    last = (first ? last->next : first) = new list_entry<T>(x);
  }
  list_entry<T> *first, *last;
};

template <typename T>
T sum(const list<T> &l) {
  T sum = 0;
  for (auto entry = l.first; entry != nullptr; entry = entry->next)
    sum += entry->value;
  return sum;
}

int main(int argc, char *argv[]) {
  list<float> l;
  l.append(2.0f);
  l.append(4.0f);
  l.append(7.0f);

  std::cout << "sum l is " << sum(l) << '\n';

  return EXIT_SUCCESS;
}
