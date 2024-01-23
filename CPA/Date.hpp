#ifndef _DATE_HPP 
#define _DATE_HPP 

#include <iostream> 

class Date{
    private: 
        int day, month, year;
    public: 
        Date(
            int init_day, 
            int init_month,
            int init_year
        ); 

        Date(){
        }

        friend std::ostream& operator<<(
            std::ostream& os, 
            const Date& date_object    
        ); 
};

#endif 