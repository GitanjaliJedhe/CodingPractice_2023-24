// Maps are associative containers used to store the key-value pairs where each key should be unique
// implements a red-black tree to store data in sorted order

#include <iostream>
#include <map>

int main() {
	std::map<int, std::string> m;

	m[1] = "One";
	m[2] = "Two";
	m[3] = "Three";
	m[4] = "Four";

	std::cout << "Size of map m: " << m.size() << std::endl;

	m.insert({5, "Five"});

	m.erase(4);

	// printing the map 
	std::cout << "Map:" << std::endl;
	for (auto i : m) {
		std::cout << "Key: " << i.first << '\t';
		std::cout << "Value: " << i.second << std::endl;
	}
	return 0;
}

/*
Output:
Size of map m: 4
Map:
Key: 1  Value: One
Key: 2  Value: Two
Key: 3  Value: Three
Key: 5  Value: Five
*/
