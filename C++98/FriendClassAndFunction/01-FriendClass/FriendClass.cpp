#include <iostream>

class GFG {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	GFG(int pri_var_, int pro_var_) : private_variable(pri_var_), protected_variable(pro_var_) {
	}

	friend class Programmer;

};

class Programmer {
public:
	void display(GFG &gfgObj) {
		std::cout << "The Value of Private Variable = " << gfgObj.private_variable << std::endl;
		std::cout << "The Value of Protected Variable = " << gfgObj.protected_variable << std::endl;
	}
};

int main() {
	GFG gfgObj(545, 878);

	Programmer progObj;
	progObj.display(gfgObj);

	return 0;
}

/*
Output:
The Value of Private Variable = 545
The Value of Protected Variable = 878
*/
