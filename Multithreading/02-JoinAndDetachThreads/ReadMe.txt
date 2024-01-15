Detaching Threads using std::thread::detach()
By detaching, we convert threads into daemon or background threads. 
For example,
// Create a Thread
std::thread th(funcPtr);
// Detach the thread i.e.
// thread will not be joinable now
th.detach();


Important Points about join() and detach() functions:
To ensure safety before calling join() or detach(), it’s advisable to check if the thread is joinable using the joinable() method, 
as demonstrated in the given example.

// Create thread object
std::thread threadObj( (WorkerThread()) );

// Check if thread is joinable
if(threadObj.joinable())
{
    std::cout<<"Detaching Thread "<<std::endl;
    threadObj.detach();
}

// Check if thread is joinable
if(threadObj.joinable())    
{
    std::cout<<"Detaching Thread "<<std::endl;
    threadObj.detach();
}

// Create thread object
std::thread threadObj2( (WorkerThread()) );

// Check if thread is joinable
if(threadObj2.joinable())
{
    std::cout<<"Joining Thread "<<std::endl;
    threadObj2.join();
}

// Check if thread is joinable
if(threadObj2.joinable())    
{
    std::cout<<"Joining Thread "<<std::endl;
    threadObj2.join();
}



Never forget to call either join() or detach():
