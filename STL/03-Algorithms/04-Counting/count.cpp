#include <iostream>

int main() {
	int arr[] = { 1,2,1,1,3,2,15,18,3 };

	int n = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " appears " << std::count(arr, arr + n, arr[i]) << " times." << std::endl;
	}

	return 0;
}

/*
Output:
1 appears 3 times.
2 appears 2 times.
1 appears 3 times.
1 appears 3 times.
3 appears 2 times.
2 appears 2 times.
15 appears 1 times.
18 appears 1 times.
3 appears 2 times.
*/
