#include "gtest/gtest.h"

/**
 * Difference between name and expression.
 */
TEST(DECLTYPE_TEST, lvalue_expression) {
  int i = 0;
  // If it's a name, it returns the declared type.
  EXPECT_TRUE((std::is_same<int, decltype(i)>::value));

  // The expression lvalue preserves reference type.
  EXPECT_TRUE((std::is_same<int&, decltype((i))>::value));
}
