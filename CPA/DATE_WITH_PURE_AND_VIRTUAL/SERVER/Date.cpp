#include <stdio.h> 
#include "IDate.hpp"
#include "Date.hpp"

Date::Date(int init_day, int init_month, int init_year) : day(init_day), 
                                                          month(init_month), 
                                                          year(init_year)
{

}

int Date::get_day() const{
    return day; 
}

int Date::get_month() const{
    return month; 
} 

int Date::get_year() const {
    return year; 
}

void Date::set_day(int new_day){
    day = new_day; 
}

void Date::set_month(int new_month){
    month = new_month; 
} 

void Date::set_year(int new_year){
    year = new_year; 
}

void Date::show() const{
    printf("%d-%d-%d\n", day, month, year); 
}

IDate* IDate::get_instance(int init_day, int init_month, int init_year){
    Date* p_new_date = new Date(init_day, init_month, init_year); 
    return (p_new_date);    
}

