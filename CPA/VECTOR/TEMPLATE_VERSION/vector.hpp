#ifndef _VECTOR_HPP
#define _VECTOR_HPP 

#include <iostream> 
#include <cassert> 

typedef long long ssize_t; 

template <typename T> 
class vector{
    private: 
        T* arr; 
        ssize_t N;
    public:  
        vector() : arr(0), N(0){

        }

        ~vector(){
            delete[] arr; 
            arr = 0; 
            N = 0; 
        }

        void push_back(const T& element){
            arr = (T*)realloc((void*)arr, (N+1)*sizeof(T)); 
            assert(arr != 0); 
            N += 1; 
            arr[N-1] = element; 
        }

        friend std::ostream& operator<<(std::ostream& os, const vector<T>& vec){
               for(ssize_t i = 0; i != vec.N; ++i)
                    os << "vec[" << i << "]:" << vec.arr[i] << std::endl; 
                return os; 
        }
}; 

#endif // _VECTOR_HPP
