/*
std::future is a class template and its object internally stores a value that will be assigned in future 
and it also provides a mechanism to access that value i.e. using get() member function. 
But if somebody tries to access this associated value of future through get() function before it is available, 
then get() function will block till value is not available.

std::promise is also a class template and its object promises to set the value in future. 
Each std::promise object has an associated std::future object that will give the value once set by the std::promise object.
*/

#include <iostream>
#include <thread>
#include <future>

void initializer(std::promise<int> *promObj) {
	int val = 989;
	promiseObj->set_value(val);
	std::cout << "Inside Thread " << std::this_thread::get_id() << " Value = " << val << std::endl;
}

int main() {
	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();
	std::thread th(initializer, &promiseObj);

	std::cout << "Inside Main Thread Value = " << futureObj.get() << std::endl;

	th.join();

	return 0;
}

/* Output:
Inside Thread 24304 Value = 989
Inside Main Thread Value = 989
*/
