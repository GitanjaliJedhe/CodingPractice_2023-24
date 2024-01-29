#include <iostream>

// initialization of base class
class B {

};

// initialization of derived class
class D : public B {

};

int main() {
	B* b = new D(); // Base class pointer
	D* d = dynamic_cast<D*>(b); // Derived class pointer

	if (d != NULL)
		std::cout << "works" << std::endl;
	else
		std::cout << "cannot cast B* to D*";

	return 0;
}

/*
Output:
RTTI-01.cpp
RTTI-01.cpp(15): error C2683: 'dynamic_cast': 'B' is not a polymorphic type
RTTI-01.cpp(4): note: see declaration of 'B'
*/

