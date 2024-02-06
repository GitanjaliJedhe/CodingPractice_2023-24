Reference: https://thispointer.com/c11-move-contsructor-rvalue-references/

copy constructors in C++ work with the l-value references
copy semantics means copying the actual data of the object to another object rather than making another object to point the already existing object in the heap


move constructors work on the r-value references
move semantics involves pointing to the already existing object in the memory

Why Move Constructors are used?
Move constructor moves the resources in the heap,
i.e., unlike copy constructors which copy the data of the existing object and assigning it to the new object 
move constructor just makes the pointer of the declared object to point to the data of temporary object and nulls out the pointer of the temporary objects. 
Thus, move constructor prevents unnecessarily copying data in the memory. 

Work of move constructor looks a bit like default member-wise copy constructor but in this case, 
it nulls out the pointer of the temporary object preventing more than one object to point to same memory location.























