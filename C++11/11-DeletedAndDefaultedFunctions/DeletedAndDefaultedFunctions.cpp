/*
Deleted Function:
Deleting functions is useful when you want to prevent certain operations on your class.
Defaulted Function:
They are used to explicitly request the compiler to 
generate default implementations for certain member functions.
*/

#include <iostream>

class Example {
private:

public:
	Example() = default;
	Example(const Example& other) = delete;
};

int main() {
	// allowed: default constructor is used
	Example obj1;

	// error: copy constructor is deleted
	// Example obj2 = obj1;

	return 0;
}

/*
Output:
*/
