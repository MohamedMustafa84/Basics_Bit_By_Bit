#include <iostream>
#include "../../MyLib.h"
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth(int Year, int Month)
{

    short arrNumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? isLeapYear(Year) ? 29 : 28 : arrNumberOfDays[Month - 1];
}



 int NumberOfDaysFromBeginingOfYear(int Day, int Month,int Year){

     int TotalDays = 0;
     for (short i = 1; i <Month; i++){
        TotalDays +=NumberOfDaysInAMonth(Year, i);
     }
     TotalDays += Day;

     return TotalDays;
 }

int main()
{

    //  Problem 10
    // write  a program to Print Total Days From The Begining os Year to the given date

    int Day = UserInputs::ReadPositiveNumber("Please Enter The Day : ");
    int Month = UserInputs::ReadPositiveNumber("Please Enter The Month  : ");
    int Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");

    cout << "Number Of Days From Begining Of The Year Is " << NumberOfDaysFromBeginingOfYear(Day, Month, Year);

    return 0;
}