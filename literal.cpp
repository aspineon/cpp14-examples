#include "gtest/gtest.h"

TEST(LITERAL_TEST, binary_literal) {
  // binary literal
  int binary = 0b1001;
  EXPECT_EQ(9, binary);
}

TEST(LITERAL_TEST, utf8_literal) {
  // utf8 literal
  std::string u8str(u8"☃");
  EXPECT_EQ(u8"\u2603", u8str);
}

TEST(LITERAL_TEST, raw_literal) {
  auto string_block = R"( 
    it is like python's """ raw string inside """
    )";
  EXPECT_EQ(56, strlen(string_block));
}

