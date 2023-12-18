/*
Example:

We’ll have two styles of pizza: “New York” and “Chicago,” each with its own set of pizza types.

Step 1: We’ll define an abstract factory interface (PizzaFactory) with methods for creating different types of pizzas for different styles.
Step 2: We’ll create two concrete factories (NewYorkPizzaFactory and ChicagoPizzaFactory) implementing this interface 
and create corresponding New York and Chicago style pizzas.
Step 3: We’ll create an abstract product interface (Pizza) that defines the methods that concrete pizzas must implement.
Concrete pizza classes (NewYorkCheesePizza, NewYorkPepperoniPizza, ChicagoCheesePizza, ChicagoPepperoniPizza) 
implement the abstract Pizza interface for each style.

The client code will create and prepare pizzas using the abstract factories and interact with them 
without needing to know the specific pizza styles or implementations.
*/

#include <iostream>

// Abstract Product Interface
class Pizza {
public:
	virtual void bake() = 0;
	virtual void cut() = 0;
	virtual void box() = 0;
};

// Concrete New York Cheese Pizza
class NewYorkCheesePizza : public Pizza {
public:
	void bake() override {
		std::cout << "Baking New York-style cheese pizza." << std::endl;
	}

	void cut() override {
		std::cout << "Cutting New York-style cheese pizza." << std::endl;
	}

	void box() override {
		std::cout << "Boxing New York-style cheese pizza." << std::endl;
	}
};

// Concrete New York Pepperoni Pizza
class NewYorkPepperoniPizza : public Pizza {
public:
	void bake() override {
		std::cout << "Baking New York-style pepperoni pizza." << std::endl;
	}

	void cut() override {
		std::cout << "Cutting New York-style pepperoni pizza." << std::endl;
	}

	void box() override {
		std::cout << "Boxing New York-style pepperoni pizza." << std::endl;
	}
};

// Concrete Chicago Cheese Pizza
class ChicagoCheesePizza : public Pizza {
public:
	void bake() override {
		std::cout << "Baking Chicago-style cheese pizza." << std::endl;
	}

	void cut() override {
		std::cout << "Cutting Chicago-style cheese pizza." << std::endl;
	}

	void box() override {
		std::cout << "Boxing Chicago-style cheese pizza." << std::endl;
	}
};

// Concrete Chicago Pepperoni Pizza
class ChicagoPepperoniPizza : public Pizza {
public:
	void bake() override {
		std::cout << "Baking Chicago-style pepperoni pizza." << std::endl;
	}

	void cut() override {
		std::cout << "Cutting Chicago-style pepperoni pizza." << std::endl;
	}

	void box() override {
		std::cout << "Boxing Chicago-style pepperoni pizza." << std::endl;
	}
};

// Abstract Factory Interface
class PizzaFactory {
public:
	virtual Pizza* createCheesePizza() = 0;
	virtual Pizza* createPepperoniPizza() = 0;
};

// Concrete New York Pizza Factory
class NewYorkPizzaFactory : public PizzaFactory {
public:
	Pizza* createCheesePizza() override {
		return new NewYorkCheesePizza();
	}

	Pizza* createPepperoniPizza() override{
		return new NewYorkPepperoniPizza();
	}
};

// Concrete Chicago Pizza Factory
class ChicagoPizzaFactory : public PizzaFactory {
public:
	Pizza* createCheesePizza() override {
		return new ChicagoCheesePizza();
	}

	Pizza* createPepperoniPizza() override {
		return new ChicagoPepperoniPizza();
	}
};

int main() {
	// Create a New York Pizza Factory
	PizzaFactory* newYorkFactory = new NewYorkPizzaFactory();
	Pizza* newYorkCheesePizza = newYorkFactory->createCheesePizza();
	Pizza* newYorkPepperoniPizza = newYorkFactory->createPepperoniPizza();

	// Create a Chicago Pizza Factory
	PizzaFactory* chicagoFactory = new ChicagoPizzaFactory();
	Pizza* chicagoCheesePizza = chicagoFactory->createCheesePizza();
	Pizza* chicagoPepperoniPizza = chicagoFactory->createPepperoniPizza();

	// Order and prepare the pizzas
	newYorkCheesePizza->bake();
	newYorkCheesePizza->cut();
	newYorkCheesePizza->box();

	newYorkPepperoniPizza->bake();
	newYorkPepperoniPizza->cut();
	newYorkPepperoniPizza->box();

	chicagoCheesePizza->bake();
	chicagoCheesePizza->cut();
	chicagoCheesePizza->box();

	chicagoPepperoniPizza->bake();
	chicagoPepperoniPizza->cut();
	chicagoPepperoniPizza->box();

	// Clean up
	delete newYorkFactory;
	delete newYorkCheesePizza;
	delete newYorkPepperoniPizza;

	delete chicagoFactory;
	delete chicagoCheesePizza;
	delete chicagoPepperoniPizza;

	return 0;
}

/*
* Output:
Baking New York-style cheese pizza.
Cutting New York-style cheese pizza.
Boxing New York-style cheese pizza.
Baking New York-style pepperoni pizza.
Cutting New York-style pepperoni pizza.
Boxing New York-style pepperoni pizza.
Baking Chicago-style cheese pizza.
Cutting Chicago-style cheese pizza.
Boxing Chicago-style cheese pizza.
Baking Chicago-style pepperoni pizza.
Cutting Chicago-style pepperoni pizza.
Boxing Chicago-style pepperoni pizza.
*/
