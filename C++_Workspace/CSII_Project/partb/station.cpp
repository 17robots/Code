#include "station.hpp"
#include <iostream>

int Station::getId() const {return id;}

std::string Station::getName() const {
    return name;
}

int Station::getUseTime() const {
    return useTimeInMinutes;
}

int Station::getLabNumber() const {
	return labNumber;
}

//Modifiers
void Station::setId(int newId) {id = newId;}

void Station::setName(std::string newName) {name = newName;}

void Station::setUseTime(int newUseTime) {useTimeInMinutes = newUseTime;}

void Station::setLabNumber(int newLabNumber) {labNumber = newLabNumber;}

//Interface Methods
Station::Station() {
	id= -1;
	name = " ";
	useTimeInMinutes = -1;
	labNumber = -1;
}

Station::Station(int newLabNumber) { //Default constructor
	id = -1;
	name = " ";
	useTimeInMinutes = 0;
	labNumber = newLabNumber;
}

Station::Station(int newId, std::string newName, int newUseTime, int newLabNumber) { //Basic Constructor
	id = newId;
	name = newName;
	useTimeInMinutes = newUseTime;
	labNumber = newLabNumber;
}

Station::Station(Station const &copy) {
	id = copy.getId();
	name = copy.getName();
	useTimeInMinutes = copy.getUseTime();
	labNumber = copy.getLabNumber();
}

std::ostream & operator <<(std::ostream & buffer, Station &obj) {
	buffer << obj.getId() << " " << obj.getName() << " " << obj.getUseTime() << " ";
	return buffer;
}
