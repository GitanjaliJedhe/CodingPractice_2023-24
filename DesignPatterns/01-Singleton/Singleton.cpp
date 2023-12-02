// Example: Logger

#include <iostream>

using namespace std;

class Singleton {
private:
	int m_value;

	static Singleton* s_instance;

	Singleton(int value) : m_value(value) {

	}

public:
	Singleton(const Singleton& other) = delete;

	void operator=(const Singleton &other) = delete;

	static Singleton* get_instance(int value);

	void SomeBusinessLogic() {
		// code
	}

	int get_value() const {
		return m_value;
	}

};

Singleton* Singleton::s_instance = nullptr;

Singleton* Singleton::get_instance(int value) {
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

	test_1();

	test_2();

	return 0;
}
