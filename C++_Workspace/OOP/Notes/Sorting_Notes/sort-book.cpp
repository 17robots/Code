#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

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

bool operator<(book const& a, book const& b) {
    if(a.author < b.author)
        return true;
    if(b.author < a.author)
        return false;
    if(a.year < b.year)
        return true;
    if(b.year < a.year)
        return false;
    if(a.title < b.title)
        return true;
    if(b.title < a.title)
        return false;
}

using comparison = std::function<bool(book const&, book const&)>();


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
        std::iter_swap(first, iter);
    }
}

bool less(book const& a, book const& b) {
    return a < b;
}

bool greater(book const& a, book const& b) {
    return !(a < b);
}

void print(std::vector<book> const& v) {
    for(book b : v) {
        std::cout << b << " ";
    }
}

int main() {
    std::vector<book> sortMe = {
        {"The Great Gatsby", "Fitzgerald", "1935"},
        {"The Lord of the rings", "Tolkein", "1965"},
        {"1984", "Orwell", "1948"},
        {"Dune", "Herbert", "1962"} 
    };
    comparison func;
    print(sortMe);
    insertion_sort(sortMe.data(), sortMe.data() + sortMe.size(), comparison(func));
    print(sortMe);
    insertion_sort(sortMe.data(), sortMe.data() + sortMe.size(),comparisonFunc);
    print(sortMe);
    return 0;
}