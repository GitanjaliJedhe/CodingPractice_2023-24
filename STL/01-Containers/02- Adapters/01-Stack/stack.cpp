//  stack is a container adaptor that operates one LIFO principle

#include <iostream>
#include <stack>

int main() {
	std::stack<int> s;

	for (int i = 1; i <= 5; i++) {
		s.push(i);
	}
	s.push(6);
	std::cout << "s.top() = " << s.top() << std::endl;

	std::cout << "s: ";
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;

	std::cout << "Final Size: " << s.size() << std::endl;

	return 0;
}

/*
Output:
s.top() = 6
s: 6 5 4 3 2 1
Final Size: 0
*/
