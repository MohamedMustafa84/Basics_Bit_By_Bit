#include <iostream>
#include "../../MyLib.h"
using namespace std;


struct stDate{
    short Day;
    short Month;
    int Year;
};

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

 stDate GetDateFromDayOrderInYear(int NumberOfDays, int Year)
 {

     stDate stDate;
     stDate.Year = Year;
     stDate.Month = 1;

     short RemainingDays = NumberOfDays;

     while (true)
     {

         if (RemainingDays> NumberOfDaysInAMonth(Year, stDate.Month))
         {
             RemainingDays-= NumberOfDaysInAMonth(Year, stDate.Month);
             stDate.Month++;
         }
         else
         {
             stDate.Day = RemainingDays;
             break;
         }
     }

     return stDate;
 }

 int main()
{

    //  Problem 11
    // write  a program to Print Total Days From The Begining os Year to the given date
    // Then Take The Total Days And Convert It To Date

    int Day = UserInputs::ReadPositiveNumber("Please Enter The Day : ");
    int Month = UserInputs::ReadPositiveNumber("Please Enter The Month  : ");
    int Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");

    int  NumberOfDays = NumberOfDaysFromBeginingOfYear(Day, Month, Year);

    stDate stDate = GetDateFromDayOrderInYear(NumberOfDays, Year);

    cout << "Number Of Days From Begining Of The Year Is " <<NumberOfDays << endl;
    cout << "Date For [" << NumberOfDays << "] is : " << stDate.Day << "/" << stDate.Month << "/" << stDate.Year << endl;
        return 0;
}