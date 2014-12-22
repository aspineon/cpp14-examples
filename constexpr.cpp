#include "gtest/gtest.h"

// constexpr implies inline function
constexpr int triple(const int &x) {
  return 3 * x;
}

template<typename T, size_t N>
struct array {
  T value [N];
};

size_t triple_func(const size_t &x) {
  return 3 * x;
}

/**
 * constexpr can be calculated at compile time, and thus
 * the array declaration wouldn't have compile error, while
 * if using non-constexpr function, it would have compile error
 */
TEST(CONST_EXPR_TEST, constexpr_func) {
  // this implies triple(c) is calculated at compile time.
  const size_t c = 5;
  array<int, triple(c)> dummy;
  static_assert(15 == sizeof(dummy.value)/sizeof(int), "");

  // the following line would have compile error
  // array<int, triple_func(c)> dummy2;
}

/**
 * Another test of constexpr for variable. The mainpoint here
 * is that static_assert would result in a compile error if
 * it was not declared as constexpr.
 */
TEST(CONST_EXPR_TEST, constexpr_var) {
  constexpr double PI = 3.141592653589793;
  static_assert(3.141592653589793 == PI, "");

  // the following two lines would have compile error
  // double var = 3.14;
  // static_assert(3.14 == var, "");
}