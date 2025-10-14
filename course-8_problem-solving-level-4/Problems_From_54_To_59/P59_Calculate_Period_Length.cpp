#include <iostream>
#include "../../DateLib.h"
using namespace std;

int calculate_Period_Length(Date::stPeriod Period, bool IncludeLastDay = false)
{

    return Date::GetDifferenceInDays(Period.DateFrom, Period.DateTo, IncludeLastDay);
}

int main()
{

    // problem 
    // write a program to read peroid and calculate period length in days 


    Date::stPeriod Period = Date::ReadPeriod("Period One");

    cout <<"Period length is : " << calculate_Period_Length(Period) << " Days" << endl;
    cout << "Period length (Including Last Day) is : " << calculate_Period_Length(Period, true) << " Days" << endl;

    return 0;
}