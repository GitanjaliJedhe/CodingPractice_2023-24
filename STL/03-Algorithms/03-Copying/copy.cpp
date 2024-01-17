// std::copy method efficiently copies a range of elements to another container using its iterators.
// Syntax of std::copy
// copy(beginIterator, endIterator, destIterator);

#include <iostream>
#include <vector>
#include <algorithm> // for copy()

int main() {
	std::vector<int> v1 = { 1, 5, 7, 3, 8, 3};

	std::vector<int> v2(6);

	// using copy() to copy 1st 3 elements 
	std::copy(v1.begin(), v1.begin()+3, v2.begin());

	// printing new vector 
	std::cout << "The new vector elements entered using copy() : ";
	for (int i = 0; i < v2.size(); i++) {
		std::cout << v2.at(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
* Output:
The new vector elements entered using copy() : 1 5 7 0 0 0
*/
