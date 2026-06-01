#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>

template <typename T> struct wrap {};

// wrap the type since typeid forgets all the qualifiers
template <typename T> std::string my_info() { return typeid(wrap<T>).name(); }

template <typename T> std::string l_or_r(const T &) { return "const"; }

template <typename T> std::string l_or_r(T &) { return "mutable"; }

// Evil hack for testing
#define info(TPara, p)                                                         \
  std::cout << "Type of TPara is " << typeid(TPara).name()                     \
            << " == " << my_info<TPara>() << ", is"                            \
            << (std::is_lvalue_reference<TPara>::value ? "" : " no")           \
            << " lref"                                                         \
            << ", is" << (std::is_rvalue_reference<TPara>::value ? "" : " no") \
            << " rref"                                                         \
            << ", is" << (std::is_const<TPara>::value ? "" : " not")           \
            << " const\n"                                                      \
            << "Type of p is " << typeid(p).name()                             \
            << " == " << my_info<decltype(p)>() << ", is"                      \
            << (std::is_lvalue_reference<decltype(p)>::value ? "" : " no")     \
            << " lref"                                                         \
            << ", is"                                                          \
            << (std::is_rvalue_reference<decltype(p)>::value ? "" : " no")     \
            << " rref"                                                         \
            << ", is" << l_or_r(p) << "\n===================\n\n";

struct rubbish {};

struct dummy {
  dummy &operator=(int i) {
    j = i;
    return *this;
  }
  int j = 8;
};

// template <typename TPara>
// void f(FPara p);

template <typename TPara> void f1(TPara p) { info(TPara, p); }

int main(int argc, char *argv[]) {
  int i = 0;
  int &j = i;
  const int &k = i;

  f1(3);
  f1(i);
  f1(j);
  f1(k);

  std::unique_ptr<int> up;
  // f1(up); // Error: no copy constructor
  f1(std::move(up)); // Okay: use move constructor

  return EXIT_SUCCESS;
}
