#include "myString.hpp"
#include <cstring>
#include <iosfwd>
#include <string>
#include <iostream>
#include <cassert>

int main() {
  umm::myString s;
  char const * str = "hello world"; 
  umm::myString yes = str;
  assert(yes.getStringArray() != str);
  assert(strcmp(yes.getStringArray(), str) == 0);
  std::cout << yes << std::endl; 
  // std::cout << yes.length();
  s = yes;
  // std::cout << s.length();
  umm::myString const s1;
  assert(s1.empty());

  umm::myString const s2 = "";
  assert(s2.empty());
  return 0;
}
