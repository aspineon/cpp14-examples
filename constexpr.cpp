#include "gtest/gtest.h"

TEST(CONST_EXPR_TEST, constexpr) {
  const int size = 5;
  int a[size];
  int b[size * 2];
  EXPECT_EQ(size, sizeof(a)/sizeof(int));
  EXPECT_EQ(size * 2, sizeof(b)/sizeof(int));
}