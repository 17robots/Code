#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include "station.hpp"
#include "list.hpp"
#include <ctime>

//global variables for the data structure
const int NUMLABS = 8;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

// printing function headers
void printMenu();
void printLabs();
void printSignInPrompt();
void printSignOutPromptMain();
void printSignOutPromptId();
void printSignOutPromptLab();


// helper function headers
void log(std::string message);
void initialze(List (&list)[NUMLABS]);
int generateId();
int runProgram(List (&list)[NUMLABS], std::map<int, Station> &map);
void recoverUser(int userId, std::map<int, Station> &map);
void signInUser(int labChoice, List (&list)[NUMLABS], Station &newUser, std::map<int, Station> &map);
void signOutUser(int userId, List (&list)[NUMLABS], std::map<int, Station> &map);
void signOutUser(int labChoice, int stationChoice, List (&list)[NUMLABS]);
Station search(int userId, std::map<int, Station> &map);
bool isFull(int labChoice, List &list);

int main() {
    // variable creation
    List labs[NUMLABS];
    int currentLab;
    // the map for searching
    std::map<int, Station> users;
    
    // seed the random number generator
    srand(((unsigned) time(NULL)));
    
    // initial display of everything and assignment
    initialze(labs, currentLab);
    
    int responseCode;
    
    do {
        responseCode = runProgram(labs, users);	
    } while(responseCode != 6);	
    return 0;
}

void initialze(List (&list)[NUMLABS], int& currentLab) {
    // print the main display menus including all of the labs and universities
    std::cout << "COMPUTER LAB MANAGEMENT SOFTWARE" << std::endl;
    printLabs();
    std::cout << "Please select a lab to manage: ";
    int labChoice;
		std::cin >> labChoice;

    while(std::cin.fail() || labChoice < 1 || labChoice > NUMLABS) {
			std::cout << "Please choose a valid lab: ";
			std::cin >> labChoice;
    }

		currentLab = labChoice;

    std::cout << "Initialized" << std::endl; 
}

// print functions
void printMenu() {
    std::cout << "Options" << std::endl;
    std::cout << "1. Sign In A User" << std::endl;
    std::cout << "2. Sign Out A User" << std::endl;
    std::cout << "3. Print Station" << std::endl;
    std::cout << "4. Search User" << std::endl;
    std::cout << "5. Recover User" << std::endl;
		std::cout << "6. Change Lab" << std::endl;
    std::cout << "6. Quit" << std::endl;
}

void printLabs() {
    for(int i = 0; i < NUMLABS; ++i) {
        std::cout <<i + 1 << ". " << UNIVERSITYNAMES[i] << std::endl;
        std::cout << "Avaliable Labs: " << LABSIZES[i] << std::endl; 
    }
}

// helper functions
void log(std::string message) {
    // first try to open the file
     time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    char buffer [20];
    strftime (buffer,20,"%Y-%m-%d.",now);
    std::string str(buffer);
    
    std::ofstream myfile;
    myfile.open (str + "log", std::ios_base::ate);
    if(myfile.is_open()) {
        std::cout<<"Success"<<std::endl;
    } else {
        std::cout << "Failed to open file" << std::endl;
    }
    
    strftime (buffer,80,"%d-%m-%Y %H-%M-%S",now);
    
    myfile << buffer << ": "<< message << std::endl;
    std::cout << "logged" << std::endl;
    myfile.close();
}

int generateId() {
    return rand() % 99999 + 1;
}

void changeLab(int& lab) {
	std::cout << "Changing Labs" << std::endl;
	printLabs();
	std::cout << "Choose a new lab to manage." << std::endl;
	int newLab;
	std::cin >> newLab;
	while(std::cin.fail() || newLab < 1 || newLab > NUMLABS) {
					std::cout << "Please choose a valid lab: ";
					std::cin >> newLab;
	}
	lab = newLab;
}

int runProgram(List (&list)[NUMLABS], std::map<int, Station> &map, &currentLab) {
    int menuChoice;
		std::cout << "Current University: " << UNIVERSITYNAMES[currentLab - 1] << std::endl;
    printMenu();
    std::cout << "Menu Option: ";
    std::cin >> menuChoice;
    
    if(std::cin.fail()) {
        std::cout << "That is not a choice. Please enter an integer between 1 and 6." << std::endl;
        return 7; // return a value to make the menu repeat
    } else {
        switch(menuChoice) {
            case 1: // sign in user	
								std::cout << "Signing User into " << UNIVERSITYNAMES[currentLab - 1] << std::endl;
								std::cout << "Enter the person's name: ";
								std::string name;
								std::getline(std::cin, name);
								std::cout << "Please enter the expected use time for the user: ";
							 	int useTime;	
								do {
									std::cin >> useTime;
									switch(useTime) {
										case 15:
												break;
										case 30:
												break;
										case 45:
												break;
										case 60:
												break;
										default:
												useTime = 10000; // force the loop to repeat
												std::cout << "Please enter a valid use time in increments of 15 up to an hour." << std::endl;
									}
								} while(std::cin.fail() || useTime < 15 && useTime > 60);
								int id = generateId();	
								signInUser(currentLab, list, Station(generateId(), name, useTime, currentLab);
								log("Logged " + id + " into ");
                break;
            case 2: // sign out user
                std::cout << "Sign Out" << std::endl;
                break;
            case 3: // print labs
                list[currentLab - 1].showList();
                break;
            case 4: // search user
                std::cout << "Search" << std::endl;
                break;
            case 5: // recover user
                std::cout << "Recover" << std::endl;
                break;
            case 6: // quit
                changeLab(currentLab);
                break;
						case 7:
								std::cout << "Quitting" << std::endl;
            default: 
                std::cout << "That is not a valid menu option" << std::endl;
        }
        return menuChoice;
    }
}

void recoverUser(int userId, std::map<int, Station> &map) {
    std::cout << "Recover User" << std::endl;
}

void signInUser(int labChoice, List (&list)[NUMLABS], Station &newUser, std::map<int, Station> &map) {
    std::cout << "Log In User" << std::endl;
}

void signOutUser(int userId, List (&list)[NUMLABS], std::map<int, Station> &map) {
    std::cout << "Log Out User" << std::endl;
}

void signOutUser(int labChoice, int stationChoice, List (&list)[NUMLABS]) {
    std::cout << "Log Out User 2" << std::endl; 
}
Station search(int userId, std::map<int, Station> &map) {
    std::cout << "Search User" << std::endl;
    return Station(999, " ", 999, 999);
}

bool isFull(int labChoice, List &list) {
    return list.loop(LABSIZES[labChoice - 1] - 1).getId() != -999;
}
