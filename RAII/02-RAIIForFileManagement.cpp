/*
In this example, we define a file_wrapper class that manages a file stream.
The constructor of the class opens the file and throws an exception if the file cannot be opened.
The destructor closes the file.
By using RAII, we ensure that the file is automatically closed when the file_wrapper object goes out of scope, 
preventing resource leaks and ensuring proper file management.
*/

#include <iostream>
#include <fstream>
#include <stdexcept>

class FileWrapper {
private:
	std::fstream file_stream_;

public:
	FileWrapper(const std::string& file_name) : file_stream_(file_name) {
		if (!file_stream_.is_open()) {
			throw std::runtime_error("Failed to open file: " + file_name);
		}

		std::cout << "Opened file: " << file_name << std::endl;
	}

	~FileWrapper() {
		std::cout << "Closing file" << std::endl;
		file_stream_.close();
	}

};

int main() {
	try {
		FileWrapper file("example.txt");
		// Perform file operations using file.stream()
	}
	catch (const std::runtime_error &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "Exiting main function" << std::endl;

	return 0;
}

/*
* Output:
Error: Failed to open file: example.txt
*/
