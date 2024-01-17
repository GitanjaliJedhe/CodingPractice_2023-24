#include <iostream>
#include <vector>
#include <algorithm> // max_element

int main() {
	std::vector<int> v = { 10, 88, 2, 9, 45, 82, 546, 42, 221 };

	auto max = std::max_element(v.begin(), v.end());

	std::cout << "Max Element: " << *max << std::endl;

	return 0;
}

/*
* Output:
Max Element: 546
*/
