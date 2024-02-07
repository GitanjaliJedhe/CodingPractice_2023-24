/*
Weak_ptr is a smart pointer that holds a non-owning reference to an object. 
It’s much more similar to shared_ptr except it’ll not maintain a Reference Counter. 
In this case, a pointer will not have a stronghold on the object. 
The reason is if suppose pointers are holding the object and requesting for other objects then they may form a Deadlock.
*/

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

	std::weak_ptr<Rectangle> p2(p1);

	std::cout << p1->area() << std::endl;

	std::cout << p1.use_count() << std::endl;

	return 0;
}

/*
Output:
50
1
*/
