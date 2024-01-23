// For multiple inheritance order of constructor call is, 
// the base class’s constructors are called in the order of inheritanceand then the derived class’s constructor.

#include <iostream>

class Parent1 {
public:
	Parent1() {
		std::cout << "Inside first base class" << std::endl;
	}
};

class Parent2 {
public:
	Parent2() {
		std::cout << "Inside second base class" << std::endl;
	}
};

class Child : public Parent1, public Parent2 {
public:
	Child() {
		std::cout << "Inside child class" << std::endl;
	}
};

int main() {
	Child obj;

	return 0;
}

/*
Output:
Inside first base class
Inside second base class
Inside child class
*/
