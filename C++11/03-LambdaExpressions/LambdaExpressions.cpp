/*
* Lambda expressions allow you to create anonymous functions in a concise manner. 
They are especially useful when you need to pass small functions as arguments to other functions.
The general syntax is:
[capture_clause] (parameter_list) -> return_type {
    // lambda body: Code to be executed
}
Here,
capture_clause - specifies which variables from the surrounding scope are accessible within the lambda function.
parameter_list - defines the parameters the function accepts.
-> return_type - Declares the return type of the function.

Extra:
You can also capture all local variables without specifying them one by one:
By value using [=]
By reference using [&]
*/

#include <iostream>

int main() {
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    int result = add(666, 333);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

/*
Output:
Result: 999
*/
