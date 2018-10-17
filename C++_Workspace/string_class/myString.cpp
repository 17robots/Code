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
  }

  myString::myString(const myString &obj) {
  	// copy...everything
		stringArray = obj.data();
		lastChar = obj.getLastChar();
		maxChar = obj.getMaxChar();
  }

  myString::~myString() {
		// delete the array
		delete [] stringArray;
		
		//set it all to null
		lastChar = NULL;
		maxChar = NULL;
		stringArray = NULL;
  }

  std::size_t myString::length() const {
  	// if lastChar is at the beginning of the string, it's empty, or, we need to return the max number to account for the being one off
		return lastChar == stringArray ? 0 : maxChar - stringArray;
  }

  myString & umm::myString::operator=(const myString &obj) {
		if(this == &obj) {
		  return *this;
		}
		
		// reassign the stringArray
		stringArray = new char(obj.length());
		
		for(int i = 0; i < obj.length(); i++) {
		  stringArray[i] = obj.data()[i]; // set it to the new string
		}
	
		// shift everything
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
  	// if the physical length is 0, it's empty
		return maxChar - stringArray == 0;
  }
  
  char & umm::myString::operator[](int index) const {
  	if(index > maxChar - stringArray) {
  		std::cout << "index out of range" << std::endl;
  	} else {
  		return stringArray[index];
  	}
  }
  
  int umm::myString::find(char charToFind) const {
  		// we only want to return the first occurance of the char
      for(int i = 0; i < maxChar - stringArray; ++i) {
          if(stringArray[i] == charToFind) {
              return i; // hey we found it 
          }
      }
      
      return -1; // nope we didn't
  }
  
  char * umm::myString::substr(int first, int last) const{
  	// the bulk of this function is to make it less prone to mistakes and issues with user error
  	
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
  	if(this->length() == obj.length()) { // if the strings lengths aren't equal, don't continue
  		for(int i = 0; i < obj.length(); ++i) {
  			if(stringArray[i] != obj.data()[i]) {
  				return false; // nope not equal
  			}
  		}	
  		return true; // yeah everything is equal
  	}
  	
  	return false; // for when the string lengths aren't equal
	}
	
	bool umm::myString::operator==(const char * obj) const {
		// grabbing the char length for obj
		int counter = 0;
		while(obj[counter] != '\0') {
		  counter++;
		}
		
		// same thing with size checking
  	if(this->length() == counter) {
  		for(int i = 0; i < counter; ++i) {
  			if(stringArray[i] != obj[i]) {
  				return false; // nope not equal
  			}
  		}	
  		return true; // equal
  	}
  	
  	return false; // sizes are different - not equal
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
				return false; // not < 
			}
		}
		return true; // < is true
  }
  
  bool umm::myString::operator<(const char * lhs) const {
  	// we always seem to need to grab the length of the char
  	int counter = 0;
		while(lhs[counter] != '\0') {
		  counter++;
		}
		
		for(int i = 0; i < counter; ++i) {
			if(!(stringArray[i] < lhs[i])) {
				return false; // not <
			}
		}
		return true; // <
  }
  
  bool umm::myString::operator>(const myString& lhs) const {
  	for(int i = 0; i < lhs.length(); ++i) {
			if(!(stringArray[i] > lhs.data()[i])) {
				return false; // not >
			}
		}
		return true; // >
  }
  
  bool umm::myString::operator>(const char * lhs) const {
  	// grabbing char length.....again
  	int counter = 0;
		while(lhs[counter] != '\0') {
		  counter++;
		}
		
		for(int i = 0; i < counter; ++i) {
			if(!(stringArray[i] > lhs[i])) {
				return false; // not >
			}
		}
		return true; // >
  }
  
  // basically, I can build the rest of the comparison operators and their overloads with what has already been created, so let's do that 
  bool umm::myString::operator<=(const myString& lhs) const {return (*this < lhs || *this == lhs);}
  bool umm::myString::operator<=(const char * lhs) const {return (*this < lhs || *this == lhs);}
  bool umm::myString::operator>=(const myString& lhs) const {return (*this > lhs || *this == lhs);}
  bool umm::myString::operator>=(const char * lhs) const {return (*this > lhs || *this == lhs);}
  
  
  umm::myString umm::myString::operator+(const myString& obj) {
  	char * combinedArray = new char[this->length() + obj.length()]; // the new array that will be set
  	
  	// add in the original string's value
  	for(int i = 0; i < this->length(); ++i) {
  		combinedArray[i] = stringArray[i];
  	}
  	
  	for(int i = 0; i < obj.length(); ++i) {
  		combinedArray[i + this->length()] = obj.data()[i];
  	}
  	
  	return myString(combinedArray);
  }
  
  umm::myString& umm::myString::operator+=(const myString& obj) {
  	int tmp = this->length(); // we will need this later for looping through
  	
  	char * combinedArray = new char[this->length() + obj.length()]; // the new string to assign
  	
  	// add in the original string's value
  	for(int i = 0; i < this->length(); ++i) {
  		combinedArray[i] = stringArray[i];
  	}
  	
  	for(int i = 0; i < obj.length(); ++i) {
  		combinedArray[i + this->length()] = obj.data()[i];
  	}
  	
  	delete [] stringArray;
  	stringArray = new char[tmp + obj.length()]; // here's where we need the tmp variable - after we delete the stringArray
  	for(int i = 0; i < tmp + obj.length(); i++) {
  		stringArray[i] = combinedArray[i];
  	}
  	
  	lastChar = stringArray + this->length() + obj.length() - 1;
  	maxChar = lastChar + 1;
  	
  	return *this;
  }
  
  std::ostream & operator<<(std::ostream &os, const umm::myString &obj) {
		for(int i = 0; i < obj.length(); ++i) {
		  os << obj.data()[i]; // add each character to the output stream
		}
		return os;
  }
}
