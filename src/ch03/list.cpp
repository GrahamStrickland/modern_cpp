#include <cstdlib>
#include <iostream>

template <typename T> struct list_entry {
  list_entry(const T &value) : value{value}, next{nullptr} {}

  T value;
  list_entry<T> *next;
};

template <typename T> struct list_iterator {
  using value_type = T;
  list_iterator(list_entry<T> *entry) : entry{entry} {}

  T &operator*() { return entry->value; }

  const T &operator*() const { return entry->value; }

  list_iterator<T> &operator++() {
    entry = entry->next;
    return *this;
  }

  list_iterator<T> operator++(int) {
    list_iterator<T> tmp(*this);
    entry = entry->next;
    return tmp;
  }

  bool operator!=(const list_iterator<T> &other) const {
    return entry != other.entry;
  }

  list_entry<T> *entry;
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

  list_iterator<T> begin() { return list_iterator<T>(first); }
  list_iterator<T> end() { return list_iterator<T>(0); }
};

template <typename T> T sum(const list<T> &l) {
  T sum = 0;
  for (auto entry = l.first; entry != nullptr; entry = entry->next)
    sum += entry->value;
  return sum;
}

template <typename Iter, typename T>
inline T accumulate(Iter it, Iter end, T init) {
  for (; it != end; ++it)
    init += *it;
  return init;
}

int main(int argc, char *argv[]) {
  list<float> l;
  l.append(2.0f);
  l.append(4.0f);
  l.append(7.0f);

  std::cout << "sum l is " << sum(l) << '\n';

  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "array sum = " << accumulate(a, a + 10, 0.0) << '\n';
  std::cout << "list sum = " << accumulate(l.begin(), l.end(), 0) << '\n';

  return EXIT_SUCCESS;
}
