// performs compile-time type conversion
// mainly used for explicit conversions that are considered safe by the compiler. 

#include <iostream>
#include <typeinfo> // for typeid()

int main() {
	int num = 858;
	double numDouble = static_cast<double>(num);

	std::cout << typeid(num).name() << std::endl;

	std::cout << typeid(static_cast<double>(num)).name() << std::endl;

	std::cout << typeid(numDouble).name() << std::endl;

	return 0;
}

/*
Output:
int
double
double
*/
