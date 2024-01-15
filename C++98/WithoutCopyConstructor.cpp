#include <iostream>
#include <cstring>

class String {
private:
	char *s;
	int size;

public:
	String(const char *str = NULL);
	void print() {
		std::cout << s << std::endl;
	}
	void change(const char* str);
	~String() { delete[]s; };
};

String::String(const char* str) {
	size = strlen(str);
	s = new char[size+1];
	strcpy(s, str);
}

void String::change(const char* str) {
	strcpy(s, str);
}

int main() {
	String str1("Gitanjali Dilip Jedhe");
	String str2(str1);

	str1.print();
	str2.print();

	str2.change("Jedhe Gitanjali Dilip");

	str1.print();
	str2.print();

	return 0;
}
