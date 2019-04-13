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
    
    std::vector<int> numbers;
    std::string line;
    
    while(getline(file, line)) {
        std::istringstream sstream(line);
        int number;
        sstream >> number;
        numbers.push_back(number);
    }

    std::cout << "File vector loaded. Please enter a number of elements to generate: ";
    
    int elememts;
    
    std::cin >> elememnts;
    
    while(cin.fail()) {
        std::cout << "Please enter a number: ";
        std::cin >> elements;
    }
    
    // create 3 vectors
    std::vector<int> ascending;
    std::vector<int> descending;
    std::vectot<int> random;
    
    for(int i = 0; i < elements; ++i) {
        
    }

    return 0;
}
