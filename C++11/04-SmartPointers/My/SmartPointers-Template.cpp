#include <iostream>

template <class T>
class SmartPointer {
private:
	T* ptr;

public:
	SmartPointer(int *ptr_) {
		ptr = ptr_;
	}

	T& operator*() {
		return *ptr;
	}

	T* operator->() {
		ptr;
	}

	~SmartPointer() {
		delete ptr;
	}
};

int main() {
	SmartPointer<int> ptr(new int());

	*ptr = 30;

	std::cout << *ptr << std::endl;

	return 0;
}

/*
Output:
30
*/
