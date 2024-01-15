/*
*This implementation demonstrates the Factory Method Pattern, where:

The abstract creator (ShapeFactory) defines the factory method (createShape())
Concrete creators (CircleFactory and SquareFactory) implement this method to create concrete prodcuts (Circle and Square).
The client code interacts with the abstract creator, creating products without needing to know their specific types.
This promotes flexibility and decoupling between the client and product classes.
*/

#include <iostream>

// Abstract product class
class Shape {
public:
	virtual void draw() = 0;

	// Virtual destructor for polymorphism
	virtual ~Shape() {
	} 
};

// Concrete product class - Circle
class Circle : public Shape {
public:
	void draw() override{
		std::cout << "Drawing a Circle" << std::endl;
	}
};

// Concrete product class - Square
class Square : public Shape {
public:
	void draw() override{
		std::cout << "Drawing a Square" << std::endl;
	}
};

// Abstract creator class
class ShapeFactory {
public:
	virtual Shape* createShape() = 0;

	// Virtual destructor for polymorphism
	virtual ~ShapeFactory() {
	}
};

// Concrete creator class - CircleFactory
class CircleFactory : public ShapeFactory {
public:
	Shape* createShape() override {
		return new Circle();
	}
};

// Concrete creator class - SquareFactory
class SquareFactory : public ShapeFactory {
public:
	Shape* createShape() override {
		return new Square();
	}
};

int main() {
	ShapeFactory* circleFactory = new CircleFactory();
	ShapeFactory* squareFactory = new SquareFactory();

	Shape* circle = circleFactory->createShape();
	Shape* square = squareFactory->createShape();

	circle->draw();
	square->draw();

	delete square;
	delete circle;

	delete squareFactory;
	delete circleFactory;

	return 0;
}

/*
* Output:
Drawing a Circle
Drawing a Square
*/
