#include "gtest/gtest.h"

// trailing return type.
template<typename T, typename U>
auto product(const T &t, const U &u) -> decltype(t * u) {
  return t * u;
}

TEST(TYPE_TEST, trailing_return_type) {
  EXPECT_EQ(1.0 * 5L, product(5L, 1.0));
}

// decltype(auto) return type deduction
template<typename T, typename U>
decltype(auto) sum(const T &t, const U &u) {
  return t + u;
}

TEST(TYPE_TEST, decltype_auto) {
  EXPECT_EQ(1.0 + 5L, sum(5L, 1.0));
}

// template alias
template<typename T>
using pair_s = std::pair<T, T>;

TEST(TYPE_TEST, template_alias) {
  pair_s<int> p(3, 4);
  EXPECT_EQ(3, p.first);
  EXPECT_EQ(4, p.second);
}

// variadic templates. defined recursively
template<typename T>
T sum(T n) {
  return n;
}
template <typename T, typename... Args>
T sum(T n, Args... rest) {
  return n + sum(rest...);
}

TEST(TYPE_TEST, variadic_template) {
  EXPECT_EQ(15, sum(1,2,3,4,5));
  EXPECT_DOUBLE_EQ(6.0, sum(1.0, 2.0, 3.0));
}
