// constructor of base class is called first to initialize all the inherited members

#include <iostream>

class Parent {
public:
	Parent() {
		std::cout << "Inside base class" << std::endl;
	}
};

class Child : public Parent {
public:
	Child() {
		std::cout << "Inside sub class" << std::endl;
	}
};

int main() {
	Child obj;

	return 0;
}

/*
Output:
Inside base class
Inside sub class
*/
