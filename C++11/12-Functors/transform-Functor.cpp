/*
Functors are objects that can be treated as though they are a function or function pointer.
To create a functor, we create a object that overloads the operator().

The line,
MyFunctor(10);

Is same as
MyFunctor.operator()(10);

The line,
transform(arr, arr+n, arr, increment(to_add));

is the same as writing below two lines,
// Creating object of increment
increment obj(to_add);

// Calling () on object
transform(arr, arr+n, arr, obj);

*/

#include <iostream>
#include <algorithm> // for transform()

class increment {
private:
	int n;

public:
	increment(int n_) : n(n_) {
	}

	int operator()(int arr_num) {
		return n + arr_num;
	}
};

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int add_num = 5;

	std::transform(arr, arr+n, arr, increment(add_num));

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
Output:
6 7 8 9 10
*/
