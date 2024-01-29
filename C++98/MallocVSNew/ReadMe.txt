1. Calling Constructors: 
new calls constructors, while malloc() does not. 
In fact primitive data types (char, int, float.. etc) can also be initialized with new. 

#include<iostream>
using namespace std;
int main()
{
    // Initialization with new()
    int *n = new int(10); 
    cout << *n;
    getchar();
    return 0;
}

2. operator vs function:
new is an operator, while malloc() is a function.

3. return type:
new returns exact data type, while malloc() returns void *.

4. Failure Condition:
On failure, malloc() returns NULL where as new throws bad_alloc exception.

5. Memory:
In case of new, memory is allocated from free store where as in malloc() memory allocation is done from heap.

6. Size: 
Required size of memory is calculated by compiler for new, where as we have to manually calculate size for malloc().