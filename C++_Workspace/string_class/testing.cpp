#include "myString.hpp"
#include <cstring>
#include <iosfwd>
#include <string>
#include <iostream>
#include <cassert>

using namespace umm;

int main() {
  umm::myString s1 = "abc";
  umm::myString s2 = "def";
  umm::myString s3 = s1 + s2;
  umm::myString s4 = "abcdef";
  s4 += s3;
  
  std::cout << s4 << std::endl;
  // assert(s3 == s4);

  
  return 0;
}
