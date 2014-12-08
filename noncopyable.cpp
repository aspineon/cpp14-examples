#include "gtest/gtest.h"

TEST(NONCOPYABLE, by_delete_keyword) {
  class noncopyable_string {
   public:
    noncopyable_string() = default;
    noncopyable_string(const char *str) : s(str) {}
    noncopyable_string(const noncopyable_string&) = delete;
    noncopyable_string &operator=(const noncopyable_string&) = delete;
    size_t len() { return s.length(); }
   private:
    std::string s;
  };

  noncopyable_string s1;
  noncopyable_string s2("string");

  EXPECT_EQ(0, s1.len());
  EXPECT_EQ(6, s2.len());

  // The following statements will have compile errors
  // noncopyable_string s3(s2);
  // s1 = s2;
}