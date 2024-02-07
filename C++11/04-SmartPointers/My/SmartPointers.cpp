#include <iostream>

class SmartPointer {
private:
	int* ptr;

public:
	SmartPointer(int *ptr_) {
		ptr = ptr_;
	}

	int& operator*() {
		return *ptr;
	}

	int* operator->() {
		ptr;
	}

	~SmartPointer() {
		delete ptr;
	}
};

int main() {
	SmartPointer ptr(new int());

	*ptr = 20;

	std::cout << *ptr << std::endl;

	return 0;
}

/*
Output:
20
*/
