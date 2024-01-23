#include <iostream> // for transform()

int increment(int x) {
	x = x + 1;
	return x;
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::transform(arr, arr+n, arr, increment);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}

/*
Output:
2 3 4 5 6
*/
