#include <iostream>
#include "myString.hpp"

namespace umm {
  myString::myString() {
	stringArray = NULL;
	lastChar = NULL;
	maxChar = NULL;
  }

  myString::myString(char const * str) {
		// grab the length of str
		int counter = 0;
		while(str[counter] != '\0') {
		  counter++;
		}
		
		stringArray = new char[counter]; // create a char array of str size
		for(int i = 0; i < counter; i++) {
		  stringArray[i] = str[i]; // set the char
		}
		
		lastChar = stringArray + counter - 1;
		maxChar = lastChar + 1;
		
		// std::cout << "lastChar - stringArray: " << lastChar - stringArray << std::endl;
  }

  myString::myString(const myString &obj) {
		stringArray = obj.data();
		lastChar = obj.getLastChar();
		maxChar = obj.getMaxChar();
  }

  myString::~myString() {
		// delete everything
		// delete maxChar;
		// delete lastChar;
		delete [] stringArray;
		
		//set it all to null
		lastChar = NULL;
		maxChar = NULL;
		stringArray = NULL;
  }

  int myString::length() const {
		return lastChar == stringArray ? 0 : maxChar - stringArray;
  }

  myString & umm::myString::operator=(const myString &obj) {
		if(this == &obj) {
		  return *this;
		}
	
		stringArray = new char(obj.length());
		lastChar = stringArray;
	
		for(int i = 0; i < obj.length(); i++) {
		  stringArray[i] = obj.data()[i];  
		}
	
		lastChar = stringArray + obj.length() - 1; 
	
		maxChar = lastChar + 1;
	
		return *this;
  }

  char * umm::myString::data() const {
		return stringArray;
  } 

  char * umm::myString::getLastChar() const {
		return lastChar;
  }

  char * umm::myString::getMaxChar() const {
		return maxChar;
  } 

  bool umm::myString::empty() const {
		return lastChar - stringArray == 0;
  }

  std::ostream & operator<<(std::ostream &os, const umm::myString &obj) {
		for(int i = 0; i < obj.length(); ++i) {
		  os << obj.data()[i];
		}
		return os;
  }
  
  char & umm::myString::operator[](int index) const {
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
  
  char * umm::myString::substr(int first, int last) const{
  	if(first < 0 && last > maxChar - stringArray) {
  		std::cout << "First index is too small and the second index is too big. Returning original string" << std::endl;
  		return stringArray;
  	} else if(first < 0 && last < 0) {
  		std::cout << "Both indexes are too small. Returning original string." << std::endl;
  		return stringArray;
  	} else if(first > maxChar - stringArray && last > maxChar - stringArray) {
  		std::cout << "Both indexes are greater than the string length. Returning original array." << std::endl;
  		return stringArray;
  	} else if(first < 0) {
  		std::cout << "First index is too small. Starting from the 0th index" << std::endl;
  		char * returnedArr = new char[last];
  		for(int i = 0; i < last; ++i) {
  			returnedArr[i] = stringArray[i];
  		}
  		return returnedArr;
  	} else if(last > maxChar - stringArray) {
  		std::cout << "Second index is too big. Ending at the last character in the string." << std::endl;
  		char * returnedArr = new char[(maxChar - stringArray) - first];
  		for(int i = 0; i < (maxChar - stringArray) - first + 1; ++i) {
  			returnedArr[i] = stringArray[first + i];
  		}
  		return returnedArr;
  	} else {
  		char * returnedArr = new char[last - first];
  		for(int i = 0; i < last - first; ++i) {
  			returnedArr[i] = stringArray[first + i];
  		}
  		return returnedArr;
  	}
  }
  
  bool umm::myString::operator==(const umm::myString &obj) const {
  	if(this->length() == obj.length()) {
  		for(int i = 0; i < obj.length(); ++i) {
  			if(stringArray[i] != obj.data()[i]) {
  				return false;
  			}
  		}	
  		return true;
  	}
  	
  	return false;
	}
	
	bool umm::myString::operator==(const char * obj) const {
		int counter = 0;
		while(obj[counter] != '\0') {
		  counter++;
		}
		
  	if(this->length() == counter) {
  		for(int i = 0; i < counter; ++i) {
  			if(stringArray[i] != obj[i]) {
  				return false;
  			}
  		}	
  		return true;
  	}
  	
  	return false;
	}
	
	bool umm::myString::operator!=(const umm::myString &obj) const {
		return !(*(this) == obj);
	}
  
  bool umm::myString::operator!=(const char * obj) const {
  	return !(*(this) == obj);
  }
  
  bool umm::myString::operator<(const myString& lhs) const {
  	for(int i = 0; i < lhs.length(); ++i) {
			if(!(stringArray[i] < lhs.data()[i])) {
				return false;
			}
		}
		return true;
  }
  
  bool umm::myString::operator<(const char * lhs) const {
  	int counter = 0;
		while(lhs[counter] != '\0') {
		  counter++;
		}
		
		for(int i = 0; i < counter; ++i) {
			if(!(stringArray[i] < lhs[i])) {
				return false;
			}
		}
		return true;
  }
  
  bool umm::myString::operator>(const myString& lhs) const {
  	for(int i = 0; i < lhs.length(); ++i) {
			if(!(stringArray[i] > lhs.data()[i])) {
				return false;
			}
		}
		return true;
  }
  
  bool umm::myString::operator>(const char * lhs) const {
  	int counter = 0;
		while(lhs[counter] != '\0') {
		  counter++;
		}
		
		for(int i = 0; i < counter; ++i) {
			if(!(stringArray[i] > lhs[i])) {
				return false;
			}
		}
		return true;
  }
  
  
  bool umm::myString::operator<=(const myString& lhs) const {return (*this < lhs || *this == lhs);}
  bool umm::myString::operator<=(const char * lhs) const {return (*this < lhs || *this == lhs);}
  bool umm::myString::operator>=(const myString& lhs) const {return (*this > lhs || *this == lhs);}
  bool umm::myString::operator>=(const char * lhs) const {return (*this > lhs || *this == lhs);}
  
  umm::myString umm::myString::operator+(const myString& obj) {
  	char * combinedArray = new char[this->length() + obj.length()];
  	
  	// add in the original string's value
  	for(int i = 0; i < this->length(); ++i) {
  		combinedArray[i] = stringArray[i];
  	}
  	
  	for(int i = 0; i < obj.length(); ++i) {
  		combinedArray[i + this->length()] = obj.data()[i];
  	}
  	
  	return myString(combinedArray);
  	
  	// std::cout << "calling the += stuff" << std::endl;
  	// *this += obj;
  	// return *this;
  }
  
  umm::myString& umm::myString::operator+=(const myString& obj) {
  	int tmp = this->length();
  	char * combinedArray = new char[this->length() + obj.length()];
  	
  	// add in the original string's value
  	for(int i = 0; i < this->length(); ++i) {
  		combinedArray[i] = stringArray[i];
  	}
  	
  	for(int i = 0; i < obj.length(); ++i) {
  		combinedArray[i + this->length()] = obj.data()[i];
  	}
  	
  	delete [] stringArray;
  	stringArray = new char[tmp + obj.length()];
  	for(int i = 0; i < tmp + obj.length(); i++) {
  		stringArray[i] = combinedArray[i];
  	}
  	
  	lastChar = stringArray + this->length() + obj.length() - 1;
  	maxChar = lastChar + 1;
  	
  	return *this;
  }
}
