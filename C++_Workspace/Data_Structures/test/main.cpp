//DAD  ADE BAB  EAB   AAB  BAD  CAB  DAB  ABC  DAA

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

const int BUCKETS = 256;

void countSort(std::vector<std::string> &arr, int stringLen) {
	int N = arr.size();
	std::vector<std::string> buckets(BUCKETS + 1);
	std::vector<std::string> *in = &arr;
	std::vector<std::string> *out = &bucket;
}

int main() {
	std::vector<std::string> words = { "DAD", "ADE", "BAB", "EAB", "AAB", "BAD", "CAB", "DAB", "ABC", "DAA" };
	return 0;
}