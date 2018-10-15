#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>

// lets define things
namespace umm {
  class myString {
	public:
	  myString(); // default construtor 
	  myString(char const * str); // the string constructor
	  myString(const myString &obj); // the copy constructor
	  ~myString(); // deconstructor
	  int length() const;
	  myString & operator=(const myString &obj); // operator override
	  char * data() const;
	  char * getLastChar() const;
	  char * getMaxChar() const;
	  bool empty() const;
	  friend std::ostream & operator <<(std::ostream& os, const umm::myString &obj);
	  char &operator[](int index) const;
	  int find(char charToFind) const;
	  static const std::size_t npos = -1;
	  char * substr(int first, int last) const;
	  bool operator==(const umm::myString &obj) const;
	  bool operator==(const char * obj) const;
	  bool operator!=(const umm::myString &obj) const;
	  bool operator!=(const char * obj) const;
	  bool operator< (const myString& lhs) const;
	  bool operator< (const char * lhs) const;
	  bool operator> (const myString& lhs) const;
	  bool operator> (const char * lhs) const;
	  bool operator<= (const myString& lhs) const;
	  bool operator<= (const char * lhs) const;
	  bool operator>= (const myString& lhs) const;
	  bool operator>= (const char * lhs) const;
	  myString operator+(const myString& obj);
	  myString & operator+=(const myString& obj);
	private:
	  // we will need to create a char array that is stored on the heap so that
	  // we can allocate more space as necessary.
	  char * stringArray;
	  char * lastChar; // the last char of the string
	  char * maxChar; // the last char of the string + 1
  };

  std::ostream &operator<<(std::ostream &os, const umm::myString &obj);
}

#endif
