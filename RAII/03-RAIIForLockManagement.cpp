/*
In this example, we define a lock_guard class that manages a mutex lock.
The constructor of the class locks the mutex, and the destructor unlocks it.
By using RAII, we ensure that the lock is automatically released when the lock_guard object goes out of scope, 
preventing deadlocks and improving overall thread safety.
*/

#include <iostream>
#include <thread>
#include <mutex>

class LockGuard {
private:
	std::mutex& mtx_;

public:
	explicit LockGuard(std::mutex& mtx) : mtx_(mtx) {
		mtx_.lock();
	}

	~LockGuard() {
		mtx_.unlock();
	}

	// Disable copy constructor and assignment operator
	LockGuard(const LockGuard&) = delete;
	LockGuard& operator=(const LockGuard&) = delete;
};

void printWithLock(std::mutex &mtx, const std::string &msg) {
	LockGuard lock(mtx);

	std::cout << msg << std::endl;
}

int main() {
	std::mutex print_mtx;

	std::thread th1(printWithLock, std::ref(print_mtx), "Hello from thread 1");

	std::thread th2(printWithLock, std::ref(print_mtx), "Hello from thread 2");

	std::thread th3(printWithLock, std::ref(print_mtx), "Hello from thread 3");

	th1.join();
	th2.join();
	th3.join();

	std::cout << "Exiting main function" << std::endl;

	return 0;
}

/* 
* Output:
Hello from thread 2
Hello from thread 1
Hello from thread 3
Exiting main function
*/
