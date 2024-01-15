#include <iostream>
#include <thread>

void func(int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "Thread using function pointer as callable" << std::endl;
	}
}

// A callable object
class threadObj {
public:
	void operator()(int n) {
		for (int i = 0; i < n; i++) {
			std::cout << "Thread using function object as callable" << std::endl;
		}
	}
};

// Class definition
class Base {
public:
	// Non-static member function
	void func() {
		std::cout << "Thread using non-static member function as callable" << std::endl;
	}

	// Static member function
	static void func1() {
		std::cout << "Thread using static member function as callable" << std::endl;
	}
};


int main() {

	// This thread is launched by using function pointer as callable
	std::thread threadObject1(func, 5);

	// This thread is launched by using function object as callable
	std::thread threadObject2(threadObj(), 5);

	// Define a Lambda Expression
	auto f = [](int n) {
		for (int i = 0; i < n; i++) {
			std::cout << "Thread using lambda expression as callable" << std::endl;
		}
	};

	// This thread is launched by using lambda expression as callable
	std::thread threadObject3(f, 5);

	// Object of Base Class
	Base bObject;

	// This thread is launched by using non-static member function as callable
	std::thread threadObject4(&Base::func, &bObject);

	// This thread is launched by using static member function as callable
	std::thread threadObject5(&Base::func1);

	threadObject1.join();

	threadObject2.join();

	threadObject3.join();

	threadObject4.join();

	threadObject5.join();

	return 0;
}

/*
* Output:
Thread using function pointer as callable
Thread using function pointer as callable
Thread using non-static member function as callable
Thread using function pointer as callable
Thread using function pointer as callable
Thread using lambda expression as callable
Thread using static member function as callable
Thread using function pointer as callable
Thread using function object as callable
Thread using function object as callable
Thread using lambda expression as callable
Thread using lambda expression as callable
Thread using lambda expression as callable
Thread using lambda expression as callable
Thread using function object as callable
Thread using function object as callable
Thread using function object as callable
*/
