#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>

// lets define things
namespace umm {
  struct myString {
	  myString(); // default construtor
	  myString(char const * str); // the string constructor
	  myString(const myString &obj); // the copy constructor
	  ~myString(); // deconstructor
	  
	  // precondition: none
	  // postcondition: returns the physical length of the string
	  std::size_t length() const;
	  
	  // precondition: obj is properly initialized 
	  // postcondition: sets the current myString to obj
	  myString & operator=(const myString &obj); // operator override
	  
	  // precondition: none
	  // postcondition: returns the stringArray char array
	  char * data() const;
	  
	  // precondition: none
	  // postcondition: returns the lastChar pointer
	  char * getLastChar() const;
	  
	  // precondition: none
	  // postcondition: returns the maxChar pointer
	  char * getMaxChar() const;
	  
	  // precondition: none
	  // postcondition: returns whether or not there are characters in the string
	  bool empty() const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: puts out the contents of obj to the buffer for console output
	  friend std::ostream & operator <<(std::ostream& os, const umm::myString &obj);
	  
	  // precondition: index is within the bounds of stringArray
	  // postcondition: returns the character in stringArray at index
	  char &operator[](int index) const;
	  
	  // precondition: char is properly initialized
	  // postcondition: returns the index of the first occurance of charToFind or -1
	  int find(char charToFind) const;
	  
	  static const std::size_t npos = -1;
	  
	  // precondition: first and last are within the bounds of stringArray
	  // postcondition: returns a character array containing the characters from first to last
	  char * substr(int first, int last) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not the stringArrays of obj and this are equal
	  bool operator==(const umm::myString &obj) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not the stringArray of this is equal to obj
	  bool operator==(const char * obj) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not the stringArrays of obj and this are equal
	  bool operator!=(const umm::myString &obj) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not the stringArray of this is equal to obj
	  bool operator!=(const char * obj) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is < lhs' stringArray
	  bool operator< (const myString& lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is < than lhs
	  bool operator< (const char * lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is > lhs' stringArray
	  bool operator> (const myString& lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is > than lhs
	  bool operator> (const char * lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is <= lhs' stringArray
	  bool operator<= (const myString& lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is <= than lhs
	  bool operator<= (const char * lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is >= lhs' stringArray
	  bool operator>= (const myString& lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns whether or not this stringArray is >= than lhs
	  bool operator>= (const char * lhs) const;
	  
	  // precondition: obj is properly initialized
	  // postcondition: returns a myString with the two stringArrays added together
	  myString operator+(const myString& obj);
	  
	  // precondition: obj is properly initialized
	  // postcondition: sets this stringArray to the stringArray + obj's stringArray
	  myString & operator+=(const myString& obj);

	  // we will need to create a char array that is stored on the heap so that
	  // we can allocate more space as necessary.
	  char * stringArray;
	  char * lastChar; // the last char of the string
	  char * maxChar; // the last char of the string + 1
  };
  
  // precondition: obj is properly initialized
  // postcondition: puts out the contents of obj to the buffer for console output
  std::ostream &operator<<(std::ostream &os, const umm::myString &obj);
}

#endif
