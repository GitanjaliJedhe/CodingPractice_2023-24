/*
Syntax of std::find
find (firstIterator, lastIterator, value);
*/

#include <iostream>
#include <vector>
#include <algorithm> // for find()

int main() {
	std::vector<int> v = { 1, 8, 97, 3, 654, 132, 65, 4, 321, 5, 45 };

	auto itr = std::find(v.begin(), v.end(), 654);

	if (itr != v.end()) {
		std::cout << *itr << " found!" << std::endl;
	}
	else {
		std::cout << *itr << " not found" << std::endl;
	}

	return 0;
}

/*
* Output:
654 found!
*/
