#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cassert>

struct book {
    std::string title;
    std::string author;
    std::string year;
};

std::ostream& operator<<(std::ostream& os, book const& b) {
    os << "Title: " << b.title << '\n';
    os << "Author: " << b.author << '\n';
    os << "Year: " << b.year << '\n';
    os << "----------\n";
    return os;
}

using comparison = std::function<bool(book const&, book const&)>;


// first class function - passing function as parameter to another function
// insertion_sort is a higher order function
//
// instead of a flag, we can use a function to compare the values
//
// post condition
// is_sorted(first, last, comp) && 
// is permuation of original
//
// new precondition is harder to define
// axiom is_range(first, last)
//
// what is required  for comp
//
// one must be true:
// a < b
// b < a
// !(a < b) && !(b < a)
// comp(a,b)
// comp(b,a)
// !comp(a,b) && !comp(b,a)

void insertion_sort(book* first, book* last, comparison comp) {
    while(first != last) {
        book* iter = std::min_element(first, last, comp);
        std::iter_swap(first++, iter);
    }
}

void print(std::vector<book> const& v) {
    for(book b : v)
        std::cout << b << " ";
}

book* my_min_element(book* first, book* last, comparison& op) {
    assert(first != last);
    book* min = first++;
    for(; first!=last; ++first)
        if(op(*first, *last))
            min = first;
}

int main() {
    std::vector<book> sortMe = {
        {"The Great Gatsby", "Fitzgerald", "1935"},
        {"The Lord of the rings", "Tolkein", "1965"},
        {"1984", "Orwell", "1948"},
        {"Dune", "Herbert", "1962"}
    };

    book* first = sortMe.data();
    book* last = first + sortMe.size();
    
    bool asc = false;
    insertion_sort(sortMe.data(), sortMe.data() + sortMe.size(), [asc](book const& a, book const& b) {
        if(asc)
            return a.year < b.year;
        else
            return b.year < a.year;
    });

    print(sortMe);
    return 0;
}