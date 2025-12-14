#include "length.h"

length operator"" _m(long double l) { return length(static_cast<double>(l)); }

length operator"" _km(long double l) {
  return length(1000.0 * static_cast<double>(l));
}

length operator"" _nm(long double l) {
  return length(1852.0 * static_cast<double>(l));
}

length operator"" _miles(long double l) {
  return length(1609.344 * static_cast<double>(l));
}

length operator"" _m(unsigned long long l) {
  return length(static_cast<double>(l));
}

length operator"" _km(unsigned long long l) {
  return length(1000.0 * static_cast<double>(l));
}

length operator"" _nm(unsigned long long l) {
  return length(1852.0 * static_cast<double>(l));
}

length operator"" _miles(unsigned long long l) {
  return length(1609.344 * static_cast<double>(l));
}
