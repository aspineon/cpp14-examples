#include "gtest/gtest.h"

// trailing return type.
template<typename T, typename U>
auto product(const T &t, const U &u) -> decltype(t * u) {
  return t * u;
}

// decltype(auto) return type deduction 
template<typename T, typename U>
decltype(auto) sum(const T &t, const U &u) {
  return t + u;
}

TEST(TYPE_INFERENCE_TEST, trailing_return_type) {
  EXPECT_EQ(1.0 * 5L, product(5L, 1.0));
}

TEST(TYPE_INFERENCE_TEST, decltype_auto) {
  EXPECT_EQ(1.0 + 5L, sum(5L, 1.0));
}