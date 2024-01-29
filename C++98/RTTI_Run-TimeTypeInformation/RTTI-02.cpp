#include <iostream>

// initialization of base class
class B {
	virtual void fun() {}
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
works
*/
