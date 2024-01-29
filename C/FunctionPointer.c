#include <stdio.h>

void func(int n) {
	printf("Value of n is %d\n", n);
}

int main() {
	void(*fPtr)(int) = func;

	fPtr(563);

	return 0;
}

/*
Output:
Value of n is 563
*/
