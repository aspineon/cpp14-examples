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
 * 'auto' type deduction with pointer type
 */
TEST(AUTO_TEST, auto_with_pointer_test) {
  const int i = 1;
  const int* pi = &i;

  auto pa = pi;
  EXPECT_TRUE((std::is_same<const int*, decltype(pa)>::value));

  const auto cpa = pi;
  EXPECT_TRUE((std::is_same<const int *const, decltype(cpa)>::value));

  // Declare auto& doesn't guarantee that the variable is not a pointer.
  auto& ra = pi;
  EXPECT_TRUE((std::is_same<const int *&, decltype(ra)>::value));
  EXPECT_EQ(1, *ra);

  const auto& cra = pi;
  EXPECT_TRUE((std::is_same<const int *const &, decltype(cra)>::value));
  EXPECT_EQ(1, *cra);

  auto* ppa = pi;
  EXPECT_TRUE((std::is_same<const int*, decltype(ppa)>::value));

  const auto* cppa = pi;
  EXPECT_TRUE((std::is_same<const int*, decltype(cppa)>::value));
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

/**
 * List initializer has no type and is treated specially by auto type deduction
 * N3922 the behavior may have change with or without '='
 * This is also the only rule that is different from template type deduction.
 */
TEST(AUTO_TEST, initializer_list_test) {
  auto a = { 1, 2, 3 };
  EXPECT_TRUE((std::is_same<std::initializer_list<int>, decltype(a)>::value));
  auto b = { 1.0, 2.0, 3.0 };
  EXPECT_TRUE((std::is_same<std::initializer_list<double>, decltype(b)>::value));
  auto c = { "foo", "bar" };
  EXPECT_TRUE((std::is_same<std::initializer_list<const char *>, decltype(c)>::value));
}

// a dummy function
void foo() {
  return;
}

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
