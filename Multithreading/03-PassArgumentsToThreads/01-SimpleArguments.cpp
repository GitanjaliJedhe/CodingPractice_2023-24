#include <iostream>
#include <thread>
#include <string>

void threadCallback(int n, std::string str) {
	std::cout << "Passed Number = " << n << std::endl;
	std::cout << "Passed String = " << str << std::endl;
}


int main() {
	int n = 10;
	std::string str = "Sample String";

	std::thread threadObject(threadCallback, n, str);

	threadObject.join();

	return 0;
}

/*
* Output:
Passed Number = 10
Passed String = Sample String
*/
