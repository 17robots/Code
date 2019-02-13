#include <iostream>

int main() {
	char test = 191;
	int testInt = test & 0x3f; // grabs the last 6 bits from the right
	std::cout << testInt << std::endl;
	testInt = ((test >> 6) & 0x3); // grabs the first 2 bits from the left
	std::cout << testInt << std::endl;
	// rank = last 6 
	// suit = first 2
	// setting the bits for the constructor
	char suit = 3, rank = 4;
	int newtest = (suit << 6) | rank;
	std::cout << newtest << std::endl;	
	return 0;
}
