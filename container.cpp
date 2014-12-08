#include <vector>
#include "gtest/gtest.h"

/**
 * Test using range-based for loop.
 */
TEST(CONTAINER_TEST, range_base_for)
{
  // range-based for and list initialization
  int integers[] = {1, 2, 3, 4, 5};
  auto sum = 0;
  for (auto &i : integers) {
    sum += i;
  }
  EXPECT_EQ(15, sum);
}

/**
 * Test using non-member begin/end
 */
TEST(CONTAINER_TEST, non_member_begin_end)
{
  // non-member begin/end
  const char *names[] {"foo", "bar", "google", "tien"};
  auto it = std::find_if(
    std::begin(names),
    std::end(names),
    [](const char* s) { return strlen(s) > 4; });
  // assert found
  EXPECT_NE(std::end(names), it);
  EXPECT_EQ("google", *it);
}

/**
 * Test using std::all_of
 */
TEST(CONTAINER_TEST, all_of) {
  std::vector<int> v {0,2,4,6};
  auto all_even = std::all_of(
    v.cbegin(),
    v.cend(),
    [](const int& ptr) { return ptr % 2 == 0; });

  EXPECT_TRUE(all_even);
  v.push_back(7);
  
  all_even = std::all_of(
    v.cbegin(),
    v.cend(),
    [](const int& ptr) { return ptr % 2 == 0; });
  EXPECT_FALSE(all_even);
}
