#include "empmaps.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>

/*
Filename: empdriver.cpp
Author: Matthew Dray
Purpose: Run the program and control input and output for the program
*/

void employee(std::vector<Employee>& emplist) {
	std::cout << "============ Creating Maps ============\n\n";
	clock_t start, stop;

	std::cout << "Creating unordered department map\n";	
	start = clock();
	std::unordered_map<int,std::vector<Employee>> udepMap = umapEmpDept(emplist);
	stop = clock();
	std::cout << "Created Unordered Department Map\n";
	std::cout << "Operation took " << stop-start << " clock ticks or " << static_cast<double>((stop-start)/(CLOCKS_PER_SEC/1000.0)) << " ms\n\n";

	
	std::cout << "Creating Ordered Department Map\n";
	start = clock();
	std::map<int,std::vector<Employee>> depMap = mapEmpDept(emplist);
	stop = clock();
	std::cout << "Created Ordered Department Map\n";
	std::cout << "Operation took " << stop-start << " clock ticks or " << static_cast<double>((stop-start)/(CLOCKS_PER_SEC/1000.0)) << " ms\n\n";

	std::cout << "Creating Unordered Salary Map\n";
	start = clock();
	std::unordered_map<int,std::vector<Employee>> usalMap = umapSalRange(emplist);
	stop = clock();
	std::cout << "Created Unordered Salary Map\n";
	std::cout << "Operation took " << stop-start << " clock ticks or " << static_cast<double>((stop-start)/(CLOCKS_PER_SEC/1000.0)) << " ms\n\n";

	std::cout << "Creating Ordered Salary Map\n";
	start = clock();
	std::map<int,std::vector<Employee>> salMap = mapSalRange(emplist);
	stop = clock();
	std::cout << "Created Ordered Salary Map\n";
	std::cout << "Operation took " << stop-start << " clock ticks or " << static_cast<double>((stop-start)/(CLOCKS_PER_SEC/1000.0)) << " ms\n\n";

	std::cout << "=======================================\n\n";
	std::cout << "========== Printing elements ==========\n\n";
	
	std::cout << "Printing Unordered Salary Range\n";
	start = clock();
	uprintSalRange(usalMap);
	stop = clock();
	std::cout << "Printed Unordered Salary Range\n";
	std::cout << "Operation took " << stop-start << " clock ticks or " << static_cast<double>((stop-start)/(CLOCKS_PER_SEC/1000.0)) << " ms\n\n";
	
	std::cout << "Printing Ordered Salary Range\n";
	start = clock();
	printSalRange(salMap);
	stop = clock();
	std::cout << "Printed Unordered Salary Range\n";
	std::cout << "Operation took " << stop-start << " clock ticks or " << static_cast<double>((stop-start)/(CLOCKS_PER_SEC/1000.0)) << " ms\n\n";
	std::cout << "=======================================\n";
}

int main() {
	std::vector<Employee> people = employees();
	employee(people);
	return 0;
}

