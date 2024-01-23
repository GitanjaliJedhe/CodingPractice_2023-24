#include <iostream>

class Base {
public:
	Base() {
		std::cout << "Constructing Base" << std::endl;
	}

	~Base() {
		std::cout << "Destructing Base" << std::endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		std::cout << "Constructing Derived" << std::endl;
	}

	~Derived() {
		std::cout << "Destructing Derived" << std::endl;
	}
};

int main() {
	Derived obj;

	return 0;
}

/*
Output:
Constructing Base
Constructing Derived
Destructing Derived
Destructing Base
*/
