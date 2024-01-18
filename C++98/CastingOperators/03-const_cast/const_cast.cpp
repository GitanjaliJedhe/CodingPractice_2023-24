// const_cast operator is used to modify the const 

#include <iostream>

int main() {
	const int num = 564;

	const int* ptr = &num;

	int *nonConstPtr = const_cast<int*>(ptr);

	*nonConstPtr = 4362;

	std::cout << "Modified number: " << *nonConstPtr << std::endl;

	return 0;
}

/*
Output:
Modified number: 4362
*/
