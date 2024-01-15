/*
C++11 introduced smart pointers that automatically manage memory and help prevent memory leaks. 
Basically, a smart pointer automatically releases the memory it manages when it goes out of scope.

Smart pointers are of two types:
Unique Pointers have exclusive ownership of the objects they point to.
Shared Pointers allow multiple shared pointers to own a single object.
*/

#include <iostream>
#include <memory>

int main() {
	std::shared_ptr<int> shared_pointer = std::make_shared<int>(42);

	std::unique_ptr<double> unique_pointer = std::make_unique<double>(3.14);

	std::cout << "shared_pointer: " << *shared_pointer << std::endl;

	std::cout << "unique_pointer: " << *unique_pointer << std::endl;

	return 0;
}

/*
Output:
shared_pointer: 42
unique_pointer: 3.14
*/
