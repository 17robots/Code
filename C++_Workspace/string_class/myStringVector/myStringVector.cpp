// Matthew Dray
// string vector implementations

#include "myStringVector.hpp"

namespace umm2 {
    myStringVector::myStringVector() {
        strArr = nullptr;
        lastElem = nullptr;
        maxElem = nullptr;
    }
    
    myStringVector::myStringVector(std::initializer_list<std::string> strings) {
        int counter = 0;
        strArr = new std::string[strings.end() - strings.begin()];
        for(std::initializer_list<std::string>::iterator i = strings.begin(); i != strings.end(); ++i) {
            strArr[i - strings.begin()] = *i;
            lastElem = strArr + (i - strings.begin());
            maxElem = lastElem + 1;
        }
    }
    
    myStringVector::myStringVector(const myStringVector &obj) {
        std::cout << "calling copy constructor" << std::endl;
        strArr = obj.data();
        lastElem = obj.last();
        maxElem = obj.max();
    }
    
    myStringVector & myStringVector::operator=(const myStringVector &obj) {
        if(this == &obj) {
		  return *this;
		}
		
		// reassign the stringArray
		strArr = new std::string[obj.length()];
		
		for(int i = 0; i < obj.length(); i++) {
		  strArr[i] = obj.data()[i]; // set it to the new string
		}
	
		// shift everything
		lastElem = strArr + obj.length() - 1; 
	
		maxElem = lastElem + 1;
	
		return *this;
    }
    
    bool myStringVector::empty() const {
        return this->length() == 0;
    }
    
    std::size_t myStringVector::length() const {
        return (((lastElem == strArr && !strArr) || (strArr[0] == "" && lastElem == strArr)) ? 0 : lastElem - strArr + 1);
    }
    
    std::size_t myStringVector::capacity() const {
        return maxElem - strArr;
    }
    
    std::string * myStringVector::data() const {
        return strArr;
    }
    
    std::string * myStringVector::last() const {
        return lastElem;
    }
    
    std::string * myStringVector::max() const {
        return maxElem;
    }
    
    void myStringVector::reserve(int reservedSize) {
        std::string * newArr = new std::string[this->length() + reservedSize];
        for(int i = 0; i < this->length(); ++i) {
            newArr[i] = strArr[i];
        }
        
        int length = this->length();
        int capacity = this->capacity();
        delete [] strArr;
        strArr = newArr;
        lastElem = strArr + length;
        maxElem = strArr + capacity + reservedSize;
    }
    
    void myStringVector::resize(int finalSize) {
        std::string * newArr = new std::string[finalSize];
        int capacity = this->capacity();
        
        for(int i = 0; i < finalSize; ++i) {
            if(i >= this->length() || !strArr) {
                newArr[i] = "";
            } else {
                newArr[i] = strArr[i];
            }
        }
        
        delete [] strArr;
        strArr = newArr;
        lastElem = strArr + finalSize - 1;
        if(capacity < finalSize) {
            maxElem = lastElem + 1;
        } else {
            maxElem = strArr + capacity;
        }
    }
    
    void myStringVector::clear() {
        int capacity = this->capacity();
        delete [] strArr;
        strArr = new std::string[capacity];
        lastElem = strArr;
        maxElem = strArr + capacity;
    }
    
    bool myStringVector::operator==(myStringVector const &obj) const {
        if(this->length() == obj.length()) {
            for(int i = 0; i < obj.length(); ++i) {
                if(strArr[i] != obj.data()[i]) {
                    return false;
                }
            }
        } else {
            return false;
        }
        return true;
    }
    
    void myStringVector::push_back(std::string value) {
        
        std::string * newArr = new std::string[this->length() + 1];
        for(int i = 0; i < this->length(); ++i) {
            newArr[i] = strArr[i];
        }
        
        newArr[this->length()] = value;
        int length = this->length();
        int capacity = this->capacity();
        delete [] strArr;
        strArr = newArr;
        lastElem = strArr + length;
        maxElem = strArr + capacity;
    }
    
    void myStringVector::pop_back() {
        if(this->empty()) {
            std::cout << "The vector is empty" << std::endl;
        } else {
            std::string * newArr = new std::string[this->length() - 2];
            
            for(int i = 0; i < this->length() - 2; ++i) {
                newArr[i] = strArr[i];
            }
            int length = this->length() - 2; // this accounts for the length function returning 1 more than the index and the lack of last one
            int capacity = this->capacity();
            delete [] strArr;
            strArr = newArr;
            lastElem = strArr + length;
            maxElem = strArr + capacity;   
        }
        
    }
    
    bool myStringVector::operator!=(myStringVector const &obj) const {
        return !(*(this) == obj);
    }
    
    bool myStringVector::operator < (myStringVector const &obj) const {
        if(this->length() > obj.length()) {
            return false;
        } else if(this->length() < obj.length()) {
            return true;
        } else {
            for(int i = 0; i < this->length(); ++i) {
                if(strArr[i] >= obj.data()[i]) {
                    return false;
                }
            }
            
            return true;
        }
    }
    
    bool myStringVector::operator > (myStringVector const &obj) const {
        if(this->length() < obj.length()) {
            return false;
        } else if(this->length() > obj.length()) {
            return true;
        } else {
            for(int i = 0; i < this->length(); ++i) {
                if(strArr[i] <= obj.data()[i]) {
                    return false;
                }
            }
            
            return true;
        }
    }
    
    bool myStringVector::operator <= (myStringVector const &obj) const {
        if(this->length() > obj.length()) {
            return false;
        } else if(this->length() < obj.length()) {
            return true;
        } else {
            for(int i = 0; i < this->length(); ++i) {
                if(strArr[i] > obj.data()[i]) {
                    return false;
                }
            }
            
            return true;
        }
    }
    
    bool myStringVector::operator >= (myStringVector const &obj) const {
        if(this->length() < obj.length()) {
            return false;
        } else if(this->length() > obj.length()) {
            return true;
        } else {
            for(int i = 0; i < this->length(); ++i) {
                if(strArr[i] < obj.data()[i]) {
                    return false;
                }
            }
            
            return true;
        }
    }
    
    std::string & myStringVector::operator [] (int index) const {
        if(index >= this->length() || index < 0) {
            std::cout << "The index is out of bounds. Returning last character instead" << std::endl;
            return strArr[lastElem - strArr];
        } else {
            return strArr[index];
        }
    }
    
    myStringVector::~myStringVector() {
        delete [] strArr;
        maxElem = NULL;
        lastElem = NULL;
        strArr = NULL;
    }
    
    myStringVector::iterator myStringVector::begin() {
        iterator citer;
        citer.lit = strArr;
        return citer;
    }
    
    myStringVector::iterator myStringVector::end() {
        iterator citer;
        citer.lit = lastElem;
        return citer;
    }
    
    myStringVector::const_iterator myStringVector::begin() const {
        const_iterator citer;
        citer.lit = strArr;
        return citer;
    }
    
    myStringVector::const_iterator myStringVector::end() const {
        const_iterator citer;
        citer.lit = lastElem;
        return citer;
    }
    
}