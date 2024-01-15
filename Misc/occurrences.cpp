#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec1 = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };
	std::vector<int> vec2 = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };

	std::vector<int>::iterator it;

	std::sort(vec2.begin(), vec2.end());
	// Now v becomes 1 1 2 2 3 3 3 3 7 7 8 10

	int num = vec2.size();
	it = std::unique(vec2.begin(), vec2.begin() + num);

	num = std::distance(vec2.begin(), it);

	vec2.resize(num);
	/*
	for (it = vec2.begin(); it != vec2.end(); it++) {
		std::cout << *it << " ";
	}
	*/

	for (it = vec2.begin(); it != vec2.end(); it++) {
		//std::cout << *it << " ";
		std::cout << *it << " appears " << std::count(vec1.begin(), vec1.end(), *it) << " times." << std::endl;
	}

	return 0;
}

/*
* Output:
1 appears 2 times.
2 appears 2 times.
3 appears 4 times.
7 appears 2 times.
8 appears 1 times.
10 appears 1 times.
*/
