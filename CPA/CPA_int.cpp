#include <iostream> 
#include <cassert> 
#include <typeinfo> 

class CPA_int
{
    private: 
        int N; 

    public: 
        CPA_int(int _n = 0) : N(_n){}

        CPA_int operator+(const CPA_int& other) const
        {
            std::cout << "In CPA_int::operator+():" << std::endl; 
            int result = this->N + other.N; 
            CPA_int sum_obj(result); 
            return sum_obj; 
        } 

        CPA_int operator-(const CPA_int& other) const 
        {
            return CPA_int(N - other.N);
        }

        CPA_int operator*(const CPA_int& other) const 
        {
            return CPA_int(N * other.N);
        }

        CPA_int operator/(const CPA_int& other) const
        {
            assert(other.N != 0); 
            return CPA_int(N / other.N); 
        }

        CPA_int operator%(const CPA_int& other) const 
        {
            assert(other.N != 0); 
            return CPA_int(N % other.N); 
        }

        CPA_int operator<<(const CPA_int& other) const 
        {
            return CPA_int(N << other.N); 
        }

        CPA_int operator>>(const CPA_int& other) const 
        {
            return CPA_int(N >> other.N); 
        }

        CPA_int operator&(const CPA_int& other) const 
        {
            return CPA_int(N & other.N); 
        }

        CPA_int operator|(const CPA_int& other) const 
        {
            return CPA_int(N | other.N); 
        }

        CPA_int operator^(const CPA_int& other) const 
        {
            return CPA_int(N ^ other.N); 
        }

        CPA_int operator~() const 
        {
            return CPA_int(~N);
        }

        bool operator>(const CPA_int& other) const 
        {
            return (N > other.N); 
        }

        bool operator>=(const CPA_int& other) const 
        {
            return (N >= other.N); 
        }

        bool operator<(const CPA_int& other) const 
        {
            return (N < other.N); 
        }

        bool operator<=(const CPA_int& other) const 
        {
            return (N <= other.N); 
        }

        bool operator==(const CPA_int& other) const 
        {
            return (N == other.N); 
        }

        bool operator!=(const CPA_int& other) const 
        {
            return (N != other.N); 
        }

        CPA_int operator++()
        {
            std::cout   << "++n will be resolved by this member function" 
                        << std::endl;    
            ++this->N; 
            return *this; 
        }
        
        CPA_int operator++(int)
        {
            std::cout   << "n++ will be resolved by this member function" 
                        << std::endl; 
            CPA_int tmp(this->N); 
            this->N += 1; 
            return tmp;   
        }

        CPA_int operator--()
        {
            std::cout << "--n will be resolved by this member function"
                      << std::endl; 
            --this->N; 
            return *this; 
        }

        CPA_int operator--(int)
        {
            std::cout << "n-- will be resolved by this member function"
                      << std::endl; 
            CPA_int tmp(this->N); 
            this->N -= 1; 
            return tmp; 
        }
       
        double flt_div(const CPA_int& other) const 
        {
            assert(other.N != 0); 
            return (((double)N)/other.N); 
        }

        void show(const char* msg) const 
        {
            if(msg)
                std::cout << msg; 
            std::cout << this->N << std::endl; 
        }
};


int main(void)
{
    CPA_int n1(10), n2(3); 
    CPA_int result; 

    n1.show("n1:"); 
    n2.show("n2:"); 
    result = n1 + n2; 
    result.show("Summation:"); 
    
    std::cout << "type(n1):" << typeid(n1).name() << std::endl; 
    std::cout << "type(n2):" << typeid(n2).name() << std::endl; 
    std::cout << "type(reuslt):" << typeid(result).name() << std::endl; 

    result = n1 - n2; 
    result.show("Subtraction:"); 

    result = n1 * n2; 
    result.show("Multiplication:"); 

    result = n1 / n2; 
    result.show("Quotient:"); 

    result = n1 % n2; 
    result.show("Remainder:"); 

    double flt_num = n1.flt_div(n2); 
    std::cout   << "flt_num:" 
                << flt_num 
                << std::endl; 
    std::cout   << "type(flt_num):" 
                << typeid(flt_num).name() 
                << std::endl; 

    result = n1 << n2; 
    result.show("Shift Arithmetic Left:"); 

    result = n1 >> n2; 
    result.show("Shift Arithmetic Right:"); 

    result = n1 & n2; 
    result.show("Bitwise AND:"); 

    result = n1 | n2; 
    result.show("Bitwise OR:"); 

    result = n1 ^ n2; 
    result.show("Bitwise XOR:"); 

    result = ~n1; 
    result.show("Bitwise ~:"); 

    std::cout << "COMPARISON OPERATORS" << std::endl; 
    n1.show("n1:"); 
    n2.show("n2:"); 

    bool rs = (n1 > n2); 
    std::cout << "n1 > n2:" << rs << std::endl; 

    rs = (n1 >= n2); 
    std::cout << "n1 >= n2:" << rs << std::endl;

    rs = (n1 < n2); 
    std::cout << "n1 < n2:" << rs << std::endl;

    rs = (n1 <= n2); 
    std::cout << "n1 <= n2:" << rs << std::endl;

    rs = (n1 == n2); 
    std::cout << "n1 == n2:" << rs << std::endl;

    rs = (n1 != n2); 
    std::cout << "n1 != n2:" << rs << std::endl;

    CPA_int X = CPA_int(100); 
    result = X++;  
    result.show("result:"); 
    result = ++X; 
    result.show("result:"); 
    result = --X; 
    result.show("result:"); 
    result = X--; 
    result.show("result:"); 
    
    return EXIT_SUCCESS;  
}

/*

class CLASSNAME 
{
    public: 
        static bool casecmp(const char* s1, const char* s2)
        {
            return strcasecmp(s1, s2) < 0;
        }
}; 

void caller(void)
{
    bool ret = CLASSNAME::casecmp(s1, s2); 
}

*/

// type(objT OP objT) -> T  
// OP is one of following : +, -, *, /, %, <<, >>, &, |, ^, 

// type(~objT) -> T 

// if OP is an ASSOCIATIVE OPERATOR : a OP (b OP C) == (a OP b) OP c

// if OP is a COMMUTATIVE : a OP b = b OP a 

// Mathmatical Definition: Let S be a non-empty set. 
// Let * be a binary operator defined on elements on set S. 

// if, for all (x, y in S) : x * y is also in S 
// then * is said be to closed in the set S. 

// Generalization: 
// Let S be a non-empty set. 
// Let * be an n-ary operator defined on elements of set S. (where n >= 1)
// if, for all (x1, x2, ,...xn) in S, (* x1 x2 x3 .... xn) is also in S 
// then * is closed under S 

// Let T be a data type. 
// Let S = {object | where typeid(object) == T}
// operator + is closed under S. why? 
// for all t1, t2 in S, (+ t1 t2) is also in S 

// operator ~ is also closed under S. Why? 
// for all t in S, (~ t) is also in S 

// t1 + t2 + t3 + ... + tn

// sizeof(T) >>> 32 
// operator + 
