#include <iostream>
#include "type_inference.h"

using namespace std;

// trailing return type.
template<typename T, typename U>
auto product(const T &t, const U &u) -> decltype(t * u) {
  return t * u;
}

// return type deduction 
decltype(auto) trailing_return() {
  cout << "product:" << product(1.0, 5L) << endl;
}

void type_inference() {
  cout << "\033[1;32m==== trailing return ====\033[0m" << endl; 
  trailing_return();
}