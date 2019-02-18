#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::list<int>::iterator gt(std::list<int>::iterator start, std::list<int>::iterator stop, int x) {
    std::list<int>::iterator test = start;
    return test;
		// implement this later
}

void swap(int i,int j, std::vector<int>& a){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(std::vector<int>& a, int i, int j) {
	int pivot = a[j];    // pivot 
    int lowerIndex = (i - 1);  // Index of smaller element 
  
    for (int k = i; k <= j - 1; ++k) { 
        // If current element is smaller than or 
        // equal to pivot 
        if (a[k] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(lowerIndex, k, a); 
        } 
    } 
    swap(lowerIndex + 1, j, a); 
    return (lowerIndex + 1); 
}

void sort(std::vector<int>& sortThis, int lower, int upper) {
	if (lower < upper) 
    { 
        /* pi is partitioning index, sortThis[pi] is now 
           at right place */
        int pi = partition(sortThis, lower, upper); 
  
        // Separately sort elements before 
        // partition and after partition 
        sort(sortThis, lower, pi - 1); 
        sort(sortThis, pi + 1, upper); 
    } 
}

void printAdjList(std::vector<std::list<int>>& adjList) {
	for( auto x : adjList ) {
		for(auto y : x) {
			std::cout << y << " ";
		}
		std::cout << "\n";
	}
}

bool connComponent(const std::list<int> & com1, const std::list<int> & com2) {
  return true;
	// implement this later
}

bool merge(std::list<int> & list1, std::list<int> & list2) {
  return true;
	// implement this later
}

int main(int argc, char* argv[], char* envp[]) {
	std::vector<std::list<int>> graphList;
	std::string filename;
	std::cout << "Graph Adjacency List\n";
	if(argc == 1) { // if the command does not have any arguments
		std::cout << "Please enter the name of the graph file: ";
		std::cin >> filename;
	} else {
		filename = std::string(argv[0]);
	}

	std::ifstream graphFile;
	graphFile.open(filename);

	while(!graphFile) { // while we do not have the correct file name
		std::cout << "Error opening file - File name not found.\n";
		std::cout << "Please enter another file name: ";
		std::cin >> filename;
		graphFile.close();
		graphFile.open(filename);
	}

	// now start reading and making the adjacency lists
	std::string line;
	int counter = 0;
	while(std::getline(graphFile, line)) {
		std::vector<int> sortMe;
		std::stringstream stream(line);
		while(stream) {
			int n; // the number to be read
			stream >> n;
			sortMe.push_back(n);
		}
		sort(sortMe, 0, sortMe.size() - 1);
		graphList.push_back(std::list<int>({ std::begin(sortMe), std::end(sortMe) })); // copy the sorted vector as a list into the graphList vector
		++counter; // next index
	}

	std::cout << "List read. Printing Adjacency List:\n";

	printAdjList(graphList);

	// logic for menu loop interface for the merging of lists
	

	// final printout logic
	


   return 0;
}
