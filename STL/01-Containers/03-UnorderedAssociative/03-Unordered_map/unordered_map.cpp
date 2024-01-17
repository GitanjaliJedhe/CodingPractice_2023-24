// Unordered_maps are stores the data in the form of key-value pairs.
// They implement the hash table so there is no particular order in which the data is stored.

#include <iostream>
#include <unordered_map>

int main() {
	std::unordered_map<int, std::string> umap;

	umap[1] = "One";
	umap[2] = "Two";
	umap[3] = "Three";
	umap.insert({4, "Four"});

	if (umap.find(3) != umap.end()) {
		std::cout << "3 found!" << std::endl;
	}
	else {
		std::cout << "3 not found" << std::endl;
	}

	std::cout << "umap: " << std::endl;
	for (auto it = umap.begin(); it != umap.end(); it++) {
		std::cout << "Key: " << it->first << '\t';
		std::cout << "Value: " << it->second << std::endl;
	}

	return 0;
}

/*
* Output:
3 found!
umap:
Key: 4	Value: Four
Key: 3	Value: Three
Key: 2	Value: Two
Key: 1	Value: One
*/
