/*
for (range_initialization : range_container) {
    // loop statements
}
Here,
range_initialization - creates an iterating variable.
range_container - container to iterate over.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    // declared the iterating variable num and 
    // iterated over the container numbers using a range based for loop.

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}

/*
Output:
1 2 3 4 5
*/
