/*
For example,
Suppose we are building a network based application. This application does following tasks,
Perform some handshaking with server
Load Data from XML files.
Do processing on data loaded from XML.

Responsibilities of Thread 1 are,
	Perform some handshaking with server.
	Wait for data to be loaded from XML by Thread 2
	Do processing on data loaded from XML.

Responsibilities of Thread 2 are,
	Load data from XML
	Notify another Thread i.e. waiting for the message.
*/

#include <iostream>
#include <thread>
#include <mutex>

class Application {
private:
	std::mutex m_mutex;
	bool m_bDataLoaded;

public:
	Application() {
		m_bDataLoaded = false;
	}

	void loadData() {
		// Make This Thread sleep for 1 Second
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "Loading Data from XML" << std::endl;

		// Lock The Data structure
		std::lock_guard<std::mutex> lockGuard(m_mutex);

		// Set the flag to true, means data is loaded
		m_bDataLoaded = true;
	}

	void mainTask() {
		std::cout << "Do Some Handshaking" << std::endl;

		// Acquire the Lock
		m_mutex.lock();

		// Check if flag is set to true or not
		while (m_bDataLoaded != true) {
			// Release the lock
			m_mutex.unlock();

			//sleep for 100 milli seconds
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			// Acquire the lock
			m_mutex.lock();
		}

		// Release the lock
		m_mutex.unlock();

		//Doc processing on loaded Data
		std::cout << "Do Processing on loaded Data" << std::endl;
	}
};

int main() {
	Application appObject;

	std::thread thread_1(&Application::mainTask, &appObject);
	std::thread thread_2(&Application::loadData, &appObject);

	thread_2.join();
	thread_1.join();

	return 0;
}

/*
* Output:
Do Some Handshaking
Loading Data from XML
Do Processing on loaded Data
*/
