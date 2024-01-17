#include <iostream>
#include <algorithm>

int main() {
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Before sort: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	/*Here we take two parameters, the beginning of the
	array and the length n upto which we want the array to
	be sorted*/
	std::sort(arr, arr+n);

	std::cout << "After sort: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
* Output:
Before sort:
1 5 8 9 6 7 3 4 2 0
After sort:
0 1 2 3 4 5 6 7 8 9
*/
