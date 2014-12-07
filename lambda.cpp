#include <iostream>
#include "lambda.h"

using namespace std;

// 'using' instead of typedef
using voidfunc = void (*)();

void lambda() {
  voidfunc empty_lambda_func = [](){};
  cout << "\033[1;32m==== lambda func ====\033[0m" << endl;
  cout << "calling lambda func..." << endl;
  empty_lambda_func();
}