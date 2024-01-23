/*
Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. 
To correct this situation, the base class should be defined with a virtual destructor.
*/

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
	Base *pBase = new Derived();

	delete pBase;

	return 0;
}

/*
Output:
Constructing Base
Constructing Derived
Destructing Base
*/
