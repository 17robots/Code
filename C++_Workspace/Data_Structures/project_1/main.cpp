#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::list<int>::iterator gt(std::list<int>::iterator start, std::list<int>::iterator stop, int x) {
	while(start != stop && *start < x) {
		++start;
	}
	return start;
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
		std::list<int> addMe;
		std::stringstream stream(line);
		while(stream) {
			int n; // the number to be read
			stream >> n;
			addMe.insert(gt(addMe.begin(), addMe.end(), n), n);
		}	
		graphList.push_back(addMe);
	}

	std::cout << "List read. Printing Adjacency List:\n";

	printAdjList(graphList);

	// logic for menu loop interface for the merging of lists
	

	// final printout logic
	


   return 0;
}
