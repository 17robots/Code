/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CSII assignment 1
   Author.  Matthew Dray
   Version. 1.01 09.09.2017
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream class

// build your class and member functions here
class Complex {
private:
double a, b;

public:
    Complex() {a = 0; b = 0;} // Default Constructor
    Complex(double A, double B) {a = A; b = B;} //Basic Constructor

	// Precondition: B is an initialized object
	// Postcondition: returns a Complex that has the real parts of this and
	// B together and the imaginary parts of this and B together
    Complex add(Complex &B) {
        return Complex(a + B.getA(), b + B.getB());
    }

	//Precondition: B is an initialized Complex object
	//Postcondition: Returns a Complex that contains the difference of the real
	//parts and the difference of the imaginary parts (B's parts minus these
	//parts)
    Complex subtract(Complex &B) {
        return Complex(B.getA() - a, B.getB() - b);
    }

	// Precondition: B is an initialized Complex object
	// Postcondition: returns a Complex with the foiled answers stored in it 
    Complex multiply(Complex &B) {
        return Complex(((a * B.getA()) + (-1 * (b * B.getB()))),((a * B.getB()) + (b * B.getA())));
    }
	
	// Precondition: a and b are properly initialized 
	// Postcondition: returns a string that prints the variables
    std::string toString() {
        std::ostringstream buffer;

        buffer << "(" << a << " + " << b << "i)";

        return buffer.str();
    }

	// Precondition: A and B are properly initialized doubles
	// Postcondition: sets the a and b values of the Complex object
    void setComplexNumber(double A, double B) {
        a = A;
        b = B;
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the + operator by returning the sum of the
	// parts of the Complex numbers
    Complex operator+(const Complex &B) {
        return Complex(B.getA() + a, B.getB() + b);
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the - operator by returning the difference of
	// B and this complex object
    Complex operator-(const Complex &B) {
        return Complex(B.getA() - a, B.getB()-b);
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the * operator by returning the product of the
	// two binomial complex numbers
    Complex operator*(const Complex &B) {
        return Complex((a * B.getA()) + (-1 *(b * B.getB())), (a * B.getB()) + (b * B.getA()));
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the << operator by returning an ostream buffer
	// with what should be outputted
    friend std::ostream &operator<<(std::ostream& buffer, const Complex &B) {
        buffer << "(" << B.getA() << " + " << B.getB() << "i)";
        return buffer;
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the >> operator by reading in its own values
	// and setting the complex number of B
    friend std::istream &operator>>(std::istream& buffer, Complex &B) {
        double a,b;
        buffer.ignore(1);
        buffer >> a;
        buffer.ignore(2);
        buffer >> b;

        B.setComplexNumber(a, b);
        buffer.ignore(1);
        buffer.ignore(1);
        return buffer;
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the = operator by setting the parts of B into
	// this object
    void operator=(const Complex &B) {
        a = B.getA();
        b = B.getB();
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the == operator by returning a bool checking
	// whether or not the parts of this are equal to the parts of B
    bool operator == (const Complex &B) {
        return (a == B.getA() && b == B.getB());
    }

	// Precondition: B is a properly initialized Complex object
	// Postcondition: overrides the != operator by returning a bool that checks
	// whether the parts of B are not equal to the parts of this object
    bool operator != (const Complex &B) {
        return !(a == B.getA() && b == B.getB());
    }

	// Precondition: a is initialized properly
	// Postcondition: returns a
    double getA() const {return a;}

	// Precondition: b is initialized properly
	// Postcondition: returns b
    double getB() const {return b;}
};

int main()
{
   for (double i = 1; i < 100; ++ i)
   {
     Complex a = Complex(i * 2, i + 2);
     Complex b = Complex(i * 3, i + 3);

     Complex c = a.add(b); // invoke add function and assign to object c
     std::cout << "Test case for Complex: add " << std::endl;
     std::cout << a.toString() << " + " << b.toString() << " = " << c.toString() << std::endl;
     std::cout << std::endl;

     a.setComplexNumber(i * 2, i + 2); // reset realPart and
     b.setComplexNumber(i * 3, i + 3); // and imaginaryPart

     std::cout << "Test case for Complex: subtract " << std::endl;
     c = a.subtract(b); // invoke subtract function and assign to object c
     std::cout << a.toString() << " - " << b.toString() << " = " << c.toString() << std::endl;
     std::cout << std::endl;

     a.setComplexNumber(i * 2, i + 2); // reset realPart and
     b.setComplexNumber(i * 3, i + 3); // and imaginaryPart

     std::cout << "Test case for Complex: multiply " << std::endl;
     c = a.multiply(b); // invoke multiply function and assign to object c
     std::cout << a.toString() << " * " << b.toString() << " = " << c.toString() << std::endl;
     std::cout << std::endl;
   }

//  THE FOLLOWING CODE FOR TESTING YOUR OVERLOADING ...

   for (double i = 1; i < 10; ++ i)
   {
     Complex y{i * 2.7, i + 3.2};
     Complex z{i * 6, i + 8.3};

     Complex x;
     Complex k;

     std::cout << "Enter a complex number in the form: (a, b)\n? ";
     std::cin >> k; // demonstrating overloaded >>
     std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
               << k << '\n'; // demonstrating overloaded <<
     x = y + z; // demonstrating overloaded + and =
     std::cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
     x = y - z; // demonstrating overloaded - and =
     std::cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
     x = y * z; // demonstrating overloaded * and =
     std::cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

     if (x != k) { // demonstrating overloaded !=
        std::cout << x << " != " << k << '\n';
     }

     std::cout << '\n';
     x = k;

     if (x == k) { // demonstrating overloaded ==
        std::cout << x << " == " << k << '\n';
     }
       std::cout << std::endl;
     }
     
return 0;
}

