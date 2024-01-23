/*
How to call the parameterized constructor of the ‘Person’ class ?
The constructor has to be called in ‘TA’ class.
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
	TeachingAssistant(int x) : Faculty(x), Student(x), Person(x) {
		std::cout << "TeachingAssistant::TeachingAssistant(int) called" << std::endl;
	}
};

int main() {
	TeachingAssistant ta(543);

	return 0;
}

/*
Output:
Person::Person(int) called
Faculty::Faculty(int) called
Student::Student(int) called
TeachingAssistant::TeachingAssistant(int) called
*/
