#include "station.hpp"
#include <iostream>

int Station::getId() const {return id;}

std::string Station::getName() const {
    return name;
}

int Station::getUseTime() const {
    return useTimeInMinutes;
}

//Modifiers
void Station::setId(int newId) {
    id = newId;
}

void Station::setName(std::string newName) {name = newName;}

void Station::setUseTime(int newUseTime) {useTimeInMinutes = newUseTime;}

//Interface Methods
Station::Station() { //Default constructor
	id = -1;
	name = " ";
	useTimeInMinutes = 0;
}

Station::Station(int newId, std::string newName, int newUseTime) { //Basic Constructor
	id = newId;
	name = newName;
	useTimeInMinutes = newUseTime;
}

Station::Station(Station const &copy) {
	id = copy.getId();
	name = copy.getName();
	useTimeInMinutes = copy.getUseTime();
}

std::ostream & operator <<(std::ostream & buffer, Station &obj) {
	buffer << obj.getId() << " " << obj.getName() << " " << obj.getUseTime() << std::endl;
	return buffer;
}