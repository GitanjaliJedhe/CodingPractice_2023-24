Pointers: A pointer is a variable that holds the memory address of another variable. 
A pointer needs to be dereferenced with the * operator to access the memory location it points to. 

References: A reference variable is an alias, that is, another name for an already existing variable. 
A reference, like a pointer, is also implemented by storing the address of an object. 
A reference can be thought of as a constant pointer (not to be confused with a pointer to a constant value!) with automatic indirection, 
i.e., the compiler will apply the * operator for you. 

Differences:
Initialization
1.
declareand initialize pointer at same step or in multiple line.
int a = 10;
int *p = &a;
// OR 
int *p;
p = &a;

2.
int a = 10;
int &p = a; // It is correct
// but
int &p;
p = a; // It is incorrect as we should declare and initialize references at single step

Reassignment:
A pointer can be re-assigned. This property is useful for the implementation of data structures like a linked list, a tree, etc.
int a = 5;
int b = 6;
int *p;
p = &a;
p = &b;

On the other hand, a reference cannot be re-assigned, and must be assigned at initialization.
int a = 5;
int b = 6;
int &p = a;
int &p = b; // This will throw an error of "multiple declaration is not allowed"

// However it is valid statement,
int &q = p;


Memory Address: 
A pointer has its own memory address and size on the stack, whereas a reference shares the same memory address with the original variable and takes up no space on the stack.
int &p = a;
cout << &p << endl << &a;

NULL value:
A pointer can be assigned NULL directly, whereas a reference cannot be. 

Indirection:
You can have a pointer to pointer (known as a double pointer) offering extra levels of indirection, whereas references only offer one level of indirection.
In Pointers,
int a = 10;
int *p;
int **q; // It is valid.
p = &a;
q = &p;

// Whereas in references,
int &p = a;
int &&q = p; // It is reference to reference, so it is an error

8. Arithmetic operations:
Various arithmetic operations can be performed on pointers, whereas there is no such thing called Reference Arithmetic


When to use What
The performances are exactly the same as references are implemented internally as pointers. But still, you can keep some points in your mind to decide when to use what:  
Use references: 
In function parameters and return types.
Use pointers: 
If pointer arithmetic or passing a NULL pointer is needed. For example, for arrays (Note that accessing an array is implemented using pointer arithmetic).
To implement data structures like a linked list, a tree, etc. and their algorithms. This is so because, in order to point to different cells, we have to use the concept of pointers.