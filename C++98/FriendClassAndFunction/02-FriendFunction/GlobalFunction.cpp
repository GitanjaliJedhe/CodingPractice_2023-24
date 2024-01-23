#include <iostream>

class Base {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	Base(int pri_var_, int pro_var_) : private_variable(pri_var_), protected_variable(pro_var_) {
	}

	friend void friendfunction(Base& obj);

};

void friendfunction(Base& obj) {
	std::cout << "The Value of Private Variable = " << obj.private_variable << std::endl;
	std::cout << "The Value of Protected Variable = " << obj.protected_variable << std::endl;
}

int main() {
	Base obj(632, 523);
	
	friendfunction(obj);

	return 0;
}

/*
Output:
The Value of Private Variable = 632
The Value of Protected Variable = 523
*/
