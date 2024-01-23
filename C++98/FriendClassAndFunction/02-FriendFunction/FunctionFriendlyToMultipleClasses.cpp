#include <iostream>

class XYZ;

class ABC {
private:
	int x;

public:
	ABC(int x_) : x(x_) {
	}

	friend void max(ABC&, XYZ&);
};

class XYZ {
private:
	int y;

public:
	XYZ(int y_) : y(y_) {
	}

	friend void max(ABC&, XYZ&);
};

void max(ABC& t1, XYZ& t2) {
	if (t1.x > t2.y)
		std::cout << t1.x;
	else
		std::cout << t2.y;
}


int main() {
	ABC abc(543);
	XYZ xyz(954);

	max(abc, xyz);

	return 0;
}

/*
Output:
954
*/
