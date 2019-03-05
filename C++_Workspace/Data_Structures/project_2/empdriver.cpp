#include "empmaps.h"
#include <ctime>

void employee() {
	
}

void employees() {

}

int main() {
	employee(); // grab the file for data and read it in
	clock_t start, stop;
	start = clock();	
	stop = clock();
	
	std::cout << "clock ticks: " << double(stop-start) << '\n';
	return 0;
}
