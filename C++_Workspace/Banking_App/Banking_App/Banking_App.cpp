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
	std::string type;
};

class user {
	std::vector<account> accounts;
	std::string username, password, name;
};

enum command_arguments {
	register_user = 3,
	delete_user = 2,
	view_account = 2,
	login = 3,
	logout = 1,
	add_account = 2,
	deposit = 3,
	withdraw = 3
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

std::vector<std::string> breakLine(std::string line) {
	std::vector<std::string> returnedVector;
	std::string trimmedString = line;
	int spaceIndex;

	do {
		spaceIndex = trimmedString.find(" ");
		returnedVector.push_back(trimmedString.substr(0, spaceIndex));
		trimmedString = trimmedString.substr(spaceIndex + 1);
	} while (trimmedString.find(" ") != std::string::npos);

	returnedVector.push_back(trimmedString);

	return returnedVector;
}

int getWords(std::string line) {
	return numSpaces(line) + 1;
}

user findUserByAccountName(std::vector<user> users, std::string name) {

}

void addAccount(std::string type) {

}

void addUser() {

}

void deleteUser() {

}

void parse(std::string line) {
	command_arguments args;
	if (getWords(line) > 1) {

	}
	else {

	}
}

int main()
{
	std::string command = "test";
	std::cin.get();
    return 0;
}

