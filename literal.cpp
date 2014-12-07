#include <iostream>
#include "literal.h"

void binary_literal() {
  std::cout << "\033[1;32m==== binary literal ====\033[0m" << std::endl; 
  // binary literal
  int binary = 0b1001;
  std::cout << "binary 0b1001 = " << binary << std::endl;
}

void utf8_literal() {
  // utf8 literal
  std::cout << "\033[1;32m==== utf8 literal ====\033[0m" << std::endl; 
  char test[] = u8"two snowmen: ☃\u2603";
  std::cout << test << std::endl;
}

void raw_literal() {
  std::cout << "\033[1;32m==== raw string literal ====\033[0m" << std::endl; 
  std::cout << R"( 
    it is like python's """ raw string inside """
    )" << std::endl;
}

void literal() {
  binary_literal();
  raw_literal();
  utf8_literal();
}