#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace json {
	
	struct Visitor;
	struct SizeVisitor;
	struct Value;
	struct Null;
	struct Bool;
	struct Number;
	struct String;
	struct Array;
	struct Object;
	
	// visitor algorithm creates dispatchers for the different types
	struct Visitor {
		virtual void visit(Null const& n) {}
		virtual void visit(Bool const& n) {}
		virtual void visit(Number const& n) {}
		virtual void visit(String const& n) {}
		virtual void visit(Array const& n) {}
		virtual void visit(Object const& n) {}
	};
	
	// Defines the actual behaviors for the size() function
	struct SizeVisitor : Visitor {
		virtual void visit override (Null const& n) { ret = 1; }
		virtual void visit override (Bool const& n) { ret = 1; }
		virtual void visitoverride (Number const& n) { ret = 1; }
		virtual void visit override (String const& n) { ret = 1; }
		virtual void visit override (Array const& n) {ret = n.size(); }
		virtual void visit override (Object const& n) { ret = n.size(); }
		
		// since the visit functions return null, we need to cache the bool in the state of the visitor
		bool ret = 0;
	};
	
	void indent(std::ostream& os, int tab) {
		os << std::string(2 * tab, ' ')
	}
	
	// reprsent set of all values
	struct Value {
		// the accept function dispatches to a row in
		// the table, defined by the visitor
		virtual void accept(Visitor& vis) = 0;
		virtual ~Value() = default;
		virtual int size() const { return 1; }
		virtual int height() const { return 0; }
		virtual void print(std::ostream& os) const = 0;
	};

	// Represents the value null
	struct Bool : Value {
		bool value;
		Bool(bool v): value(v) {}
		
		virtual void print(std::ostream& os, int tab) const override {
			indent(os, tab);
			os << value;
		}
		
		void accept(Visitor& vis) override {
			return vis.visit(*this);
		}
	};

	// Represents the value null
	struct Null : Value {
		void print(std::ostream& os) const override {
			indent(os, tab);
		}
		
		void accept(Visitor& vis) override {
			return vis.visit(*this);
		}
	};

	// Represents numeric data 
	struct Number : Value {
		double value;
		
		Number(double v): value(v) {}
		
		void print(std::ostream& os, int tab) const override {
			indent(os, tab);
			os << value;
		}
		
		void accept(Visitor& vis) override {
			return vis.visit(*this);
		}
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
		
		void accept(Visitor& vis) override {
			return vis.visit(*this);
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
		
		void accept(Visitor& vis) override {
			return vis.visit(*this);
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
		
		void accept(Visitor& vis) override {
			return vis.visit(*this);
		}
	};
	
	Value* parse(const std::string& str) {
		
	}
};
