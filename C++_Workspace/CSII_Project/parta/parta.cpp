// NAME: Matthew Dray
// Filename: parta.cpp
// Purpose: Part A of the project, making a computer lab management system

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

// pregiven constants from the specs 
const int NUMLABS = 8;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

// the Station class that represents each user on each computer
class Station {
	private:
		int id;
		std::string name;
		int useTimeInMinutes;
	public:
		//Accessors
		int getId() const {return id;}
		std::string getName() const {return name;}
		int getUseTime() const {return useTimeInMinutes;}

		//Modifiers
		void setId(int newId) {id = newId;}
		void setName(std::string newName) {name = newName;}
		void setUseTime(int newUseTime) {useTimeInMinutes = newUseTime;}

		//Interface Methods
		Station() { //Default constructor
			id = -1;
			name = " ";
			useTimeInMinutes = 0;
		}

		Station(int newId, std::string newName, int newUseTime) { //Basic Constructor
			id = newId;
			name = newName;
			useTimeInMinutes = newUseTime;
		}

		Station(Station const &copy) {
			id = copy.getId();
			name = copy.getName();
			useTimeInMinutes = copy.getUseTime();
		}
};

// helper functions

// precondition: none
//post condition: creates a random 5-digit id for the user
int generateUserID() {
	srand(time(NULL));
	return rand() % 99999 + 1;
}

//pre condition: Labs is properly initialized to a jagged array and university is a properly initialized integer
//post condition: returns if the computer lab is full or not as a bool
bool isFull(int university, Station * Labs[]) {
	int counter = 0;
	for(int i = 0; i < LABSIZES[university]; ++i) {
		if(Labs[university][i].getId() != -1) {
			counter++;
		}
	}

	return (counter == LABSIZES[university]); // if the lab is full or not
}

// these print functions make dealing with menu formatting a lot easier and clean up the code down below so as only to focus on the structure of the menu transitions
void printMainMenu() { // the main menu
	std::cout << "Menu" << std::endl;
	std::cout << "1. Log In" << std::endl;
	std::cout << "2. Log Off" << std::endl;
	std::cout << "3. Display" << std::endl;
	std::cout << "4. Search" << std::endl;
	std::cout << "5. Quit" << std::endl;
}

void printUniversities() { // the list of universities
	for(int i = 0; i < NUMLABS; ++i) {
		std::cout << i + 1 << ". " << UNIVERSITYNAMES[i] << std::endl;
	}
}

void printLabs(int university, Station *Labs[]) { // the list of each universities' lab stations
	for(int i = 0; i < LABSIZES[university]; ++i) {
		std::cout << "[Station " << i + 1 << ": ";
		if(Labs[university][i].getId() == -1) {
			std::cout << "Open] ";
		} else {
			std::cout << "In use by " << std::setfill('0') << std::setw(5) << Labs[university][i].getId() << ", " << Labs[university][i].getName() << "] ";
		}
	}
}

void printUser(int university, int station, Station *Labs[]) { // the user information
	std::cout << "Id: " << std::setfill('0') << std::setw(5) << Labs[university][station].getId() << std::endl;
	std::cout << "Name: " << Labs[university][station].getName() << std::endl;
	std::cout << "University: " << UNIVERSITYNAMES[university] << std::endl;
	std::cout << "Station: " << station + 1 << std::endl;
	std::cout << "Expected Use Time: " << Labs[university][station].getUseTime() << " minutes" << std::endl;
}

void printLogOutMenu() { // the menu options for choosing who to log out
	std::cout << "1. Id" << std::endl;
	std::cout << "2. Station" << std::endl;
	std::cout << "3. Main Menu" << std::endl;
	std::cout << "How would you like to log out the user?: ";
}

void printLogOutFindFailedMenu() { // the menu that shows when the search for the user's id fails for logging out 
	std::cout << "That user is not logged in." << std::endl;
	std::cout << "1. Try logging out another user" << std::endl;
	std::cout << "2. Quit" << std::endl;
	std::cout << "Choice: ";
}

void printOutFindSuccessMenu() { // the menu that shows when the search for the user's id succeeds for logging out 
	std::cout << std::endl << "1. Sign this user out" << std::endl;
	std::cout << "2. Search for another user" << std::endl;
	std::cout << "3. Main Menu" << std::endl;
	std::cout << "Choice: ";
}


// using do {} while() structures with switch statenents will allow for correcting user input while processing menu transitions smoothly as states

int main() {
	int menuChoice;
	Station* Labs[NUMLABS]; // the array of pointers

	for(int i = 0; i < NUMLABS; ++i) {
		Labs[i] = new Station[LABSIZES[i]]; // build the arrays on the heap with different sizes
	}

	for(int i = 0; i < NUMLABS; ++i) {
		for(int j = 0; j < LABSIZES[i]; ++j) {
			Labs[i][j] = Station(); // Fill up all of the stations with empty people
		}
	}

	do {
		printMainMenu();
		std::cout << "Option: ";
		std::cin >> menuChoice;

		switch(menuChoice) {
			case 1: {
					printUniversities();

					int uniChoice, stationChoice;
					std::string Fname;

					std::cout << "Which Uninversity are you logging into?: ";
					std::cin >> uniChoice;

					while(std::cin.fail() || !(uniChoice < NUMLABS + 1 && uniChoice > 0)) {
						std::cout << "Please enter a number on the list: ";
						std::cin >> uniChoice;
					}

					if(isFull(uniChoice - 1, Labs)) {
						std::cout << "The Lab is full, please wait until someone signs out." << std::endl;
						break; // if the lab is full, do not try to continue
					}

					printLabs(uniChoice - 1, Labs);

					do {
						std::cout << "Please choose a station (" << UNIVERSITYNAMES[uniChoice - 1] << "): ";
						std::cin >> stationChoice;
						if(Labs[uniChoice - 1][stationChoice - 1].getId() != -1) { // if the computer is in use
							std::cout << "That station is in use" << std::endl;
							stationChoice = -1; // force the loop to repeat
						}
					} while(std::cin.fail() || !(stationChoice < LABSIZES[uniChoice - 1] + 1 && stationChoice > 0));
					
					int minutes;
					do {
						std::cout << "Now, how many minutes do you plan to use the computer for?: ";
						std::cin >> minutes;
						bool validTime = false;

						switch(minutes) {
							case 15:
								validTime = true;
								break;
							case 30:
								validTime = true;
								break;
							case 45:
								validTime = true;
								break;
							case 60:
								validTime = true;
								break;
							default:
								std::cout << "That is not a valid time. Please enter either 15, 30, 45, or 60 minutes." << std::endl;
						}
						
						if(!validTime) {
							minutes = 62;
						}
					} while(std::cin.fail() || !(minutes < 61 && minutes > 0));

					std::cout << "And finally, what is your name?: ";

					getline(std::cin, Fname); // get rid of the enter character
					getline(std::cin, Fname);

					// now we log the user in 
					Labs[uniChoice - 1][stationChoice - 1] = Station(generateUserID(), Fname, minutes);
					std::cout << "Successfully Logged In " << Labs[uniChoice - 1][stationChoice - 1].getName() << " into " << UNIVERSITYNAMES[uniChoice - 1] << "'s Station " << stationChoice << " for " << minutes << " minutes." << std::endl;
					break;
				}
			case 2: {
					int logOutChoice;
					do {
						printLogOutMenu();
						std::cin >> logOutChoice;

						switch(logOutChoice) {
							case 1: {
									int idToSearch, signOutUni, signOutStation;
									bool found = false;
									std::string name;
									std::cout << "Enter the person's user id: ";
									std::cin >> idToSearch;
									for(int i = 0; i < NUMLABS; ++i) {
										for(int j = 0; j < LABSIZES[i]; ++j) {
											if(Labs[i][j].getId() == idToSearch) {
												found = true;
												printUser(i, j, Labs);
												signOutUni = i;
												signOutStation = j;

												name = Labs[i][j].getName(); // we will need this to print out the confirmation message later
											}
										}
									}

									int menuChoice;

									if(!found) {
										do {
											printLogOutFindFailedMenu();
											std::cin >> menuChoice;
											switch(menuChoice) {
												case 1:
													logOutChoice = -1; // Force the menu to repeat
													break;
												case 2:
													continue; // keep going and quit to the main menu
													break;
												default:
													std::cout << "Please enter a valid option";
													break;
											}
										} while(std::cin.fail() || !(menuChoice > 0 && menuChoice < 3));
									} else {
										do {
											printOutFindSuccessMenu();
											std::cin >> menuChoice;

											switch(menuChoice) {
												case 1:
													Labs[signOutUni][signOutStation] = Station();
													std::cout << "Successfully Logged out " << name << " from " << UNIVERSITYNAMES[signOutUni] << "'s Station " << signOutStation + 1 << "." << std::endl;
													break;
												case 2:
													logOutChoice = -1;
													break;
												case 3:
													continue;
													break;
												default:
													std::cout << "Please enter a valid option";
													break;
											}
										} while (std::cin.fail() || !(menuChoice > 0 && menuChoice));
									}

									break;
								}

							case 2: {
									for(int i = 0; i < NUMLABS; ++i) {
										std::cout << i + 1 << ". " << UNIVERSITYNAMES[i] << std::endl;
									}

									int uniChoice, stationChoice; // the user's choices for the university and station (not as indexes)
									std::string Fname;

									std::cout << "Which Uninversity are you logging out of?: ";
									std::cin >> uniChoice;

									while(!(uniChoice < NUMLABS + 1 && uniChoice > 0)) { // using while because i do not want cases for every lab
										std::cout << "Please enter a number on the list: ";
										std::cin >> uniChoice;
									}

									printLabs(uniChoice - 1, Labs);

									do {
										std::cout << "Please choose a station (" << UNIVERSITYNAMES[uniChoice - 1] << "): ";
										std::cin >> stationChoice;
										if(Labs[uniChoice - 1][stationChoice - 1].getId() == -1) { // if the computer is not in use
											std::cout << "That station is not in use" << std::endl;
											stationChoice = -1; // force the loop to repeat
										}
									} while(!(stationChoice < LABSIZES[uniChoice - 1] && stationChoice > 0));

									// log the user out
									std::string name = Labs[uniChoice - 1][stationChoice - 1].getName();
									Labs[uniChoice - 1][stationChoice - 1] = Station();
									std::cout << "Successfully Logged out " << name << " from " << UNIVERSITYNAMES[uniChoice - 1] << "'s Station " << stationChoice << "." << std::endl;
									break;
								}

							case 3: {
									continue; //leaving the menu as is effectively quitting
									break;
								}

							default: {
									 std::cout << "Please pick a valid menu option" << std::endl;
									 break;
								 }
						}
					} while(std::cin.fail() || !(logOutChoice > 0 && logOutChoice < 4));
					break;

				}
			case 3: 
				for(int i = 0; i < NUMLABS; ++i) {
					std::cout << "Computer Lab at " << UNIVERSITYNAMES[i] << "." << std::endl;
					printLabs(i, Labs);
					std::cout << std::endl << std::endl;
				}
				break;
			case 4: {	
					int idToSearch;
					bool found = false; // will let us know if a person is found which will come in handy after looping through
					std::cout << "Enter the person's user id: ";
					std::cin >> idToSearch;
					for(int i = 0; i < NUMLABS; ++i) {
						for(int j = 0; j < LABSIZES[i]; ++j) {
							if(Labs[i][j].getId() == idToSearch) {
								found = true; // this will prevent the error message from printing down below
								printUser(i, j, Labs); // print the found player
							}
						}
					}
					if(!found) { // the error message if a person is not found
						std::cout << "That user is not logged in." << std::endl;
					}
					break;
				}
			case 5: {
					break;
				}
			default: {
				std::cout << "That was not a valid option please try again" << std::endl;
				std::cin >> menuChoice;
				break;
			}
		}
	} while(std::cin.fail() || menuChoice != 5);

	return 0;
}
