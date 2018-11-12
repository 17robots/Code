#include <iostream>
#include "myStringVector.hpp"
#include <string>
#include <algorithm>
#include <cassert>
#include <initializer_list>

using namespace umm2;

int main() {
    myStringVector v1 {"a", "b", "c"};
    myStringVector v2 = v1;
    return 0;
}