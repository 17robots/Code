#include <iostream>
#include "quicksort.h"
#include "heapsort.h"
#include "insertsort.h"
#include <string>
#include <fstream>
#include <sstream>

int main() {
    std::cout << "Sorting Program\n";
    std::cout << "Please enter the name of a file: ";
    std::string filename; 
    std::cin >> filename;
    std::ifstream file(filename);

    if(!file) {
        std::cerr << "File not found.";
        return 1;
    }
    std::istringstream sstream(file);

    std::cout << "File loaded. Please enter a number of elements: " << 

    return 0;
}
