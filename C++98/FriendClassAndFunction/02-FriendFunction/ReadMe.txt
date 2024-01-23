Like a friend class, a friend function can be granted special access to private and protected members of a class in C++. 
They are the non-member functions that can access and manipulate the private and protected members of the class for they are declared as friends.
A friend function can be:
A global function
A member function of another class

Syntax:
friend return_type function_name (arguments);    // for a global function

            or

friend return_type class_name::function_name (arguments);    // for a member function of another class
