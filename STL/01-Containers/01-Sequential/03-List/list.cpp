// implements the doubly linked list 

#include <iostream>
#include <list>
#include <vector>

int main() {
	// creating std::list object using initializer list 
	std::list<int> l1 = {1, 2, 3, 4, 5, 6};
	
	// adding element 
	l1.insert(l1.begin(), 8);
	// printing first element 
	std::cout << "First element if l1: " << l1.front() << std::endl;

	// deleting element 
	l1.erase(l1.begin());

	// traversing and printing l1 
	std::cout << "l1: ";
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// vector for initialization 
	std::vector<char> v1 = {'G','i','t','a','n','j','a','l','i'};
	std::list<int> l2(v1.begin(), v1.end());

	// traversing and printing l2 
	std::cout << "l2: ";
	for (auto i : l2) {
		std::cout << char(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
Output:
First element if l1: 8
l1: 1 2 3 4 5 6
l2: G i t a n j a l i
*/
