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
        return strArr == nullptr;
    }
    
    std::size_t myStringVector::length() const {
        return lastElem == strArr ? 0 : lastElem - strArr;
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
    
    void myStringVector::reserve(int) {
        
    }
    
    void myStringVector::resize(int) {
        
    }
    
    void myStringVector::clear() {
        
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
    
    bool myStringVector::operator!=(myStringVector const &obj) const {
        return !(*(this) == obj);
    }
    
    bool myStringVector::operator < (myStringVector const &obj) const {
        
    }
    
    bool myStringVector::operator > (myStringVector const &obj) const {
        
    }
    
    bool myStringVector::operator <= (myStringVector const &obj) const {
        
    }
    
    bool myStringVector::operator >= (myStringVector const &obj) const {
        
    }
    
    std::string myStringVector::operator [] (int index) const {
        
    }
    
    myStringVector::~myStringVector() {
        delete[] strArr;
        strArr = nullptr;
        maxElem = nullptr;
        lastElem = nullptr;
    }
    
    std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string> myStringVector::begin() {
        /*if(strArr != nullptr) {
            return std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string>(strArr[0]);
        }*/
    }
    
    std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string> myStringVector::end() {
        /*if(strArr != nullptr) {
            return return std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string>(lastElem);
        }*/
    }
    
}