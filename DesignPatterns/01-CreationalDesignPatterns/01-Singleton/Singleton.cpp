// Singleton is a Creational Design Pattern,
// which ensures that only one object of its kind existsand provides a single point of access to it for any other code.
// Example: Logger

#include <iostream>

using namespace std;

/**
 * The Singleton class defines the `get_instance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class Singleton {
	/*
	 * The Singleton's constructor should always be private to prevent direct
	 * construction calls with the `new` operator.
	 */
private:
	int m_value;

	static Singleton* s_instance;

	Singleton(int value) : m_value(value) {

	}

public:
	/*
	 * Singletons should not be cloneable.
	 */
	Singleton(const Singleton& other) = delete;

	/*
	 * Singletons should not be assignable.
	 */
	void operator=(const Singleton &other) = delete;

	/*
	 * This is the static method that controls the access to the singleton
	 * instance. On the first run, it creates a singleton object and places it
	 * into the static field. On subsequent runs, it returns the client existing
	 * object stored in the static field.
	 */
	static Singleton* get_instance(int value);

	/*
	 * Finally, any singleton should define some business logic, which can be
	 * executed on its instance.
	 */
	void SomeBusinessLogic() {
		// code
	}

	int get_value() const {
		return m_value;
	}

};

Singleton* Singleton::s_instance = nullptr;

/*
 * Static methods should be defined outside the class.
 */
Singleton* Singleton::get_instance(int value) {
	/*
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (s_instance == nullptr) {
		s_instance = new Singleton(value);
	}

	return s_instance;
}

void test_1() {
	Singleton *ptrSingleton = Singleton::get_instance(848);
	std::cout << "Inside test-01: " << ptrSingleton->get_value() << std::endl;
}

void test_2() {
	Singleton* ptrSingleton = Singleton::get_instance(393);
	std::cout << "Inside test-02: " << ptrSingleton->get_value() << std::endl;
}

int main() {

	std::cout << "If you see the same value, then singleton was reused\n" <<
		"If you see different values, then 2 singletons were created\n\n" <<
		"RESULT:\n";

	test_1();

	test_2();

	return 0;
}
