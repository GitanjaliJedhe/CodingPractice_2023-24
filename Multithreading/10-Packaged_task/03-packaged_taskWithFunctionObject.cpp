#include <iostream>
#include <thread>
#include <future>
#include <string>

/*
 * Function Object to Fetch Data from DB
 */
struct DBDataFetcher {
	std::string operator()(std::string token) {
		// Do some stuff to fetch the data
		std::string data = "Data fetched from DB by Filter :: " + token;
		return data;
	}
};

int main() {
	// Create a packaged_task<> that encapsulated a Function Object
	std::packaged_task<std::string (std::string)> task(std::move(DBDataFetcher()));

	// Fetch the associated future<> from packaged_task<>
	std::future<std::string> result = task.get_future();

	// Pass the packaged_task to thread to run asynchronously
	std::thread th(std::move(task), "Args");

	// Join the thread. Its blocking and returns when thread is finished.
	th.join();

	// Fetch the result of packaged_task<> i.e. value returned by getDataFromDB()
	std::string data = result.get();

	std::cout << data << std::endl;

	return 0;
}

/*
* Output:
* Data fetched from DB by Filter :: Args
*/
