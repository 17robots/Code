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

bool contains(std::list<int> & list1, int y) {
	for(auto x : list1) {
		if(x == y) {
			return true;
		}
	}
	return false;
}

bool connComponent(const std::list<int>& com1, const std::list<int>& com2) {
  if(com1.size() > com2.size()) {
  	for(auto x : com2) {
  		if(contains(com1, x)) {
  			return true;
  		}
  	}
  	return false;
  } else {
  	for(auto x : com1) {
  		if(contains(com2, x)) {
  			return true;
  		}
  	}
  	return false;
  }
}

bool merge(std::list<int> & list1, std::list<int> & list2) {
	if(list1.size() > list2.size()) {
		for(auto x : list2) {
			list1.insert(gt(list1.begin(), list1.end(), x), x);
		}
		return true;
	} else {
		for(auto x : list1) {
			list2.insert(gt(list2.begin(), list2.end(), x), x);
		}
		return false;
	}
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
	std::string responseString;
	do {
		std::cout << "Enter two list ids to potentially merge together or -1 to quit: ";
		//if(responseString != "") { std::getline(std::cin, responseString); } // if the responseString has data, clear it out and ask again
		std::getline(std::cin, responseString);
		
		if(responseString == "-1") { break; } // break the loop immediately
		
		// create the string stream to pull the ints from
		std::stringstream stream(responseString);
		
		int list1, list2;
		
		// exception handling in case input is not as desired
		stream >> list1 >> list2;
		if(stream.fail()) {
			std::cout << "Invalid parameters please try again" << std::endl;
			responseString = "repeat"; // force the loop to repeat
			continue;
		}
		
		// check to see if the lists are mergable
		if(connComponent(graphList[list1], graphList[list2])) {
			std::cout << "These two can be merged. Merging...\n";
			if(merge(graphList[list1], graphList[list2])) {
				graphList.erase(graphList.begin() + list2);
				responseString = "repeat";
			} else {
				graphList.erase(graphList.begin() + list1);
				responseString = "repeat";
			}
		} else {
			std::cout << "These two lists could not be merged: no common index between the two.\n";
			responseString = "repeat";
			continue;
		}
		
	} while(responseString != "-1");

	// final printout logic
	


   return 0;
}
