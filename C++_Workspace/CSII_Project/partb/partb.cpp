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
    
    // the map for searching
    std::map<int, Station> users;
    
    // seed the random number generator
    srand(((unsigned) time(NULL)));
    
    // initial display of everything and assignment
    initialze(labs);
    
    int responseCode;
    
    do {
        responseCode = runProgram(labs, users);
	std::cout << "Response Code: " << responseCode << std::endl;
    } while(responseCode != 6);
    return 0;
}

void initialze(List (&list)[NUMLABS]) {
    // print the main display menus including all of the labs and universities
    std::cout << "COMPUTER LAB MANAGEMENT SOFTWARE" << std::endl;
    printLabs();
    
    //  load up the list
     for(int i = 0; i < NUMLABS; ++i) {
         for(int j = 0; j < LABSIZES[i]; ++j) {
             list[i].appNode(Station(j + 1));
         }
     }

    std::cout << "Initialized" << std::endl; 
}

// print functions
void printMenu() {
    std::cout << "Options" << std::endl;
    std::cout << "1. Sign In A User" << std::endl;
    std::cout << "2. Sign Out A User" << std::endl;
    std::cout << "3. Print Labs" << std::endl;
    std::cout << "4. Search User" << std::endl;
    std::cout << "5. Recover User" << std::endl;
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

int runProgram(List (&list)[NUMLABS], std::map<int, Station> &map) {
    int menuChoice;
    printMenu();
    std::cout << "Menu Option: ";
    std::cin >> menuChoice;
    
    if(std::cin.fail()) {
        std::cout << "That is not a choice. Please enter an integer between 1 and 6." << std::endl;
        return 7; // return a value to make the menu repeat
    } else {
        switch(menuChoice) {
            case 1: // sign in user
                
                break;
            case 2: // sign out user
                std::cout << "Sign Out" << std::endl;
                break;
            case 3: // print labs
                for(int i = 0; i < NUMLABS; ++i) {
                    list[i].showList();
                }
                break;
            case 4: // search user
                std::cout << "Search" << std::endl;
                break;
            case 5: // recover user
                std::cout << "Recover" << std::endl;
                break;
            case 6: // quit
                std::cout << "Quitting" << std::endl;
                break;
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
    return Station(999, " ", 999);
}

bool isFull(int labChoice, List &list) {
    return list.loop(LABSIZES[labChoice - 1] - 1).getId() != -999;
}
