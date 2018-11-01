#ifndef STATION_HPP
#define STATION_HPP

class Station {
	private:
		int id;
		std::string name;
		int useTimeInMinutes;
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

		Station(int newId, std::string newName, int newUseTime);

		Station(Station const &copy);
};

#endif