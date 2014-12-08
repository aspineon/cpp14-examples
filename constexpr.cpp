#include "gtest/gtest.h"

// constexpr implies inline function
constexpr int triple(const int &x) {
  return 3 * x;
}

template<typename T, int N>
struct array {
  T value [N];
};

int triple_func(const int &x) {
  return 3 * x;
}

TEST(CONST_EXPR_TEST, constexpr_func) {
  // this implies triple(c) is calculated at compile time.
  const int c = 5;
  array<int, triple(c)> dummy;
  static_assert(15 == sizeof(dummy.value)/sizeof(int), "");

  // the following line would have compile error
  // array<int, triple_func(c)> dummy2;
}

TEST(CONST_EXPR_TEST, constexpr_var) {
  constexpr double PI = 3.141592653589793;
  static_assert(3.141592653589793 == PI, "");

  // the following two lines would have compile error
  // double var = 3.14;
  // static_assert(3.14 == var, "");
}