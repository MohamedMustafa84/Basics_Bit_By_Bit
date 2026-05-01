#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;

Date::stDate IncreaseDateByOneDay(Date::stDate stDate){
    if(Date::checker::isLastDayInMonth(stDate)){
        
        if (Date::checker::isLastMonthInYear(stDate))
        {
            stDate.Day = 1;
            stDate.Month = 1;
            stDate.Year++;
        }else{
            stDate.Day = 1;
            stDate.Month++;
        }
    }
    else{
        stDate.Day++;
    }
    return stDate;
}

int main()
{

    //  Problem 16
    // write  a program to read date and Increase it By One Day

    Date::stDate Date ,NewDate;

    Date = Date::ReadFullDate();

    NewDate = IncreaseDateByOneDay(Date);

    cout << "Date After Adding One Day is : " << NewDate.Day << "/"
         << NewDate.Month << "/" << NewDate.Year << endl;

    return 0;
}