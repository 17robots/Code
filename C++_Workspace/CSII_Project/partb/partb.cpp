#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include "station.hpp"
#include "list.hpp"
#include <limits>
#include <ctime>

//global variables for the data structure
const int NUMLABS = 8;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

// printing function headers
void printMenu();
void printLabs();
Station printSignInPrompt();
int printSignOutPromptId();
int printSignOutPromptLab(List (&list)[NUMLABS], int& currentLab);
int printSignOutMenu();
int printSearchPrompt();
int printRecoverMenuId();
int printRecoverMenuLab(Station foundUser, List (&list)[NUMLABS]);


// helper function headers
void log(std::string message);
void initialze(List (&list)[NUMLABS], int& currentLab);
int generateId();
Station searchLog();
int runProgram(List (&list)[NUMLABS], std::map<int, Station> &map, int &currentLab);
Station searchLog(int idToSearch);
void recoverUser(int userId, List (&labs)[NUMLABS], std::map<int, Station> &map);
void signInUser(int labChoice, List (&list)[NUMLABS], Station &newUser, std::map<int, Station> &map);
void signOutUser(int userId, List (&list)[NUMLABS], std::map<int, Station> &map);
void signOutUser(int labChoice, int stationChoice, List (&list)[NUMLABS], std::map<int, Station> &map);
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

    // choose the current lab
    initialze(labs, currentLab);

    int responseCode;

    do {
        responseCode = runProgram(labs, users, currentLab);
    } while(responseCode != 7);
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
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cout << "7. Quit" << std::endl;
}

void printLabs() {
    for(int i = 0; i < NUMLABS; ++i) {
        std::cout <<i + 1 << ". " << UNIVERSITYNAMES[i] << std::endl;
        std::cout << "Avaliable Labs: " << LABSIZES[i] << std::endl;
    }
}

int printSignOutMenu() {
  std::cout << "Sign Out" << std::endl;
  std::cout << "1. By Id" << std::endl;
  std::cout << "2. By Manual Selection" << std::endl;
  int choice;
  std::cin >> choice;
  while(std::cin.fail() || choice < 1 || choice > 2) {
    std::cout << "Please enter a valid choice: ";
    std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> choice;
  }
  return choice;
}

int printSignOutPromptLab(List (&list)[NUMLABS], int& currentLab) {
  std::cout << "Current Lab: " << UNIVERSITYNAMES[currentLab - 1] << std::endl;
  list[currentLab - 1].showList();
  int choice;
  std::cin >> choice;
  while(std::cin.fail() || choice > LABSIZES[currentLab - 1] || choice < 1) {
    std::cout << "Please enter a valid choice: ";
    std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> choice;
  }
  return choice;
}

int printSignOutPromptId() {
  int id;
  
  do {
    std::cout << "Enter the id of the user you want to sign out: " << std::endl;
    std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> id;
  } while(std::cin.fail());

  return id;
}

void printSignOutPromptLab(int currentLab, List &lab) {
  std::cout << "Signing out from " << UNIVERSITYNAMES[currentLab - 1] << std::endl;
  lab.showList();
  std::cout << "Please choose which station to sign the person out of: ";
  int stationToDelete;
  while(std::cin.fail() || stationToDelete > lab.size() || stationToDelete < 1) {
    std::cout << "Please enter a valid station number." << std::endl;
    std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> stationToDelete;
  }
}

int printSearchPrompt() {
  std::cout << "Search" << std::endl;
  std::cout << "Enter the Id To Search: ";
  int idToSearch;
  std::cin >> idToSearch;
  while(std::cin.fail()) {
    std::cout << "Please enter a valid number: ";
    std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> idToSearch;
  }
  return idToSearch;
}

Station printSignInPrompt(int currentLab) {
  std::cout << "Signing User into " << UNIVERSITYNAMES[currentLab - 1] << std::endl;
  std::cout << "Enter the person's name: ";
  std::string name;
  std::getline(std::cin, name);
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
          std::cin.clear();
		    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while(std::cin.fail() || useTime < 15 || useTime > 60);
  int id = generateId();
  return Station(generateId(), name, useTime);
}

int printRecoverMenuId() {
  std::cout << "Attempting to restore user. Please enter the id of the user you want to restore: ";
  int idToRestore;
  std::cin >> idToRestore;
  while(std::cin.fail()) {
    std::cout << "Please enter a number and try again: ";
    std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> idToRestore;
  }
  return idToRestore;
}

int printRecoverMenuLab(Station foundUser, List (&list)[NUMLABS]) {
  std::cout << "User found in the logs: ";
  std::cout << foundUser << std::endl;
  std::cout << std::endl;
  std::cout << "Which lab would you like to recover him to: ";
  int recoverLab;
  std::cin >> recoverLab;
  while(std::cin.fail() || recoverLab > NUMLABS || recoverLab < 1) {
    std::cout << "Please choose a valid option: ";
    std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> recoverLab;
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
    myfile.open (str + "txt", std::ios_base::app);
    if(myfile.is_open()) {
        std::cout<<"Opened file " << str << std::endl;
    } else {
        std::cout << "Failed to open file" << std::endl;
    }

    strftime (buffer,80,"%d-%m-%Y %H-%M-%S",now);

    myfile << buffer << ": "<< message << std::endl;
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
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> newLab;
	}
	lab = newLab;
}

Station searchLog(int idToSearch) {
  // these are what we need to recover from the file
  std::string name = "";
  int useTime = -1;
  int id = -1;

  // open the file
  time_t t = time(0);   // get time now
  struct tm * now = localtime( & t );
  char buffer [20];
  strftime (buffer,20,"%Y-%m-%d.",now);
  std::string str(buffer);

  std::ifstream myfile;
  myfile.open (str + "txt", std::ios_base::in);
  if(myfile.is_open()) {
      std::cout<<"Opened File "<< str << std::endl;
  } else {
      std::cout << "Failed to open file" << std::endl;
  }

 // now search the file
 bool found = false;
 std::string line;
 while(myfile.good()) {
   if(!found) { // if not found, keep searching
     std::getline(myfile,line);
     int pos=line.find(std::to_string(idToSearch));
     if(pos != std::string::npos) {
       found = true; // we found the person, move to load up person into a new Station object based on logging when the user signs out
     }
   } else {
     std::getline(myfile,line);
    // go through and check which things to fill for each part because each part is going to require different parsing
    if(name == "") { //start with the name
      name = line.substr(26);
    } else if(useTime == -1) {
      useTime = std::stoi(line.substr(30));
    } else if(id == -1) {
      id = idToSearch;
    }
   }
  }
  return Station(id, name, useTime);
}

int runProgram(List (&list)[NUMLABS], std::map<int, Station> &map, int &currentLab) {
    int menuChoice;
		std::cout << "Current University: " << UNIVERSITYNAMES[currentLab - 1] << std::endl;
    printMenu();
    std::cout << "Menu Option: ";
    std::cin >> menuChoice;

    if(std::cin.fail()) {
        std::cout << "That is not a choice. Please enter an integer between 1 and 7." << std::endl;
        std::cin.clear();
			  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 8; // return a value to make the menu repeat
    } else {
        switch(menuChoice) {
            case 1: {// sign in user
                Station newUser = printSignInPrompt(currentLab);
								signInUser(currentLab, list, newUser, map);
                break;
            }
            case 2: { // sign out user
                switch(printSignOutMenu()) {
                  case 1: {
                    int deleteThisId = printSignOutPromptId();
                    signOutUser(deleteThisId, list, map);
                    break;
                  }
                  case 2: {
                    int station = printSignOutPromptLab(list, currentLab);
                    signOutUser(currentLab, station, list, map);
                    break;
                  }
                }
                break;
            }
            case 3: { // print labs
                std::cout << "Current Lab: " << UNIVERSITYNAMES[currentLab - 1] << std::endl;
                list[currentLab - 1].showList();
                std::cout << std::endl;
                break;
            }
            case 4: { // search user
                int idToSearch = printSearchPrompt();
                Station foundUser = search(idToSearch, map);
                if(foundUser.getId() == -1) { // the user is not found
                  std::cout << "That user is not logged in" << std::endl;
                } else {
                  std::cout << "User Found:" << std::endl;
                  std::cout << foundUser << std::endl;
                }
                break;
            }
            case 5: { // recover user
                int id = printRecoverMenuId();
                recoverUser(id, list, map);
                break;
            }
            case 6: { // change lab
                changeLab(currentLab);
                break;
            }
						case 7: { // quit
								std::cout << "Quitting" << std::endl;
						}
            default: {
                std::cout << "That is not a valid menu option" << std::endl;
            }
        }
        return menuChoice;
    }
}

bool isFull(int labChoice, List &list) {
  return list.size() == LABSIZES[labChoice - 1];
}

void recoverUser(int userId, List (&labs)[NUMLABS], std::map<int, Station> &map) {
    Station foundStation = searchLog(userId);
    std::cout << "FoundStation: " << foundStation << std::endl;
    if(foundStation.getId() == -1) { //if the user was not found
      std::cout << "The user was not found in these logs. Please make sure the user was not signed in a previous log or that the id was typed correctly." << std::endl;
    } else {
      int labToSignIn = printRecoverMenuLab(foundStation, labs);
      std::cout << labs << std::endl;
      labs[labToSignIn - 1].appNode(foundStation); // add the user in
      std::cout << "Appended" << std::endl;
      map.emplace(foundStation.getId(), foundStation);
      std::cout << "Placing In Map" << std::endl;
      log("Signed in " + std::to_string(foundStation.getId()));
      log("Name: " + foundStation.getName());
      log("Use Time: " + std::to_string(foundStation.getUseTime()));
    }
}

void signInUser(int labChoice, List (&list)[NUMLABS], Station &newUser, std::map<int, Station> &map) {
    std::cout << list << std::endl;
    list[labChoice - 1].appNode(newUser); // add the user in
    std::cout << "Appended" << std::endl;
    map.emplace(newUser.getId(), newUser);
    std::cout << "Placing In Map" << std::endl;
    log("Signed in " + std::to_string(newUser.getId()));
    log("Name: " + newUser.getName());
    log("Use Time: " + std::to_string(newUser.getUseTime()));
}

void signOutUser(int userId, List (&list)[NUMLABS], std::map<int, Station> &map) {
    std::map<int, Station>::iterator person = map.find(userId); // find the user in the map
    if(person != map.end()) {
      // delete the map entry
      map.erase(userId);
      std::cout << "Deleted from the map" << std::endl;
      // delete the user from the list
      for(int i = 0; i < NUMLABS; ++i) {
        int result = list[i].find(userId);
        std::cout << "Found result: " << result << std::endl;
        if(result != -1) {
          list[i].delNode(result);
        } else {
          std::cout << "That person was not found" << std::endl;
        }
      }
    } else {
      std::cout << "That person is not signed in. Please make sure that the id was typed correctly." << std::endl;
    }
}

void signOutUser(int labChoice, int stationChoice, List (&list)[NUMLABS], std::map<int, Station> &map) {
  list[labChoice - 1].delNode(stationChoice);
  map.erase(list[labChoice - 1].loop(stationChoice).getId());
}

Station search(int userId, std::map<int, Station> &map) {
    std::cout << "Search User" << std::endl;
    std::map<int, Station>::iterator item  = map.find(userId);
    if(item != map.end()) {
      return map[userId];
    } else {
      return Station(-1, "", -1);
    }
}
