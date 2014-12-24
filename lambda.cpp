#include <type_traits>
#include "gtest/gtest.h"

// 'using' instead of typedef
using voidfunc = void (*)();

/**
 * Testing the feature of a basic lambda function.
 * Every instance of a lambda defines a new type.
 * For non-capturing lambda, it can be casted into a
 * function pointer implicitly.
 */
TEST(LAMBDA_TEST, func_type) {
  voidfunc empty_lambda_func = [](){}; // implicit casting here.
  auto lambda_func = [](){};
  bool is_same = std::is_same<voidfunc, decltype(lambda_func)>::value;
  EXPECT_FALSE(is_same);
  is_same = std::is_same<voidfunc, decltype(empty_lambda_func)>::value;
  EXPECT_TRUE(is_same);
}

/**
 * Testing the feature of generic lambda function.
 * Look at the argument, it's an 'auto'.
 */
TEST(LAMBDA_TEST, generic_lambda) {
  auto getsize = []( auto const& c ) { return c.size(); };
  std::vector<int> v {1,2,3};
  EXPECT_EQ(3, getsize(v));
}
