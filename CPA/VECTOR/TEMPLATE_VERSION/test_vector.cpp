#include <iostream> 
#include <cstring>
#include "vector.hpp"

int main(void){
    vector<int> v; 
    for(int i = 0; i != 100; i += 10)
        v.push_back(i); 
    std::cout << v; 
    const char* s = "CoreCode Programming Academy"; 
    vector<char> cvec; 
    for(int i = 0; i != strlen(s); ++i)
        cvec.push_back(s[i]); 
    std::cout << cvec; 
    return 0; 
}