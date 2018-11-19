#include <iostream>
#include "myStringVector.hpp"
#include <string>
#include <algorithm>
#include <cassert>
#include <initializer_list>

using namespace umm2;

namespace
{

template<typename I1, typename I2>
inline bool
my_equal(I1 first1, I1 limit1, I2 first2, I2 limit2)
{
  while (first1 != limit1 && first2 != limit2) {
    if (*first1 != *first2) {
        return false;   
    }
    ++first1;
    ++first2;
  }
  return first1 == limit1 && first2 == limit2;
}

}

int main() {
    myStringVector v {"a", "b", "c"};
    myStringVector const& cv = v;
    using I = myStringVector::iterator;
    using C = myStringVector::const_iterator;
    I first1 = v.begin(), limit1 = v.end();
    C first2 = cv.begin(), limit2 = cv.end();
    assert(my_equal(first1, limit1, first2, limit2));
    return 0;
}