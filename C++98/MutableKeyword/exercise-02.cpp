#include <iostream>

class Test {
public:
	int x;
	mutable int y;

	Test() {
		x = 4;
		y = 10;
	}
};

int main() {
	const Test t1;

	t1.x = 8;

	std::cout << t1.x << std::endl;

	return 0;
}

/*
Output:
exercise-02.cpp
exercise-02.cpp(17): error C3892: 't1': you cannot assign to a variable that is const
*/
