#include <iostream>
#include "container.h"

using namespace std;

void range_base_for() {
  // range-based for and list initialization
  cout << "\033[1;32m==== range-based for ====\033[0m" << endl; 
  int integers[] = {1, 2, 3, 4, 5};
  for (auto &i : integers) {
    cout << "element: " << i << endl;    
  }
}

void non_member_begin_end() {
  cout << "\033[1;32m==== non-member begin/end ====\033[0m" << endl; 
  // non-member begin/end
  const char *names[] {"foo", "bar", "google"};
  auto it = find_if(begin(names), end(names), [](const char* s) { return strlen(s) > 4; });
  if (it != end(names)) {
    cout << *it << endl;
  }
}

void container() {
  range_base_for();
  non_member_begin_end();
}