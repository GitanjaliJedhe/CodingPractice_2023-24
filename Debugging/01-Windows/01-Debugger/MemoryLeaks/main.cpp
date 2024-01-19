#include <iostream>
#include <cstring>

int main() {
	int a = 1;

	char* s = new char[17];
	strcpy_s(s, 17, "stackoverflow_pb");

	char* ss = new char[14];
	strcpy_s(ss, 14, "stackoverflow");

	delete[]ss;

	return 0;
}
