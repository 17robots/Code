// Matthew Dray
// String Vector Header File


#ifndef MYSTRINGVECTOR_HPP
#define MYSTRINGVECTOR_HPP
#include <iostream>
#include <algorithm>
#include <string>
#include <initializer_list>

namespace umm2 {
    class myStringVector {
      public:
        // iterator class definitions
        class iterator;
        iterator begin();
        iterator end();
        
        class iterator {
          public:
              iterator() {};
              std::string operator*() { return *lit; }
              iterator& operator++() { ++lit; }
              bool operator ==(iterator & obj) {return (lit == obj.lit);}
              bool operator !=(iterator & obj) {return (lit != obj.lit);}
              friend class myStringVector;
          private:
              std::string* lit;
        };
    
        class const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
        
        class const_iterator
        {
          public:
              const_iterator() {};
              const_iterator(iterator it) : lit(it.lit) { }
              std::string operator*() const { return *lit; }
              const_iterator& operator++() { ++lit; }
              bool operator ==(const_iterator & obj) {return (lit == obj.lit);}
              bool operator !=(const_iterator & obj) {return (lit != obj.lit);}
              friend class myStringVector;
          private:
              std::string * lit;
        };
        
        // constructors
        myStringVector();
        myStringVector(std::initializer_list<std::string>);
        myStringVector(const myStringVector &obj);
        myStringVector & operator=(const myStringVector &obj);
        
        //pre none
        //pos returns whether or not the vector has stuff in it
        bool empty() const;
        
        //pre none
        //pos returns the number of total elements in the vector
        std::size_t length() const;
        
        //pre none 
        //pos returns how many items can be added to the vector
        std::size_t capacity() const;
        
        //pre none
        //pos returns strArr
        std::string * data() const;
        
        //pre none
        //pos returns the last element in the vector
        std::string * last() const;
        
        //pre none
        //pos returns the max element in the vector
        std::string * max() const;
        
        //pre int is declared properly 
        //pos grows the vector's capacity by the specified value
        void reserve(int);
        
        //pre int is properly declared
        //pos sets the vector to have int elements, filling in "" if necessary
        void resize(int);
        
        //pre none
        //pos deletes the members in the vector while keeping the capacity the same
        void clear();
        
        //pre std::string is initialized properly
        //pos adds an element to the end and adjusts the length and capacity accordingly 
        void push_back(std::string value);
        
        //pre none
        //pos removes the last element of the array and adjusts accordingly
        void pop_back();
        
        // overloads
        bool operator==(myStringVector const &obj) const;
        bool operator!=(myStringVector const &obj) const;
        bool operator < (myStringVector const &obj) const;
        bool operator > (myStringVector const &obj) const;
        bool operator <= (myStringVector const &obj) const;
        bool operator >= (myStringVector const &obj) const;
        
        //pre index is in the bounds of the vector
        //pos returns the string* at a given index
        std::string & operator [] (int index) const;
        
        // destructor
        ~myStringVector();
      private:
        std::string * strArr;
        std::string * lastElem;
        std::string * maxElem;
    };
}

#endif
