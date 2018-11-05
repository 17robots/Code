#ifndef MYSTRINGVECTOR_HPP
#define MYSTRINGVECTOR_HPP
#include <iostream>
#include <string>

namespace {
    class myStringVector {
      public:
        myStringVector();
        myStringVector(const myStringVector &obj);
        bool empty() const;
        std::size_t length() const;
        std::size_t capacity() const;
        std::string * data() const;
        std::string * last() const;
        std::string * max() const;
        void reserve(int);
        void resize(int);
        void clear();
        bool operator==(myStringVector const &obj) const;
        bool operator!=(myStringVector const &obj) const;
        bool operator < (myStringVector const &obj) const;
        bool operator > (myStringVector const &obj) const;
        bool operator <= (myStringVector const &obj) const;
        bool operator >= (myStringVector const &obj) const;
        std::string operator [] (int index) const;
        ~myStringVector();
        
        static class iterator : std::iterator {
            public:
                explicit iterator(std::string Value = "") : value(Value) {};
                reference operator*() const;
                iterator& operator++();
                bool operator ==(iterator &other) const;
                bool operator !=(iterator &other) const;
        };
        
        static class const_iterator : std::iterator {
            public:
                explicit const_iterator(std::string Value = "") : value(Value) {};
                reference operator*() const;
                iterator& operator++();
                bool operator ==(iterator &other) const;
                bool operator !=(iterator &other) const;
        };
        iterator begin();
        iterator end();
      private:
      std::string * strArr;
      std::string * lastElem;
      std::string * maxElem;
    };
}

#endif
