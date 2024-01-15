#ifndef _IDATE_HPP 
#define _IDATE_HPP 

class IDate{
    public: 
        virtual int get_day() const = 0;  
        virtual int get_month() const = 0; 
        virtual int get_year() const = 0; 
        virtual void set_day(int new_day) = 0; 
        virtual void set_month(int new_month) = 0; 
        virtual void set_year(int new_year) = 0; 
        virtual void show() const = 0; 
        static IDate* get_instance(int init_day, int init_month, int init_year); 
}; 

#endif 