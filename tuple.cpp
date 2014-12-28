#include "gtest/gtest.h"
#include <tuple>

/**
 * Example usage of tuple get
 */
TEST(TUPLE_TEST, tuple_get) {
  auto t = std::make_tuple(1, 1.2, "foo");
  // test the type of t
  EXPECT_TRUE((std::is_same<std::tuple<int, double, char const*>, decltype(t)>::value));

  // test the value of t
  EXPECT_EQ(1, (std::get<0>(t)));
  EXPECT_EQ(1.2, (std::get<1>(t)));
  EXPECT_EQ("foo", (std::get<2>(t)));
}

/**
 * Example usage of 'tie'
 */
TEST(TUPLE_TEST, tuple_unpack) {
  auto t = std::make_tuple(1, 1.2, "foo");
  // Unpack the tuple
  int i;
  std::string s;
  std::tie(i, std::ignore, s) = t;
  EXPECT_EQ(1, i);
  EXPECT_EQ("foo", s);
}
