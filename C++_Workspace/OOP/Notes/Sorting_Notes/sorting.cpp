#include <vector>
#include <algorithm>
#include <iostream>

void insertion_sort(int* first, int* last, bool min) {
    while(first != last) {
        if(min)
            int* iter = std::min_element(first, last);
        else
            int* iter = std::max_element(first, last);
        std::iter_swap(first, min);
    }
}

void print(std::vector<int> const& v) {
    for(int n : v) {
        std::cout << v << " ";
    }
}

int main() {
    std::vector<int> sortMe = {3, 8 ,16, 100, -12, 14, 186, 72};
    print(sortMe);
    insertion_sort(sortMe.data(), sortMe.data() + sortMe.size(), true);
    print(sortMe);
    insertion_sort(sortMe.data(), sortMe.data() + sortMe.size(), false);
    print(sortMe);
    return 0;
}