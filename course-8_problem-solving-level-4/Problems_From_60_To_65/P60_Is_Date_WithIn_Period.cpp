#include <iostream>
#include "../../DateLib.h"
using namespace std;

bool isDateinPeriod(Date::stDate Date,Date::stPeriod Period){
    return !(Date::CompareTwoDates(Period.DateFrom, Date) == Date::enDateCompare::Before||
           Date::CompareTwoDates(Date, Period.DateTo)==Date::enDateCompare::After);
}

int main()
{

    // problem
    // write a program to read peroid and Date Then Check If The Date Within The Period 

    Date::stPeriod Period = Date::ReadPeriod("Period");
    cout << "Please Enter A Date To check it :\n";
    Date::stDate Date = Date::ReadFullDate();

    cout << (isDateinPeriod(Date, Period) ? "Yes , The Date Within The Period" : "No, The Date is not  Within The Period");
   
    return 0;
}