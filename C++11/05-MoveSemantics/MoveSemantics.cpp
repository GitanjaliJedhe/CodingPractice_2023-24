/*
Move semantics allows the resources owned by an object to be moved into another object 
instead of copying them. This optimizes performance by avoiding deep copies.
*/

#include <iostream>
#include <vector>

int main() {
	std::vector<int> src = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::vector<int> dest = std::move(src);

	std::cout << "Destination Vector Contents: ";
	for (std::vector<int>::iterator it = dest.begin(); it != dest.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << "\nDestination Vector Size: " << dest.size() << std::endl;

	return 0;
}
/*
Output:
Destination Vector Contents: 0 1 2 3 4 5 6 7 8 9
Destination Vector Size: 10
*/
