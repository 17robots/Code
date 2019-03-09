#include "empmaps.h"
#include <string>
#include <fstream>
#include <sstream>

std::vector<Employee> employees() {
	std::cout << "====== EMPLOYEE MAPPING PROGRAM ======\n";
	std::string filename;
	std::cout << "Please enter the name of a file: ";
	std::cin >> filename;
	std::ifstream empFile;
	empFile.open(filename);
	
	while(!empFile) { // while file does not exist
		std::cout << "Error when trying to open file: file does not exist or invalid name.\n";
		std::cout << "Please enter a different file name: ";
		std::cin >> filename;
		empFile.close(); // close the old file
		empFile.open(filename); // try to open the new one
	}
	
	// begin reading in the file
	std::string line;
	std::vector<Employee> emplist;
	int employeeCount = 0;
	while(std::getline(empFile, line)) { // while lines can be grabbed from the file
		std::stringstream stream(line);
		while(stream) {
			int id, sal;
			std::string name;
			stream >> id >> name >> sal; // read all of the employee information
			emplist.push_back(Employee(id, name, sal));
			++employeeCount;
		}
	}	
	std::cout << employeeCount << " employees loaded in from " << filename << "\n\n";
	return emplist;
}

std::map<int,std::vector<Employee>> mapEmpDept(std::vector<Employee>& emp) {
	std::map<int,std::vector<Employee>> returnedMap;
	// go through every employee
	for (auto const& x : emp) {
		if(returnedMap.find(x.id()/100) == returnedMap.end()) { // if the department does not exist
			returnedMap[x.id()/100] = std::vector<Employee>(); // create the department
			returnedMap[x.id()/100].push_back(x); // add the employee to that department
		} else { // the department does exist
			returnedMap[x.id()/100].push_back(x);
		}
	}
	return returnedMap;
}

std::map<int,std::vector<Employee>> mapSalRange(std::vector<Employee>& emp) {
	std::map<int,std::vector<Employee>> returnedMap;
	// go through every employee
	for(auto const& x : emp) {
		int range = (x.sal()/10000) * 10000;
		if(returnedMap.find(range) == returnedMap.end()) {
			returnedMap[range] = std::vector<Employee>();
			returnedMap[range].push_back(x);
		} else {
			returnedMap[range].push_back(x);	
		}
	}
	return returnedMap;
}

void printSalRange(std::map<int,std::vector<Employee>>& salRange) {
	std::cout << "Number of Salary Ranges: " << salRange.size() << '\n';
	for(auto const& x : salRange) {
		std::cout << "ORDERED Map Salary Range " << x.first << " contains " << x.second.size() << '\n';
	}
}

std::unordered_map<int,std::vector<Employee>> umapEmpDept(std::vector<Employee>& emp) {
	std::unordered_map<int,std::vector<Employee>> returnedMap;
	// go through every employee
	for (auto const& x : emp) {
		if(returnedMap.find(x.id()/100) == returnedMap.end()) { // if the department does not exist
			returnedMap[x.id()/100] = std::vector<Employee>(); // create the department
			returnedMap[x.id()/100].push_back(x); // add the employee to that department
		} else { // the department does exist
			returnedMap[x.id()/100].push_back(x);
		}
	}
	return returnedMap;
}

std::unordered_map<int,std::vector<Employee>> umapSalRange(std::vector<Employee>& emp) {
	std::unordered_map<int,std::vector<Employee>> returnedMap;
	// go through every employee
	for(auto const& x : emp) {
		int range = (x.sal()/10000) * 10000;
		if(returnedMap.find(range) == returnedMap.end()) {
			returnedMap[range] = std::vector<Employee>();
			returnedMap[range].push_back(x);
		} else {
			returnedMap[range].push_back(x);
		}	
	}
	return returnedMap;
}

void uprintSalRange(std::unordered_map<int,std::vector<Employee>>& salRange) {
	std::cout << "Number of Salary Ranges: " << salRange.size() << '\n';
	for(auto const& x : salRange) {
		std::cout << "UNORDERED Map Salary Range " << x.first << " contains " << x.second.size() << '\n';
	}	
}


