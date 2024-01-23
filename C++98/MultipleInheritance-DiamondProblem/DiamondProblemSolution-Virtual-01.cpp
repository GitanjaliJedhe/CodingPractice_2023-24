/*
The solution to this problem is ‘virtual’ keyword. 
We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid two copies of ‘Person’ in ‘TA’ class.
*/

/*
constructor of ‘Person’ is called once. One important thing to note in the above output is, the default constructor of ‘Person’ is called. 
When we use ‘virtual’ keyword, the default constructor of grandparent class is called by default even if the parent classes explicitly call parameterized constructor.
*/

#include <iostream>

class Person {
public:
	Person() {
		std::cout << "Person::Person() called" << std::endl;
	}

	Person(int x) {
		std::cout << "Person::Person(int) called" << std::endl;
	}
};

class Faculty : virtual public Person {
public:
	Faculty(int x) : Person(x) {
		std::cout << "Faculty::Faculty(int) called" << std::endl;
	}
};

class Student : virtual public Person {
public:
	Student(int x) : Person(x) {
		std::cout << "Student::Student(int) called" << std::endl;
	}
};

class TeachingAssistant : public Faculty, public Student {
public:
	TeachingAssistant(int x) : Faculty(x), Student(x) {
		std::cout << "TeachingAssistant::TeachingAssistant(int) called" << std::endl;
	}
};

int main() {
	TeachingAssistant ta(543);

	return 0;
}

/*
Output:
Person::Person() called
Faculty::Faculty(int) called
Student::Student(int) called
TeachingAssistant::TeachingAssistant(int) called
*/
