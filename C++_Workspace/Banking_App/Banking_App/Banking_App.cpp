// Banking_App.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

static const size_t npos = -1;

class account {
private:
	double amount;
	int acc_number;
};

class user {
	std::vector<account> accounts;
	std::string username, password, name;
};

std::vector<user> users;

int numSpaces(std::string line) {
	int spaces = 0;
	for (int i = 0; i < line.length(); ++i) {
		if (line.at(i) == ' ') {
			++spaces;
		}
	}
	return spaces;
}

int getWords(std::string line) {
	return numSpaces(line) + 1;
}

void parse(std::string line) {
	
}

int main()
{
	parse();
	std::cin.get();
    return 0;
}

