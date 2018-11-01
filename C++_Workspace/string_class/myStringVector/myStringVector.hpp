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
        ~myStringVector();
      private:
      std::string * strArr;
      std::string * lastElem;
      std::string * maxElem;
    };
}

#endif
