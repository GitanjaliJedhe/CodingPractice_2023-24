// set is an associative container that stores unique values in sorted order, 
//either ascending or descending. 
// implements a red-black tree as an underlying data structure

#include <iostream>
#include <set>
#include <vector>

int main() {
	std::vector<int> v = {1, 9, 3, 5, 1, 3, 3, 7};

	std::set<int> s(v.begin(), v.end());

	if (s.find(5) == s.end()) {
		std::cout << "5 not found" << std::endl;
	}
	else {
		std::cout << "5 found" << std::endl;
	}

	std::cout << "s: ";
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
Output:
5 found
s: 1 3 5 7 9
*/
