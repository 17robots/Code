#ifndef MYSTRING_HPP
#define MYSTRING_HPP

// lets define things
namespace umm {
  class myString {
  	public:
	  myString(); // default construtor 
	  myString(char const * str); // the string constructor
	  myString(const myString &obj); // the copy constructor
	  ~myString(); // deconstructor
	  myString & operator=(const myString &obj); // operator override
	  char * getStringArray();
	private:
	  // we will need to create a char array that is stored on the heap so that
	  // we can allocate more space as necessary.
	  char * stringArray;
	  char * lastChar; // the last char of the string
	  char * maxChar; // the last char of the string + 1
  };
}

#endif
