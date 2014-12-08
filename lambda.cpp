#include <type_traits>
#include "gtest/gtest.h"

// 'using' instead of typedef
using voidfunc = void (*)();

TEST(LAMBDA_TEST, func_type) {
  voidfunc empty_lambda_func = [](){}; // implicit casting here.
  bool is_same = std::is_same<voidfunc, decltype(empty_lambda_func)>::value;
  EXPECT_TRUE(is_same);
}