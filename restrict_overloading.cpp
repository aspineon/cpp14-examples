#include "gtest/gtest.h"

int integer_square(int s) {
  return s * s;
}
int integer_square(long) = delete;
int integer_square(double) = delete;

/**
 * A demonstration of preventing the user from
 * overloading the function, via `delete` keyword.
 */
TEST(NO_OVERLOADING, by_delete_keyword) {

  EXPECT_EQ(4, integer_square(2));
  // The following statements would have compile errors
  // EXPECT_EQ(4, integer_square(2L));
  // EXPECT_DOUBLE_EQ(4.0, integer_square(2.0));
}