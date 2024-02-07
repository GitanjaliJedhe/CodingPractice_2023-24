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
	std::unique_ptr<Rectangle> p1(new Rectangle(10, 5));
	std::cout << p1->area() << std::endl;

	std::unique_ptr<Rectangle> p2;
	p2 = std::move(p1);

	std::cout << p2->area() << std::endl;

	// std::cout<<P1->area()<<std::endl;

	return 0;
}

/*
Output:
50
50
*/
