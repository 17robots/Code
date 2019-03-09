#include <vector>
#include "Employee.h"
#include <map>
#include <unordered_map>

#ifndef EMPMAPS_H
#define EMPMAPS_H

std::vector<Employee> employees();

std::map<int,std::vector<Employee>> mapEmpDept(std::vector<Employee>& emp);
std::map<int,std::vector<Employee>> mapSalRange(std::vector<Employee>& emp);
void printSalRange(std::map<int,std::vector<Employee>>& salRange);

std::unordered_map<int,std::vector<Employee>> umapEmpDept(std::vector<Employee>& emp);
std::unordered_map<int,std::vector<Employee>> umapSalRange(std::vector<Employee>& emp);
void uprintSalRange(std::unordered_map<int,std::vector<Employee>>& salRange);


#endif
