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
void printUniversities();
void printLabs();


// helper function headers
void log(std::string message);
void initialze(List (&list)[NUMLABS]);
int generateId();
int runProgram(List (&list)[NUMLABS], std::map<int, Station> &map);
void recoverUser(int userId, int labChoice);
void signInUser(int labChoice, Station newUser, std::map<int, Station> &map);
void signOutUser(int userId);
void signOutUser(int labChoice, int stationChoice);

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
    } while(responseCode != 6);
    return 0;
}

void initialze(List (&list)[NUMLABS]) {
    // print the main display menus including all of the labs and universities
    std::cout << "COMPUTER LAB MANAGEMENT SOFTWARE" << std::endl;
    printLabs();
    
    // load up the list
    // for(int i = 0; i < NUMLABS; ++i) {
    //     for(int j = 0; j < LABSIZES[i]; ++j) {
    //         list[i].appNode(Station(j + 1));
    //     }
    // }
    
    list[0].appNode(Station(1));
    list[0].appNode(Station(2));
    list[0].appNode(Station(3));
    
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
                std::cout << list[0].loop(2).getLabNumber() << std::endl;
                std::cout << "Sign In" << std::endl;
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