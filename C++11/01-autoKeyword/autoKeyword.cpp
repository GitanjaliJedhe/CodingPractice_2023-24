/*
The auto keyword allows C++11 to automatically deduce the type of the variable 
from its initializer.
*/

#include <iostream>

int main() {
	// x is deduced as int
	auto x = 42;

	// pi is deduced as double
	auto pi = 3.141592;

	std::cout << "x: " << x << std::endl;
	std::cout << "pi: " << pi << std::endl;

	return 0;
}

/*
Output:
x: 42
pi: 3.14159
*/
