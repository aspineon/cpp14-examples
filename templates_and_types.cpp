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

// template alias
template<typename T>
using pair_s = std::pair<T, T>;

// variadic templates. defined recursively
template<typename T>
T sum(T n) {
  return n;
}
template <typename T, typename... Args>
T sum(T n, Args... rest) {
  return n + sum(rest...);
}

/**
 * Testing if `product` function has properly deducted
 * the return type of 5L * 1.0
 */
TEST(TYPE_TEST, trailing_return_type) {
  EXPECT_EQ(1.0 * 5L, product(5L, 1.0));
}

/**
 * Testing if decltype(auto) has properly deducted
 * the return type of 5L * 1.0
 */
TEST(TYPE_TEST, decltype_auto) {
  EXPECT_EQ(1.0 + 5L, sum(5L, 1.0));
}

/**
 * Testing the feature of template alias
 */
TEST(TYPE_TEST, template_alias) {
  pair_s<int> p(3, 4);
  EXPECT_EQ(3, p.first);
  EXPECT_EQ(4, p.second);
}

/**
 * Testing the feature of variadic template
 */
TEST(TYPE_TEST, variadic_template) {
  EXPECT_EQ(15, sum(1,2,3,4,5));
  EXPECT_DOUBLE_EQ(6.0, sum(1.0, 2.0, 3.0));
}
