#ifndef MYSTRINGVECTOR_HPP
#define MYSTRINGVECTOR_HPP
#include <iostream>
#include <algorithm>
#include <string>
#include <initializer_list>

namespace umm2 {
    class myStringVector {
      public:
        myStringVector();
        myStringVector(std::initializer_list<std::string>);
        myStringVector(const myStringVector &obj);
        myStringVector & operator=(const myStringVector &obj);
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
        static std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string> iterator;
        static std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string> const_iterator;
        std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string> begin();
        std::iterator<std::random_access_iterator_tag, std::string, std::string, const std::string *, std::string> end();
      private:
      std::string * strArr;
      std::string * lastElem;
      std::string * maxElem;
    };
}

#endif
