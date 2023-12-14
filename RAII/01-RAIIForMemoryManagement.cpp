/*
* In this example, we define a memory_block class that manages a block of memory.
The constructor of the class allocates memory and initializes the data members, 
while the destructor is responsible for deallocating the memory. 
By using RAII, we ensure that the memory is automatically released when the memory_block object goes out of scope, preventing memory leaks.
*/

#include <iostream>

class MemoryBlock {
private:
	size_t size_;
	int *data_;

public:
	MemoryBlock(size_t size) : size_(size), data_(new int[size]) {
		std::cout << "Allocated memory block of size: " << size_ << std::endl;
	}

	~MemoryBlock() {
		std::cout << "Deallocating memory block of size: " << size_ << std::endl;
		delete[]data_;
	}

	int* data() const {
		return data_;
	}

	size_t size() const {
		return size_;
	}
};

int main() {
	{
		MemoryBlock block(10);
	}

	// memory_block goes out of scope and its destructor is called,
    // releasing the memory

	std::cout << "Exiting main function" << std::endl;

	return 0;
}

/*
* Output:
Allocated memory block of size: 10
Deallocating memory block of size: 10
Exiting main function
*/
