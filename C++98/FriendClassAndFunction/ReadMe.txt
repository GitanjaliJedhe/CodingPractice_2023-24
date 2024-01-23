Advantages of Friend Functions
A friend function is able to access members without the need of inheriting the class.
The friend function acts as a bridge between two classes by accessing their private data.
It can be used to increase the versatility of overloaded operators.
It can be declared either in the public or private or protected part of the class.

Disadvantages of Friend Functions
Friend functions have access to private members of a class from outside the class which violates the law of data hiding.
Friend functions cannot do any run-time polymorphism in their members.

Important Points About Friend Functions and Classes
Friends should be used only for limited purposes. Too many functions or external classes are declared as friends of a class with protected or private data access lessens the value of encapsulation of separate classes in object-oriented programming.
Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
Friendship is not inherited. (See this for more details)
