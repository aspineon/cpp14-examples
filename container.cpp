#include <iostream>
#include <vector>
#include "container.h"

void range_base_for() {
  // range-based for and list initialization
  std::cout << "\033[1;32m==== range-based for ====\033[0m" << std::endl; 
  int integers[] = {1, 2, 3, 4, 5};
  for (auto &i : integers) {
    std::cout << "element: " << i << std::endl;    
  }
}

void non_member_begin_end() {
  std::cout << "\033[1;32m==== non-member begin/end ====\033[0m" << std::endl; 
  // non-member begin/end
  const char *names[] {"foo", "bar", "google"};
  auto it = std::find_if(std::begin(names), std::end(names), [](const char* s) { return strlen(s) > 4; });
  if (it != std::end(names)) {
    std::cout << *it << std::endl;
  }
}

void all_not_null() {
  std::cout << "\033[1;32m==== all_of ====\033[0m" << std::endl;

  // also a demo of unique_ptr and emplace_back
  std::vector<std::unique_ptr<int>> v;
  v.emplace_back(new int);
  v.emplace_back(new int);
  auto not_null = std::all_of(
    v.cbegin(),
    v.cbegin(),
    [](const std::unique_ptr<int>& ptr) { return ptr != nullptr; });
  if (not_null) {
    std::cout << "all elements of vector v are not nullptr." << std::endl;
  }

  v[0] = nullptr;
  not_null = std::all_of(
    v.cbegin(),
    v.cbegin(),
    [](const std::unique_ptr<int>& ptr) { return ptr != nullptr; });
  assert(!not_null)
}

void container() {
  range_base_for();
  non_member_begin_end();
  all_not_null();
}