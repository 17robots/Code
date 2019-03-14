#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace json {
	void indent(std::ostream& os, int tab) {
		os << std::string(2 * tab, ' ')
	}
	
	// reprsent set of all values
	struct Value {
		virtual ~Value() = default;
		virtual int size() const { return 1; }
		virtual int height() const { return 0; }
		virtual void print(std::ostream& os) const = 0;
	};

	// Represents the value null
	struct Bool : Value {
		Bool(bool v): value(v) {}
		bool value;
		virtual void print(std::ostream& os, int tab) const override {
			indent(os, tab);
			os << value;
		}
	};

	// Represents the value null
	struct Null : Value {
		virtual void print(std::ostream& os) const override {
			indent(os, tab);
		}
	};

	// Represents numeric data 
	struct Number : Value {
		Number(double v): value(v) {}
		virtual void print(std::ostream& os, int tab) const override {
			indent(os, tab);
			os << value;
		}
		double value;
	};

	// Represents JSON String

	// We also inherit std::string for its 
	// implementation 
	struct String : Value, std::string  {
		using std::string;
		virtual void print(std::ostream& os) const override {
			indent(os, tab);
			os << *this;
		}
	};

	// Represents JSON Array
	// Implementing std::vector interface
	struct Array : Value, std::vector<Value*> {
		using std::vector<Value*>::vector;
		
		int size() const override {
			int n = 1;
			for(Value* v : *this) {
				n+= v->size();
			}
		}
		
		int height() const override {
			int n = std::max_element(begin(), end(),
			[](Value* a, Value* b) {
				return a->height() < b->height();
			});
			return 1 + n;
		}
		
		virtual void print(std::ostream& os, int tab) const override {
				
		}
	};

	// represents JSON objects
	// we hash on std::string (for ease of correct implementation) and 
	// definitely not on String* which would hash on addresses not string 
	// values
	struct Object : Value, std::unordered_map<std::string, Value*> {
		using std::unordered_map<std::string, Value*>::unordered_map;
		int size() const override {
			int n = 1;
			for(auto const& kv : *this) {
				n+= kv.second->size();
			}
			return n;
		}
		
		int height() const override {
			int n = std::max_element(begin(), end(),
			[](Value* a, Value* b) {
				return a->height() < b->height();
			});
			
			return 1 + n;
		}
		
		virtual void print(std::ostream& os, int tab) const override {
			
		}
	};
	
	Value* parse(const std::string& str) {
		
	}
};
