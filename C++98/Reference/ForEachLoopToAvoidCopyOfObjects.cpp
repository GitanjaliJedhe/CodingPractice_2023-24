#include <iostream>
#include <vector>

int main() {
	std::vector<std::string> vect{ "geeksforgeeks practice",
									"geeksforgeeks write",
									"geeksforgeeks ide" };

	for (const auto &x : vect) {
		std::cout << x << std::endl;
	}

	return 0;
}

/*
Output:
geeksforgeeks practice
geeksforgeeks write
geeksforgeeks ide
*/
