// queue is a container adapter that uses the FIFO mode of operation

#include <iostream>
#include <queue>

int main() {
	std::queue<int> q;

	for (int i = 1; i <= 5; i++) {
		q.push(i);
	}
	q.push(6);

	std::cout << "q.front() = " << q.front() << std::endl;
	std::cout << "q.back() = " << q.back() << std::endl;

	// printing queue by popping all elements 
	std::cout << "q: ";
	int size = q.size();
	for (int i = 0; i < size; i++) {
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;

	return 0;
}

/*
Output:
q.front() = 1
q.back() = 6
q: 1 2 3 4 5 6
*/
