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

template <typename TPara> void f2(const TPara &p) { info(TPara, p); }

template <typename TPara> void f3(TPara &p) { info(TPara, p); }

template <typename TPara> void f4(TPara &&p) { info(TPara, p); }

template <typename TPara> void f5(TPara &&p) {
  info(TPara, std::forward<TPara>(p));
}

int main(int argc, char *argv[]) {
  int i = 0;
  int &j = i;
  const int &k = i;

  std::cout << "f1(TPara p) {}" << std::endl;
  f1(3);
  f1(i);
  f1(j);
  f1(k);

  std::unique_ptr<int> up;
  // f1(up); // Error: no copy constructor
  f1(std::move(up)); // Okay: use move constructor

  std::cout << "f2(TPara p) {}" << std::endl;
  f2(3);
  f2(i);
  f2(j);
  f2(k);

  f2(std::move(up));

  std::cout << "f3(TPara p) {}" << std::endl;
  // f3(3);
  f3(i);
  f3(j);
  f3(k);

  // f3(std::move(up));

  std::cout << "f4(TPara p) {}" << std::endl;
  f4(3);
  f4(i);
  f4(j);
  f4(k);

  f4(std::move(i));
  f4(std::move(up));

  std::cout << "f5(TPara p) { f4(forward<TPara>(p)); }" << std::endl;
  f5(3);
  f5(i);
  f5(j);
  f5(k);

  f5(std::move(i));
  f5(std::move(up));

  return EXIT_SUCCESS;
}
