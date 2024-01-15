Multithreading support was introduced in C++11. Prior to C++11, we had to use POSIX threads or <pthreads> library.
The thread classes and related functions are defined in the <thread> header file.
Syntax:
	std::thread thread_object (callable);

A callable can be any of the five:
	A Function Pointer
	A Lambda Expression	
	A Function Object
	Non-Static Member Function
	Static Member Function

