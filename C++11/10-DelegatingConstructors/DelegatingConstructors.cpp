/*
a constructor may call another constructor of the same class
*/

#include <iostream>

class test {
private:
	int x;
	int y;

public:
	// constructor #1 (target constructor)
	test(int x_, int y_) : x(x_), y(y_) {
	}

	// constructor #2 (delegating constructor)
	// pass two zeroes as arguments to target constructor 
	// the delegating constructor invokes the target constructor.
	test() : test(0, 0) {
		std::cout << "Delegating constructor" << std::endl;
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;
	}
};

int main() {
	// create an instance of class M
	// using the delegating constructor
	test t;

	return 0;
}

/*
Output: 
Delegating constructor
x = 0
y = 0
*/
