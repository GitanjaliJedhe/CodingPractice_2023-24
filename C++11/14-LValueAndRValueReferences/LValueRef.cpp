#include <iostream>

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {

	int a{ 10 }, b{20};

	std::cout << "a = " << a << " b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << " b = " << b << std::endl;

	return 0;
}

/*
Output:
a = 10 b = 20
a = 20 b = 10
*/
