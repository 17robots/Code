#include <iostream>
#include "myStringVector.hpp"
#include <string>
#include <algorithm>
#include <cassert>
#include <initializer_list>

using namespace umm2;

int main() {
    myStringVector v1 {"a", "b", "c"};
    std::cout << &v1 << std::endl;
    myStringVector v2 = v1;
    // std::cout << &v2; > <- this also doesn't print when uncommented because of the seg fault issue.
    // assert(v1 == v2);
    return 0;
}