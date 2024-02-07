#include <iostream>

class Rectangle {
private:
	int length;
	int breadth;

public:
	Rectangle(int l, int b) {
		length = l;
		breadth = b;
	}

	int area() {
		return length * breadth;
	}
};

int main() {
	std::shared_ptr<Rectangle> p1(new Rectangle(10, 5));
	std::cout << p1->area() << std::endl;

	std::shared_ptr<Rectangle> p2;
	p2 = p1;

	std::cout << p2->area() << std::endl;
	std::cout << p1->area() << std::endl;

	std::cout << p1.use_count() << std::endl;

	return 0;
}

/*
Output:
50
50
50
2
*/
