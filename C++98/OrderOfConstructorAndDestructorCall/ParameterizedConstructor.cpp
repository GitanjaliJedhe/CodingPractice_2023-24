/*
Whenever the derived class’s default constructor is called, the base class’s default constructor is called automatically.

To call the parameterized constructor of base class inside the parameterized constructor of sub class, we have to mention it explicitly.

The parameterized constructor of base class cannot be called in default constructor of sub class, 
it should be called in the parameterized constructor of sub class.
*/

#include <iostream>

class Parent {
private:
	int x;

public:
	Parent(int x_) : x(x_) {
		std::cout << "Inside base class's parameterized constructor" << std::endl;
	}
};

class Child : public Parent {
public:
	Child(int x_) : Parent(x_) {
		std::cout << "Inside child class's parameterized constructor" << std::endl;
	}
};

int main() {
	Child obj(453);

	return 0;
}

/*
Output:
Inside base class's parameterized constructor
Inside child class's parameterized constructor
*/
