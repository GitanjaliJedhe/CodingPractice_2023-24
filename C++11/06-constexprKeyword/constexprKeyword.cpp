/*
The constexpr keyword allows you to specify that a variable or function can be evaluated at compile-time.
*/

#include <iostream>

constexpr int square(int x) {
	return x * x;
}

int main() {
	int result = square(9);

	std::cout << "Result: " << result << std::endl;

	return 0;
}

/*
Output:
Result: 81
*/
