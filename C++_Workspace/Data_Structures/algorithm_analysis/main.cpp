#include <iostream>
#include <time.h>

int main() {
	int sum = 0;
	for (int n = 2; n < 2048; n+=2) {
		time_t start = time(0);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < i; ++j) {
				for(int k = 0; k < j; ++k) {
					++sum;
				}
			}
		}
		double time_in_seconds = difftime(time(0), start);
		std::cout << "Done in " << time_in_seconds << " seconds\n";

	}

	return 0;
}
