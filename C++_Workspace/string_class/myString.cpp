#include <iostream>
#include "myString.hpp"

namespace umm {
   myString::myString() {
    stringArray = new char[0]; // create an array of 0 charcters
    lastChar = stringArray;
    maxChar = lastChar + 1;
  }
  
  myString::myString(char const * str) {
    stringArray = new char[sizeof(str)/sizeof(char)]; // create a char array of str size
    for(int i = 0; i < sizeof(str)/sizeof(char); ++i) {
  	  stringArray[i] = str[i]; // set the char
    }
    lastChar = stringArray + (sizeof(str)/(sizeof(char)));
    maxChar = lastChar + 1;
  }
  
  myString::myString(const myString &obj) {
    *stringArray = *obj.stringArray;
  }
  
  myString::~myString() {
    // delete everything
    for(int i = maxChar - stringArray; i >= 0 ; --i) {
  	  delete myString[i];
    }
    
    delete myString;
    delete lastChar;
    delete maxChar;
  }
  
  myString & umm::myString::operator=(const myString &obj) {
    if(this == &obj) {
  	return *this;
    }
  
    stringArray = obj.getStringArray();
    return *this;
  }
  
  char * umm::myString::getStringArray() {
    return stringArray;
  } 
}
