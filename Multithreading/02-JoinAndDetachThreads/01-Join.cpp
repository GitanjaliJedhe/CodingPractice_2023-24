#include <iostream>
#include <thread>
#include <vector>

class WorkerThreadFunctor {
public:
	void operator()() {
		std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing" << std::endl;
	}
};

int main() {
	std::vector<std::thread> threadList;
	
	for (int i = 0; i < 10; i++) {
		threadList.push_back(std::thread(WorkerThreadFunctor()));
	}

	std::cout << "Wait for all the worker thread to finish" << std::endl;

	for (auto &th : threadList) {
		th.join();
	}

	std::cout << "Exiting from main thread" << std::endl;

	return 0;
}

/* 
* Output:
Wait for all the worker thread to finish
Worker Thread Worker Thread Worker Thread Worker Thread Worker Thread 27348 is Executing
Worker Thread 9656 is Executing
17432 is Executing
13904 is Executing
Worker Thread 17552 is Executing
Worker Thread 25392 is Executing
660 is Executing
19376 is Executing
Worker Thread 12424 is Executing
Worker Thread 21016 is Executing
Exiting from main thread
*/
