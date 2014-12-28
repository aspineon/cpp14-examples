#include "gtest/gtest.h"

/**
 * std::ref<T> returns std::reference_wrapper<T>
 */
TEST(REF, ref_test) {
  // reference_wrapper is copy constructiable and copy assignable
  EXPECT_TRUE((std::is_copy_assignable<std::reference_wrapper<int>>::value));
  EXPECT_TRUE((std::is_copy_constructible<std::reference_wrapper<int>>::value));

  // std::vector<int&> v is an illegal declaration.
  int a = 1;
  int b = 2;
  std::vector<std::reference_wrapper<int>> v = {std::ref(a), std::ref(b)};
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(2, v[1]);
  // 'a' modified, so does v[0]
  a = 3;
  EXPECT_EQ(3, v[0]);

  // v[0] modified, so does a
  v[0].get() = 5;
  EXPECT_EQ(5, a);
}

/**
 * A "Null" pointer object that overwrites '&' operator.
 */
struct Null {
  void* operator&() { return nullptr; }
};

/**
 * Show the difference of '&' and std::addressof
 */
TEST(REF, addressof) {
  Null n;
  EXPECT_EQ(nullptr, &n);
  EXPECT_NE(nullptr, std::addressof(n));
}