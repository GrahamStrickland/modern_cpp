#include <cassert>
#include <memory>

template <typename T> class vector {
  void check_index(int i) { assert(i >= 0 && i < my_size); }

public:
  explicit vector(int size) : my_size{size}, data{new T[my_size]} {}

  vector(const vector &that) : my_size{that.my_size}, data{new T[my_size]} {
    std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
  }

  int size() const { return my_size; }

  const T &operator[](int i) const {
    check_index(i);
    return data[i];
  }

private:
  int my_size;
  std::unique_ptr<T[]> data;
};

class vector_bool_proxy {
public:
  vector_bool_proxy(unsigned char &byte, int p)
      : byte{byte}, mask{static_cast<unsigned char>(1 << p)} {}

  operator bool() const { return byte & mask; }

  vector_bool_proxy &operator=(bool b) {
    if (b)
      byte |= mask;
    else
      byte &= ~mask;
    return *this;
  }

private:
  unsigned char &byte;
  unsigned char mask;
};

template <> class vector<bool> {
public:
  explicit vector(int size)
      : my_size{size}, data{new unsigned char[(my_size + 7) / 8]} {}
  vector() : my_size(0) {}

  bool operator[](int i) const { return (data[i / 8] >> i % 8) & 1; }

  vector_bool_proxy operator[](int i) { return {data[i / 8], i % 8}; }

private:
  int my_size;
  std::unique_ptr<unsigned char[]> data;
};
