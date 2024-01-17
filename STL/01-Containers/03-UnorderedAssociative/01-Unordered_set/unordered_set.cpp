// unordered_set is the version of the set container where the data is not sorted 
// but we can still perform a quick search.
// t is due to the fact that these unordered_sets are implemented using hash tables.

#include <iostream>
#include <unordered_set>

int main() {
	std::unordered_set<int> us = { 9, 4, 5, 3, 7 };

	// checking size 
	std::cout << "Size: " << us.size() << std::endl;

	// inserting data 
	us.insert(2);

	// finding some key 
	if (us.find(5) != us.end()) {
		std::cout << "5 found!" << std::endl;
	}
	else {
		std::cout << "5 not found" << std::endl;
	}

	// traversing unordered_set using iterators 
	std::cout << "us: ";
	for (std::unordered_set<int>::iterator it = us.begin(); it != us.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
* Output:
Size: 5
5 found!
us: 9 4 5 3 7 2
*/
