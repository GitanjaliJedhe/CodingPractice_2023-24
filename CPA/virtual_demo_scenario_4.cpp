#include <iostream> 

class B{
    public: 
        virtual void f(){
            std::cout << "In B::f()" << std::endl; 
        }

        B& operator=(const B& other){
            std::cout << "In B::operator=()" << std::endl; 
            return *this; 
        }
}; 

class D : public B{
    public: 
        void f(){
            std::cout << "In D::f()" << std::endl; 
        }
}; 

void test(); 

int main(void){
    B* pB = new D; 
    pB->f();    // DECISION IN FAVOUR OF POINTEE
    delete pB; 
    pB = 0; 
    test(); 
    return 0; 
}

void test(){
    D objD1; 
    D objD2; 

    B& ref1 = objD2; 
    ref1 = objD1; 
}