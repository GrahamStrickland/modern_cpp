#include <type_traits>

template <typename T, T Value> struct integral_constant;

using false_type = integral_constant<bool, false>;

template <auto Value>
struct integral_constant_c : std::integral_constant<decltype(Value), Value> {};

using f_type = integral_constant_c<false>;

template <auto Value>
using integral_constant_t = std::integral_constant<decltype(Value), Value>;

using t_type = integral_constant_t<true>;
