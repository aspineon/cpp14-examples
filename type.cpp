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