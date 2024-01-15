#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <future>

std::string fetchDataFromFile(std::string recvdData) {
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(std::chrono::seconds(5));

	//Do stuff like fetching Data File
	return "File_" + recvdData;
}

int main() {
	// Get Start Time
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	//Calling std::async with lambda function
	std::future<std::string> resultFromDB = std::async([](std::string recvdData) {
			std::this_thread::sleep_for(std::chrono::seconds(5));

			//Do stuff like creating DB Connection and fetching Data
			return "DB_" + recvdData;
		}, "Data");

	//Fetch Data from File
	std::string fileData = fetchDataFromFile("Data");

	//Fetch Data from DB
	// Will block till data is available in future<std::string> object.
	std::string dbData = resultFromDB.get();

	// Get End Time
	auto end = std::chrono::system_clock::now();

	auto diff = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

	//Combine The Data
	std::string data = dbData + " :: " + fileData;

	//Printing the combined Data
	std::cout << "Data = " << data << std::endl;

	return 0;
}

/*
* Output:
Total Time Taken = 10 Seconds
Data = DB_Data :: File_Data
*/
