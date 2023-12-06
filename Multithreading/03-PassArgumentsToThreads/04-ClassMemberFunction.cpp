#include <iostream>
#include <thread>

class dummyClass {
public:
	dummyClass() {
	}

	dummyClass(const dummyClass &obj) {
	}

	void sampleMemberFunction(int n) {
		std::cout << "Inside sampleMemberFunction() " << n << std::endl;
	}

};

int main() {
	dummyClass dummyObject;

	int n = 10;

	std::thread threadObject(&dummyClass::sampleMemberFunction, &dummyObject, n);

	threadObject.join();

	return 0;
}

/*
* Output:
* Inside sampleMemberFunction() 10
*/
