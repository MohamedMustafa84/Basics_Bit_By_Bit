#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;

bool isLastDayInMonth(Date::stDate Date){
    return Date.Day == Date::NumberOfDaysInAMonth(Date.Month,Date.Year);
}

bool isLastMonthInYear(short Month){
    return Month == 12;
}

int main()
{

    //  Problem 15
    // write  a program to read date and check if Day is the last Day In Month or Not ,The Check If Month is Last Month In Year 

    Date::stDate Date;

    Date = Date::ReadFullDate();

    cout << (isLastDayInMonth(Date) ? "Yes ,This Day Is The Last Day In Month \n" : "No ,This Day Is Not The Last Day In Month\n");
    cout << (isLastMonthInYear(Date.Month) ? "Yes ,This Month Is The Last Month In Year \n" : "No ,This Month Is Not The Last Month In Year\n");

    return 0;
}