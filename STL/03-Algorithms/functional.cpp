// Function Objects, also known as Functors, are the objects that behave like a function.
// It is due to the overloading of the ( ) parenthesis operator.

#include <iostream>
#include <functional>

int main() {
	std::equal_to<int> eq;
	std::not_equal_to<int> neq;
	std::greater<int> gt;
	std::less<int> ls;
	std::plus<int> p;
	std::minus<int> m;

	std::cout << std::boolalpha;
	std::cout << "equal_to, (10, 20): " << eq(10, 20) << std::endl;
	std::cout << "not_equal_to, (10, 20): " << neq(10, 20) << std::endl;
	std::cout << "greater, (10, 20): " << gt(10, 20) << std::endl;
	std::cout << "less, (10, 20): " << ls(10, 20) << std::endl;
	std::cout << "plus, (10, 20): " << p(10, 20) << std::endl;
	std::cout << "minus, (10, 20): " << m(10, 20) << std::endl;

	return 0;
}

/*
Output:
equal_to, (10, 20): false
not_equal_to, (10, 20): true
greater, (10, 20): false
less, (10, 20): true
plus, (10, 20): 30
minus, (10, 20): -10
*/
