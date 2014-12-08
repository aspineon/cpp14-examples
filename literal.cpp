#include <string>
#include "gtest/gtest.h"

TEST(LITERAL_TEST, binary_literal) {
  // binary literal
  int binary = 0b1001;
  EXPECT_EQ(9, binary);
  auto binary_seperated = 0b1001'1001;
  EXPECT_EQ(153, binary_seperated);
}

TEST(LITERAL_TEST, chrono_literal) {
  using namespace std::literals;
  auto t = 1ms;
  bool is_same_type = std::is_same<std::chrono::milliseconds, decltype(t)>::value;
  EXPECT_TRUE(is_same_type);
}

TEST(LITERAL_TEST, raw_literal) {
  auto string_block = R"( 
    it is like python's """ raw string inside """
    )";
  EXPECT_EQ(56, strlen(string_block));
}

TEST(LITERAL_TEST, string_literal) {
  using namespace std::literals;
  auto s = "string"s;
  bool is_same_type = std::is_same<std::string, decltype(s)>::value;
  EXPECT_TRUE(is_same_type);
}

/**
 * Convert light_speed literal to m/s, e.g. 0.8_c means 0.8 * c m/s
 */
constexpr long double operator"" _c(long double light_speed) {
  return light_speed * 299'792'458;
}

TEST(LITERAL_TEST, user_defined) {
  // user defined literal
  auto ls = 0.8_c;
  long double ans = 0.8 * 299'792'458.0;
  EXPECT_DOUBLE_EQ(ans, ls);
}

TEST(LITERAL_TEST, utf8_literal) {
  // utf8 literal
  std::string u8str(u8"☃");
  EXPECT_EQ(u8"\u2603", u8str);
}


