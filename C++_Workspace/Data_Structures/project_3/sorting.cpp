#include <iostream>
#include "quicksort.h"
#include "heapsort.h"
#include "insertsort.h"
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

int main() {
    std::cout << "Sorting Program\n";
    std::cout << "Please enter the name of a file: ";
    std::string filename; 
    std::cin >> filename;
    std::ifstream file(filename);
    srand(time(NULL));

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
    
    int seed = rand() % 100 + 1;

    for(int i = 0; i < elements; ++i) {
        ascending.push_back(seed + i);
        random.push_back(rand() % (seed * seed) + 1);
        descending.push_back(seed * seed - (i + i));
    }

    std::cout << "Vectors loaded. Proceeding with sorts:\n";

    // insertion Sort

    std::cout << "====== Insertion Sort ======\n";
    
    std::cout << "Ascending vector before insertion sort: "
    for(int x : ascending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::vector<int> insertCopy = ascending;
    insertionSort(insertCopy);
    
    std::cout << "Ascending vector after insertion sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Descending vector before insertion sort: "
    for(int x : descending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = descending;
    insertionSort(insertCopy);
    
    std::cout << "Descending vector after insertion sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Random vector before insertion sort: "
    for(int x : random) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = random;
    insertionSort(insertCopy);
    
    std::cout << "Random vector after insertion sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // merge sort

    std::cout << "====== Merge Sort ======\n";
    
    std::cout << "Ascending vector before merge sort: "
    for(int x : ascending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = ascending;
    mergeSort(insertCopy);
    
    std::cout << "Ascending vector after merge sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Descending vector before merge sort: "
    for(int x : descending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::vector<int> insertCopy = descending;
    mergeSort(insertCopy);
    
    std::cout << "Descending vector after merge sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Random vector before merge sort: "
    for(int x : random) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = random;
    mergeSort(insertCopy);
    
    std::cout << "Random vector after merge sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // heap sort

    std::cout << "====== Heap Sort ======\n";
    
    std::cout << "Ascending vector before heap sort: "
    for(int x : ascending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = ascending;
    heapSort(insertCopy);
    
    std::cout << "Ascending vector after heap sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Descending vector before heap sort: "
    for(int x : descending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::vector<int> insertCopy = descending;
    heapSort(insertCopy);
    
    std::cout << "Descending vector after heap sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Random vector before heap sort: "
    for(int x : random) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = random;
    heapSort(insertCopy);
    
    std::cout << "Random vector after heap sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // quick sort

    std::cout << "====== Quick Sort ======\n";
    
    std::cout << "Ascending vector before quick sort: "
    for(int x : ascending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = ascending;
    quickSort(insertCopy);
    
    std::cout << "Ascending vector after quick sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Descending vector before quick sort: "
    for(int x : descending) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    std::vector<int> insertCopy = descending;
    quickSort(insertCopy);
    
    std::cout << "Descending vector after quick sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Random vector before quick sort: "
    for(int x : random) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    insertCopy = random;
    quickSort(insertCopy);
    
    std::cout << "Random vector after quick sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
