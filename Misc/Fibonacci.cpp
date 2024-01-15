#include <iostream>

void fib(int n) {
	int next = 0, n1 = 0, n2 = 1;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			std::cout<< n1 << ", ";
			continue;
		}

		if (i == 1) {
			std::cout << n2 << ", ";
			continue;
		}

		next = n1 + n2;

		n1 = n2;
		n2 = next;

		std::cout << next << ", ";

	}
}

// recursion
/*
int fib(int n) {
	if (n <= 1)
		return n;

	return fib(n - 1) + fib(n - 2);
}
*/

int main() {

	int n = 9;

	//std::cout << fib(n) << std::endl;

	fib(9);

	return 0;
}
