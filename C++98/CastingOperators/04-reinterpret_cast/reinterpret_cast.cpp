// reinterpret_cast operator is used to convert the pointer to any other type of pointer. 
// It does not perform any check whether the pointer converted is of the same type or not.

#include <iostream>

int main() {
	int num = 543;
	int* intPtr = &num;

	char* charPtr = reinterpret_cast<char *>(intPtr);

	std::cout << "Integer Address: " << intPtr << std::endl;
	std::cout << "Char Address: " << reinterpret_cast<void *>(charPtr) << std::endl;

	return 0;
}

/*
Output:
Integer Address: 0000009E9E54F900
Char Address: 0000009E9E54F900
*/
