/*
* Algorithm:
* Declare a character stack S.
* Now traverse the expression string exp.
*	If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
*	If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else brackets are not balanced.
* After complete traversal, if there is some starting bracket left in stack then “not balanced”
*/

#include <iostream>
#include <stack>

bool isParenthesisBalanced(std::string expr) {
	std::stack<char> s;
	char c;

	for (int i = 0; i < expr.length(); i++) {

		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
			s.push(expr[i]);
			continue;
		}

		// if current current character is not opening 
		// bracket, then it must be closing. So stack 
		// cannot be empty at this point. 
		if (s.empty()) {
			return false;
		}

		switch (expr[i])
		{
		case ')':
			c = s.top();
			s.pop();
			if (c == '{' || c == '[')
				return false;
			break;

		case '}':
			c = s.top();
			s.pop();
			if (c == '(' || c == '[')
				return false;
			break;

		case ']':
			c = s.top();
			s.pop();
			if (c == '(' || c == '{')
				return false;
			break;

		default:
			break;
		}

	}

	// Check Empty Stack 
	return(s.empty());

}

int main() {
	std::string expr = "{()}[]";

	if (isParenthesisBalanced(expr)) {
		std::cout << "Balanced" << std::endl;
	}
	else {
		std::cout << "Not Balanced" << std::endl;
	}

	return 0;
}

/*
* Output:
* Balanced
*/

/*
* Time Complexity: O(n)
* Auxiliary Space: O(n) for stack. 
*/
