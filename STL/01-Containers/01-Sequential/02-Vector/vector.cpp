// dynamic array

#include <iostream> 
#include <vector>

int main() {
	// 1D vector with initialization list 
	std::vector<int> v1 = {1, 2, 3, 4, 5};

	// adding values using push_back() 
	v1.push_back(6);

	// printing v1 using size() 
	std::cout << "v1: ";
	for (int i = 0; i < v1.size(); i++) {
		std::cout << v1.at(i) << " ";
	}
	std::cout << std::endl;

	v1.erase(v1.begin()+4);

	// printing v1 using iterators 
	std::cout << "v1: ";
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 2D vector with size and element value initialization 
	std::vector<std::vector<int>> v2(3, std::vector<int>(4, 9));

	std::cout << "v2: " << std::endl;
	// printing v2 using range based for loop 
	for (auto i : v2) {
		for (auto j : i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

/*
Output:
v1: 1 2 3 4 5 6
v1: 1 2 3 4 6
v2:
9 9 9 9
9 9 9 9
9 9 9 9
*/
