#include <iostream>
#include "myString.hpp"

namespace umm {
  myString::myString() {
	stringArray = new char[0]; // create an array of 0 charcters
	lastChar = stringArray;
	maxChar = lastChar + 1;
  }

  myString::myString(char const * str) {
	// grab the length of str
	int counter = 0;
	while(str[counter] != '\0') {
	  counter++;
	}
	// should have the length of str now
	
	stringArray = new char[counter + 1]; // create a char array of str size
	for(int i = 0; i < counter + 1; ++i) {
	  stringArray[i] = str[i]; // set the char
	}
	lastChar = stringArray + counter;
	maxChar = lastChar + 1;
  }

  myString::myString(const myString &obj) {
	stringArray = obj.getStringArray();
	lastChar = obj.getLastChar();
	maxChar = obj.getMaxChar();
  }

  myString::~myString() {
	// delete everything 
	delete [] stringArray;
	delete lastChar;
	delete maxChar;
  }

  int myString::length()const {
	return lastChar == stringArray ? 0 : maxChar - stringArray;
	//return lastChar - stringArray;
  }

  myString & umm::myString::operator=(const myString &obj) {
	if(this == &obj) {
	  return *this;
	}

	stringArray = new char(obj.length());
	lastChar = stringArray;

	for(int i = 0; i < obj.length(); i++) {
	  stringArray[i] = obj.getStringArray()[i];  
	}

	lastChar = stringArray + obj.length() - 1; 

	maxChar = lastChar + 1;

	return *this;
  }

  char * umm::myString::getStringArray() const {
	return stringArray;
  } 

  char * umm::myString::getLastChar() const {
	return lastChar;
  }

  char * umm::myString::getMaxChar() const {
	return maxChar;
  } 

  bool umm::myString::empty() const {
	return lastChar == stringArray;
  }

  std::ostream & operator<<(std::ostream &os, const umm::myString &obj) {
	for(int i = 0; i < obj.length(); ++i) {
	  os << obj.getStringArray()[i];
	}
	return os;
  }
  
  char & umm::myString::operator[](int index) {
  	if(index > maxChar - stringArray) {
  		std::cout << "index out of range" << std::endl;
  	} else {
  		return stringArray[index];
  	}
  }
  
  int umm::myString::find(char charToFind) const {
      for(int i = 0; i < maxChar - stringArray; ++i) {
          if(stringArray[i] == charToFind) {
              return i;
          }
      }
      
      return -1;
  }
}
