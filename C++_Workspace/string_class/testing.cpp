#include "myString.hpp"
#include <cstring>
#include <iosfwd>
#include <string>
#include <iostream>
#include <cassert>

using namespace umm;

int main() {
  umm::myString s1 = "hello world"; 
   s1[0] = 'a';
   std::cout << s1 << std::endl;
   assert(s1[0] == 'a');
  return 0;
}
