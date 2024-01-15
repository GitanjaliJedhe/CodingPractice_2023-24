/*
In C++, type traits are a group of templates that are used to gather information about 
types at compile time, and are a powerful tool for template metaprogramming.

This means that before your program runs, 
the compiler can understand things about the types you're using—like whether a type is an integer, 
if it can be copied, or if it's a class with a certain function.

They are part of the Standard Template Library (STL) 
and included within the <type_traits> header file.

Type traits are implemented using class templates or function templates. 
Here's a sample code of a function template.
*/
#include <iostream>
#include <type_traits>

template <typename T>
void process(T value) {
	if (std::is_pointer<T>::value) {
		// handle pointers
	}
	else if (std::is_integral<T>::value) {
		// handle integers
	}
}

int main() {
	return 0;
}

/*
Output:
*/
