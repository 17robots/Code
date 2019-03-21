#include <ctime>
#include <assert.h>
#include <iostream>

class Clock {
public:
	virtual std::time_t start() const = 0;
	virtual std::time_t now() const = 0;
};

class TimeClock : public Clock {
public:
	std::time_t start() const override { return now(); }
	std::time_t now() const override { return std::time(nullptr); }
};

class ConfigurableClock : public Clock {
public:
	ConfigurableClock(std::time_t amount) : length(amount) {}
	std::time_t start() const override { return 0; }
	std::time_t now() const override { std::cout << "ConfigurableClock override" << std::endl; std::cout << length << std::endl; return length; }
private:
	std::time_t length;
};

class Session {
public:
	Session() : start_time(std::time(nullptr)), end_time(0), clock(TimeClock()) { }
	Session(Clock& clock) : start_time(std::time(nullptr)), end_time(0), clock(clock) { }
	void stop() { end_time = clock.now(); }
	std::time_t seconds() { return end_time - start_time; }
private:
	std::time_t start_time, end_time;
	const Clock& clock; 
};

int main() {
	{
		ConfigurableClock clock(3600);
		Session s(clock);
		s.stop();
		std::cout << s.seconds() << std::endl;
		assert(s.seconds() == 60*60);
	}
}