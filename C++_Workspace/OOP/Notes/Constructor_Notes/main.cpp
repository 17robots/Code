#include <iostream>
#include <vector>

// using the virtual constructor pattern

// when using virtual functions, also have a virtual destructor
struct Value {
   virtual Value* clone() const = 0; 
   virtual ~Value() {}
};

// Value is interface inheritance \
Vector is implementation inheritance
struct Array : Value, std::vector<Value*> {
    Array(int n) : Value(), std::vector<Value*>(n) {}
    Array* clone() const override {
        return new Array(*this);
    }
    ~Array() {}
};

Value* copy(Value* p) {
    return p->clone();
}

void kill(Value *p) {
    delete p;
}

int main() {
    kill(new Array(1 << 20));
    return 0;
}

