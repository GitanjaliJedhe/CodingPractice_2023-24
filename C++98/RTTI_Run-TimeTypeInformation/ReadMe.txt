RTTI (Run-time type information) 
is a mechanism that exposes information about an object’s data type at runtime and is available only for the classes which have at least one virtual function

Runtime Casts
Upcasting: When a pointer or a reference of a derived class object is treated as a base class pointer.
Downcasting: When a base class pointer or reference is converted to a derived class pointer.

Using ‘dynamic_cast‘: In an inheritance hierarchy, it is used for downcasting a base class pointer to a child class. 
On successful casting, it returns a pointer of the converted type and, however, it fails if we try to cast an invalid type 
such as an object pointer that is not of the type of the desired subclass.
