#ifndef STATION_HPP
#define STATION_HPP

#include <string>
#include <iomanip>

class Station {
	private:
		int id, useTimeInMinutes, labNumber;
		std::string name;
	public:
		// Accessors
		int getId() const;
		std::string getName() const;
		int getUseTime() const;

		// Modifiers
		void setId(int newId);
		void setName(std::string newName);
		void setUseTime(int newUseTime);

		// Interface Methods
		Station();
		
		Station(int newLabNumber);

		Station(int newId, std::string newName, int newUseTime);

		Station(Station const &copy);
};

std::ostream & operator <<(std::ostream & buffer, Station &obj);

#endif
