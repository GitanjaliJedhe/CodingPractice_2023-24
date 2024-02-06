#include <iostream>
#include <vector>

int main() {
	std::vector<int> numbers{10, 20, 30, 40, 50};

	for (int &n : numbers) {
		n = n + 5;
	}

	for (int n : numbers) {
		std::cout << n << " ";
	}

	std::cout << std::endl;

	return 0;
}

/*
Output:
15 25 35 45 55
*/
