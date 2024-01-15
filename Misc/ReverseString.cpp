#include <iostream>
#include <stack>

int main() {
	
	std::string name = "Gitanjali Dilip Jedhe";
	
	std::cout << "Original String: " << name << std::endl;

	std::stack<char> st;

	for (char ch : name) {
		st.push(ch);
	}

	std::cout << "Reverse String: ";

	while (!st.empty()) {
		std::cout << st.top();
		st.pop();
	}

	std::cout << std::endl;
	
	/*
	char str[] = "Gitanjali Dilip Jedhe";

	printf("Original String: %s\n", str);

	int len = 0, i = 0;
	while (str[i] != '\0') {
		len++;
		i++;
	}

	for (int i = 0, j = len - 1; i <= j; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	printf("Reverse String: %s\n", str);
	*/

	return 0;
}
