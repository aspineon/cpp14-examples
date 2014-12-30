#include "gtest/gtest.h"

/**
 * 'auto' would ignore 'const' and 'reference' in type deduction
 */
TEST(AUTO_TEST, auto_type_test) {
  const int i = 1;
  const int& ri = i;
  auto a = i;
  auto ra = ri;
  EXPECT_TRUE((std::is_same<int, decltype(a)>::value));
  EXPECT_TRUE((std::is_same<int, decltype(ra)>::value));
}

/**
 * 'auto' type deduction with const and/or reference
 */
TEST(AUTO_TEST, auto_with_const_ref) {
  const int i = 1;
  const int& ri = i;

  const auto a = i;
  const auto& ra = ri;
  auto& no_const = ri;

  EXPECT_TRUE((std::is_same<const int, decltype(a)>::value));
  EXPECT_TRUE((std::is_same<const int&, decltype(ra)>::value));
  EXPECT_TRUE((std::is_same<const int&, decltype(no_const)>::value));
}

/**
 * 'auto&&' means lvalue or rvalue, aka universal reference.
 * && in the context of type deduction means rvalue or lvalue.
 */
TEST(AUTO_TEST, universal_ref) {
  int i = 1;
  int& ri = i;

  auto&& lvalue = 1;
  auto&& rvalue = ri;
  // auto& rvalue = 1; // compile error

  EXPECT_TRUE((std::is_same<int&&, decltype(lvalue)>::value));
  EXPECT_TRUE((std::is_same<int&, decltype(rvalue)>::value));
}

/**
 * Test if 'auto' deduce to pointer for array
 */
TEST(AUTO_TEST, auto_array) {
  int v[] = { 1,2,3,4,5 };

  // int array 'decays' into int pointer
  auto a = v;
  EXPECT_TRUE((std::is_same<int*, decltype(a)>::value));

  // with auto&, it's a different story.
  // but it doesn't affect semantics in most cases.
  auto& ra = v;
  EXPECT_TRUE((std::is_same<int (&)[5], decltype(ra)>::value));
}

// a dummy function
void foo() {
  return;
}

template<typename T>
class TD;

/**
 * Test if 'auto' decude to function pointer for function.
 */
TEST(AUTO_TEST, auto_func) {
  // function 'decays' into function pointer
  auto f = foo;
  EXPECT_TRUE((std::is_same<void (*)(), decltype(f)>::value));

  // with auto&, it's a different story.
  // it is deducing function reference type.
  auto& rf = foo;
  EXPECT_TRUE((std::is_same<void (&)(), decltype(rf)>::value));
}

/**
 * 'decltype(auto)' preseves 'const' and 'reference' in type deduction.
 */
TEST(AUTO_TEST, decltype_auto) {
  const int i = 1;
  const int& ri = i;
  decltype(auto) a = i;
  decltype(auto) ra = ri;
  EXPECT_TRUE((std::is_same<const int, decltype(a)>::value));
  EXPECT_TRUE((std::is_same<const int&, decltype(ra)>::value));
}
