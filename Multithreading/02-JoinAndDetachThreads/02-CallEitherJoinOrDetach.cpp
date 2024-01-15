#include <iostream>
#include <thread>

class WorkerThread {
public:
	void operator()() {
		std::cout << "Worker Thread" << std::endl;
	}
};

int main() {
	std::thread threadObject((WorkerThread()));

	// Program will terminate as we have't called either join or detach with the std::thread object.
	// Hence std::thread's object destructor will terminate the program

	return 0;
}

/*
* Output:
* terminate called without an active exception
* Aborted (core dumped)
*/
