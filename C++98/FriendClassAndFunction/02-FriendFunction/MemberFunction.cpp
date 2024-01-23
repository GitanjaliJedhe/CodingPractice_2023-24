#include <iostream>

class Base;

class Another {
public:
	void memberfunc(Base&);
};

class Base {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	Base(int pri_var_, int pro_var_) : private_variable(pri_var_), protected_variable(pro_var_) {
	}

	friend void Another::memberfunc(Base&);
};

void Another::memberfunc(Base& obj) {
	std::cout << "The Value of Private Variable = " << obj.private_variable << std::endl;
	std::cout << "The Value of Protected Variable = " << obj.protected_variable << std::endl;
}

int main() {
	Base baseObj(543, 645);

	Another anotherObj;

	anotherObj.memberfunc(baseObj);

	return 0;
}

/*
Output:
The Value of Private Variable = 543
The Value of Protected Variable = 645
*/
