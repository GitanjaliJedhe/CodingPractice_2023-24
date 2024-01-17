// double-ended queue which follows the FIFO mode of operation 
// but unlike the queue, the deque can growand shrink from both ends

#include <iostream>
#include <deque>

int main() {
	std::deque<int> d = {1, 2, 3, 4, 5};

	// removing two elements from the back and pushing them 
	// at the front
	d.push_front(d.back());
	d.pop_back();

	d.push_front(d.back());
	d.pop_back();

	std::cout << "d: ";
	for (const auto &i : d) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
Output:
d: 4 5 1 2 3
*/
