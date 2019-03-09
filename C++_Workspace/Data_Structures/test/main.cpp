#include <iostream>

struct Test {
	Test(int x) : number(x) {} 
	int number;
};


int main() {
	std::cout << "Enter a number: ";
	Test test(static_cast<int>(std::cin));
	return 0;
}
