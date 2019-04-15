#include <iostream>
#include "quicksort.h"
#include "heapsort.h"
#include "insertsort.h"
#include "mergesort.h"
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

int main() {
    clock_t start, stop;
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
    
    int elements;
    
    std::cin >> elements;
    
    while(std::cin.fail()) {
        std::cout << "Please enter a number: ";
        std::cin >> elements;
    }
    
    // create 3 vectors
    std::vector<int> ascending;
    std::vector<int> descending;
    std::vector<int> random;
    
    int seed = rand() % 100 + 1;

    for(int i = 0; i < elements; ++i) {
        ascending.push_back(seed + i);
        random.push_back(rand() % (seed * seed) + 1);
        descending.push_back(seed * seed - (i + i));
    }

    std::cout << "Vectors loaded. Proceeding with sorts:\n\n";

    // insertion Sort
    std::cout << "====== Insertion Sort ======\n";
    std::cout << "File vector before insertion sort: ";
    for(int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    std::vector<int> insertCopy = numbers;
    insertionSort(insertCopy);
    
    std::cout << "File vector after insertion sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "Sorting Ascending Vector\n";
    insertCopy = ascending;
    start = clock();
    insertionSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Descending Vector\n";
    insertCopy = descending;
    start = clock();
    insertionSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Random Vector\n";
    insertCopy = random;
    start = clock();
    insertionSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "====================";
    std::cout << "\n\n";

    // merge sort
    std::cout << "====== Merge Sort ======\n";
    std::cout << "File vector before merge sort: ";
    for(int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    insertCopy = numbers;
    mergeSort(insertCopy);
    
    std::cout << "File vector after merge sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "Sorting Ascending Vector\n";
    insertCopy = ascending;
    start = clock();
    mergeSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0<< std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Descending Vector\n";
    insertCopy = descending;
    start = clock();
    mergeSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Random Vector\n";
    insertCopy = random;
    start = clock();
    mergeSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "===================";
    std::cout << "\n\n";

    // heap sort
    std::cout << "====== Heap Sort ======\n";
    
    std::cout << "File vector before heap sort: ";
    for(int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    insertCopy = numbers;
    heapSort(insertCopy);
    
    std::cout << "File vector after heap sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "Sorting Ascending Vector\n";
    insertCopy = ascending;
    start = clock();
    heapSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Descending Vector\n";
    insertCopy = descending;
    start = clock();
    heapSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Random Vector\n";
    insertCopy = random;
    start = clock();
    heapSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "====================";
    std::cout << "\n\n";

    // quick sort

    std::cout << "====== Quick Sort ======\n";
    
    std::cout << "File vector before quick sort: ";
    for(int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    insertCopy = numbers;
    quickSort(insertCopy);
    
    std::cout << "File vector after quick sort: ";
    for(int x : insertCopy) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "Sorting Ascending Vector\n";
    insertCopy = ascending;
    start = clock();
    quickSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Descending Vector\n";
    insertCopy = descending;
    start = clock();
    quickSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "\n\n";

    std::cout << "Sorting Random Vector\n";
    insertCopy = random;
    start = clock();
    quickSort(insertCopy);
    stop = clock();
    std::cout << "Sort Runtime: " << double(stop - start) / 1000.0 << std::endl;
    std::cout << "====================";
    std::cout << "\n\n";

    return 0;
}
