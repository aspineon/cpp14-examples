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

TEST(LITERAL_TEST, utf8_literal) {
  // utf8 literal
  std::string u8str(u8"☃");
  EXPECT_EQ(u8"\u2603", u8str);
}


