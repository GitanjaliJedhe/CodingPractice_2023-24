#include <iostream>

class MyInt {
private:
	int n;

public:
	MyInt(int n_ = 0) : n(n_) {
	}

	MyInt operator++() {
		std::cout << "++n will be resolved by this member function" << std::endl;
		++this->n;
		return *this;
	}

	MyInt operator++(int) {
		std::cout << "n++ will be resolved by this member function" << std::endl;
		MyInt temp(this->n);
		this->n += 1;
		return temp;
	}

	MyInt operator--() {
		std::cout << "--n will be resolved by this member function" << std::endl;
		--this->n;
		return *this;
	}

	MyInt operator--(int) {
		std::cout << "n-- will be resolved by this member function" << std::endl;
		MyInt temp(this->n);
		this->n -= 1;
		return temp;
	}

	void show(const char *msg) const {
		if (msg)
			std::cout << msg;
		std::cout << this->n << std::endl;
	}

};

int main() {
	MyInt x = MyInt(100);

	MyInt result;

	result = x++;
	result.show("Result: ");

	result = ++x;
	result.show("Result: ");

	result = --x;
	result.show("Result: ");

	result = x--;
	result.show("Result: ");

	return 0;
}

/*
Output:
n++ will be resolved by this member function
Result: 100
++n will be resolved by this member function
Result: 102
--n will be resolved by this member function
Result: 101
n-- will be resolved by this member function
Result: 101
*/
