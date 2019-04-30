//DAD  ADE BAB  EAB   AAB  BAD  CAB  DAB  ABC  DAA

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

void countSort(std::vector<std::string> &arr, int stringLen) {
	const int BUCKETS = 256;
	
	int N = arr.size();
	std::vector<std::string> buffer(N);
	
	std::vector<std::string> *in = &arr;
	std::vector<std::string> *out = &buffer;
	
	for(int pos = stringLen - 1; pos >= 0; --pos) {
		std::vector<int> count(BUCKETS + 1);
		
		for(int i = 0; i < N; ++i)
			++count[(*in)[i][pos] + 1];
		
		std::cout << "Count: ";
		for(int x : count)
			std::cout << x << " ";
		std::cout << "\n";
			
		for(int b = 1; b <= BUCKETS; ++b)
			count[b] += count[b - 1];
		
		std::cout << "Count Indexes: ";
		for(int x : count)
			std::cout << x << " ";
		std::cout << "\n";
		
		for(int i = 0; i < N; ++i)
			(*out)[count[(*in)[i][pos]]++] = std::move((*in)[i]);
		
		std::cout << "Out: ";
		for(auto x : *out)
			std::cout << x << " ";
		std::cout << "\n";
		
		std::swap(in,out);
	}
	
	if(stringLen % 2 == 1)
		for(int i = 0; i < arr.size(); ++i)
			(*out)[i] = std::move((*in)[i]);
}

int main() {
	std::vector<std::string> words = { "DAD", "ADE", "BAB", "EAB", "AAB", "BAD", "CAB", "DAB", "ABC", "DAA" };
	
	std::cout << "Before: ";
	for(auto x : words)
		std::cout << x << " ";
	std::cout << "\n";
	
	std::cout << "================== Sorting ====================\n";
	
	countSort(words, 3);
	
	std::cout << "===============================================\n";
	
	std::cout << "After: ";
	for(auto x : words)
		std::cout << x << " ";
	std::cout << "\n";
	return 0;
}