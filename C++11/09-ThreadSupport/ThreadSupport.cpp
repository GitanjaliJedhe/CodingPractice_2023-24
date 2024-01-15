/*
C++11 added a standardized threading library that allows you to create and manage threads.
*/

#include <iostream>
#include <thread>

void my_function() {
	std::cout << "Inside thread" << std::endl;
}

int main() {
	std::thread th(my_function);
	// wait for the thread to finish
	th.join();

	return 0;
}

/*
Output:
Inside thread
*/
