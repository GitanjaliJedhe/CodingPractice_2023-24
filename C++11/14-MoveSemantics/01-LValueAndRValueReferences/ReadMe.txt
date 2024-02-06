lvalue and rvalue in C language:
lvalue:- 
lvalue simply means an object that has an identifiable location in memory (i.e. having an address).
lvalue cannot be a function, expression (like a+b) or a constant (like 3 , 4 , etc.).

r-value:-
an object that has no identifiable location in memory

#--------------------------------------------------------------------------------------------------

lvalues references and rvalues references in C++ 
“l-value” refers to a memory location that identifies an object.
“r-value” refers to the data value that is stored at some address in memory.

Example: 

int a = 10;

// Declaring lvalue reference
int& lref = a;

// Declaring rvalue reference
int&& rref = 20;

Uses of the lvalue references: 
lvalue references can be used to alias an existing object.
They can also be used to implement pass-by-reference semantics.

Uses of rvalue references: 
They are used in working with the move constructor and move assignment.
