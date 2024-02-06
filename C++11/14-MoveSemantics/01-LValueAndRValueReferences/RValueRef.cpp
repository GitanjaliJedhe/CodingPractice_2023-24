#include <iostream>

void printReferenceValue(int&& x) {
	std::cout << x << std::endl;
}

int main() {

	printReferenceValue(100);

	return 0;
}

/*
Output:
100
*/
