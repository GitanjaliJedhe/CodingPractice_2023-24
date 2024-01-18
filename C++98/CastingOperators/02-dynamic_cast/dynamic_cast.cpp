// The dynamic_cast operator is mainly used to perform downcasting (converting a pointer/reference of a base class to a derived class)
// If the conversion is not possible, dynamic_cast returns a null pointer (for pointer conversions) or throws a bad_cast exception

#include <iostream>

// Base Class 
class Animal {
public:
	virtual void speak() const {
		std::cout << "Animal Speaks" << std::endl;
	}
};

// Derived Class 
class Dog : public Animal {
public:
	void speak() const override {
		std::cout << "Dog Barks" << std::endl;
	}
};

// Derived Class 
class Cat : public Animal {
public:
	void speak() const override {
		std::cout << "Cat Meows" << std::endl;
	}
};

int main() {
	// base class pointer to derived class object 
	Animal* animalPtr = new Dog();

	// downcasting 
	Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
	// checking if the typecasting is successfull 
	if (dogPtr) {
		dogPtr->speak();
	}
	else {
		std::cout << "Failed to cast to Dog." << std::endl;
	}

	// typecasting to other dervied class 
	Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
	if (catPtr) {
		catPtr->speak();
	}
	else {
		std::cout << "Failed to cast to Cat." << std::endl;
	}

	delete animalPtr;

	return 0;
}

/*
Output:
Dog Barks
Failed to cast to Cat.
*/
