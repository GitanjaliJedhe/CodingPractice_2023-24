#include "IDate.hpp" 

int main(void){
    IDate* pIDate = IDate::get_instance(1, 1, 1970); 
    pIDate->show(); 
    pIDate->set_day(2); 
    pIDate->set_month(3); 
    pIDate->set_year(1971); 
    pIDate->show(); 
    delete pIDate; 
    pIDate = 0; 
    return 0; 
}