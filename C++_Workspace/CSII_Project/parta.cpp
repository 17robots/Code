#include <iostream>
#include <string>

const int NUMLABS = 8;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};

const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

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

	//Operator Overloads 
	void operator==(Station &B); // meant to only compare the id's for the searching
};

void printMenu() {
  std::cout << "Menu" << std::endl;
  std::cout << "1. Log In" << std::endl;
  std::cout << "2. Log Off" << std::endl;
  std::cout << "3. Display" << std::endl;
  std::cout << "4. Search" << std::endl;
  std::cout << "5. Quit" << std::endl;
}

int main() {
  int menuChoice;
  Station* Labs[NUMLABS];

  for(int i = 0; i < NUMLABS; ++i) {
	Labs[i] = new Station[LABSIZES[i]];
  }

  for(int i = 0; i < NUMLABS; ++i) {
	for(int j = 0; j < LABSIZES[i]; ++j) {
	  Labs[i][j] = Station(); // Fill up all of the stations with empty people
	}
  }

  do {
	printMenu();
	std::cout << "Option: ";
	std::cin >> menuChoice;

	switch(menuChoice) {
	  case 1:
		for(int i = 0; i < NUMLABS; ++i) {
		  std::cout << i + 1 << ". " << UNIVERSITYNAMES[i] << std::endl;
		}

		int uniChoice, StationChoice;

		std::cout << "Which Uninversity are you logging into?: ";
		std::cin >> uniChoice;

		while(!(uniChoice < NUMLABS + 1 && uniChoice > 0)) {
		  std::cout << "Please enter a number on the list: ";
		  std::cin >> uniChoice;
		}
		for(int i = 0; i < LABSIZES[uniChoice - 1]; ++i) {
		  std::cout << "[Station " << i + 1 << ": ";
		  if(Labs[uniChoice - 1][i].getId() == -1) {
			std::cout << "Open] ";
		  } else {
			std::cout << "In use by " << Labs[uniChoice - 1][i].getId() << "] ";
		  }
		}
		std::cout << "Please choose a station (" << UNIVERSITYNAMES[uniChoice - 1] << "): ";
		
		break;
	  case 2:
		std::cout << "2. Log Off" << std::endl;
		break;
	  case 3: 
		for(int i = 0; i < NUMLABS; ++i) {
		  std::cout << "Computer Lab at " << UNIVERSITYNAMES[i] << "." << std::endl;
		  for(int j = 0; j < LABSIZES[i]; ++j) {
			std::cout << "[Station " << j + 1 << ": ";
			if(Labs[i][j].getId() == -1) {
			  std::cout << "Open] ";
			} else {
			  std::cout << "In use by " << Labs[i][j].getId() << "] ";
			}
		  }
		  std::cout << std::endl << std::endl;
		}
		break;
	  case 4:
		std::cout << "4. Search" << std::endl;
		break;
	  case 5:
		break;
	  default:
		std::cout << "That was not a valid option please try again" << std::endl;
		std::cin >> menuChoice;
		break;
	}
  } while(menuChoice != 5);

  return 0;
}

void Station::operator==(Station &B) {

}
