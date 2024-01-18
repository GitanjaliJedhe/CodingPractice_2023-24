/*
Syntax of std::for_each
for_each (firstIterator, lastIterator, unaryFunction);
*/

#include <iostream>
#include <vector>
#include <algorithm> // for for_each()

int main() {
	std::vector<int> v = {1, 2, 3, 4, 5};

	// adding 1 to each element 
	for_each(v.begin(), v.end(), [](int& i) {
		i = i + 1;
		});

	std::cout << "v: ";
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
Output:
v: 2 3 4 5 6
*/
