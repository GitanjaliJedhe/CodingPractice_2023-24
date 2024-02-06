#include <iostream>

struct Student {
	std::string name;
	std::string address;
	int rollNo;
};

void print(const Student &s) {
	std::cout << s.name << " " << s.address << " " << s.rollNo << std::endl;
}

int main() {
	Student st;

	st.name = "Gitanjali Jedhe";
	st.address = "Pune";
	st.rollNo = 123;

	print(st);

	return 0;
}
