#include <iostream>
#include <thread>

void threadFunc() {
	std::cout << "Inside Thread :: ID = " << std::this_thread::get_id() << std::endl;
}

int main() {
	std::thread threadObject1(threadFunc);
	std::thread threadObject2(threadFunc);

	if (threadObject1.get_id() != threadObject2.get_id()) {
		std::cout << "Both thread have different IDs" << std::endl;
	}

	std::cout << "Inside Main Thread :: ID of Thread 1 = " << threadObject1.get_id() << std::endl;
	std::cout << "Inside Main Thread :: ID of Thread 2 = " << threadObject2.get_id() << std::endl;

	threadObject1.join();
	threadObject2.join();

	return 0;
}

/* 
* Output:
Both thread have different IDs
Inside Main Thread :: ID of Thread 1 = 9476
Inside Main Thread :: ID of Thread 2 = 11112
Inside Thread :: ID = 9476
Inside Thread :: ID = 11112
*/
