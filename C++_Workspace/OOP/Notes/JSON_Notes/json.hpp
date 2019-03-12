#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace json {
	// reprsent set of all values
	struct Value {};

	// Represents the value null
	struct Bool : Value {
		bool value;
	};

	// Represents the value null
	struct Null : Value {};

	// Represents numeric data 
	struct Number : Value {
		double value;
	};

	// Represents JSON String

	// We also inherit std::string for its 
	// implementation 
	struct String : Value, std::string  {};

	// Represents JSON Array
	// Implementing std::vector interface
	struct Array : Value, std::vector<Value*> {};

	// represents JSON objects
	// we hash on std::string (for ease of correct implementation) and 
	// definitely not on String* which would hash on addresses not string 
	// values
	struct Object : Value, std::unordered_map<std::string, Value*> {};
};
