#ifndef MYSTRING_H
#define MYSTRING_H

umm::myString::myString() {
  stringArray = new char[0]; // create an array of 0 charcters
  lastChar = stringArr[0];
  maxChar = lastChar + 1;
}

umm::myString::myString(char const * str) {
  stringArray = new char[sizeof(str)/sizeof(char)]; // create a char array of str size
  for(int i = 0; i < sizeof(str)/sizeof(char); ++i) {
	*(stringArray[i]) = *(str[i]); // set the char
  }
  lastChar = stringArray[sizeof(str)/(sizeof(char)];
  maxChar = lastChar + 1;
}

umm::myString::myString(const myString &obj) {
  stringArray = new char[]
  *stringArray = *obj.stringArray;
}

umm::myString::~myString() {
  // delete everything
  for(int i = maxChar - stringArray[0]; i >= 0 ; --i) {
	delete myString[i];
  }
  
  delete myString;
  delete lastChar;
  delete maxChar;
}

umm::myString & umm::myString::operator=(const myString &obj) {
  if(this == &obj) {
	return *this;
  }

  stringArray = obj.getStringArray();
  return *this;
}

char * umm::myString::getStringArray() {
  return stringArray;
}
