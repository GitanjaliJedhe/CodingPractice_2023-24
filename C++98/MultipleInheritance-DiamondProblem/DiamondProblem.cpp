// The diamond problem The diamond problem occurs when two superclasses of a class have a common base class.

/*
constructor of ‘Person’ is called two times. 
Destructor of ‘Person’ will also be called two times when object ‘ta’ is destructed. 
So object ‘ta’ has two copies of all members of ‘Person’, this causes ambiguities. 
The solution to this problem is ‘virtual’ keyword.
*/

#include <iostream>

class Person {
public:
	Person(int x) {
		std::cout << "Person::Person(int) called" << std::endl;
	}
};

class Faculty : public Person {
public:
	Faculty(int x) : Person(x) {
		std::cout << "Faculty::Faculty(int) called" << std::endl;
	}
};

class Student : public Person {
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
Person::Person(int) called
Faculty::Faculty(int) called
Person::Person(int) called
Student::Student(int) called
TeachingAssistant::TeachingAssistant(int) called
*/
