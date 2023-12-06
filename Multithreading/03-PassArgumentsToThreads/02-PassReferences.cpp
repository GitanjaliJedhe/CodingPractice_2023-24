// Using std::ref()

#include <iostream>
#include <thread>

void threadCallback(const int &n) {
	int &x = const_cast<int&>(n);

	x++;

	std::cout << "Inside Thread n = " << n << std::endl;

}

int main() {
	int n = 9;
	
	std::cout << "In Main Thread : Before Thread Start n = " << n << std::endl;

	// Using std::ref()
	std::thread threadObject(threadCallback, std::ref(n));

	threadObject.join();

	std::cout << "In Main Thread : After Thread Join n = " << n << std::endl;

	return 0;
}

/*
* Output:
In Main Thread : Before Thread Start n = 9
Inside Thread n = 10
In Main Thread : After Thread Join n = 10
*/
