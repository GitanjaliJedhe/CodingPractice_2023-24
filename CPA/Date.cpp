#include <iostream> 
#include "Date.hpp"

Date::Date(
    int init_day, 
    int init_month,
    int init_year
)  :    day(init_day), 
        month(init_month), 
        year(init_year)
{

}

std::ostream& operator<<(
    std::ostream& os, 
    const Date& date_object    
){
    os  << date_object.day << "-" << date_object.month << "-" << date_object.year; 
    return os; 
} 
