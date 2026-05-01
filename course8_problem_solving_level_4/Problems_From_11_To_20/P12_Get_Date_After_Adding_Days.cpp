#include <iostream>
#include "../../MyLib.h"
using namespace std;

struct stDate
{
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

int NumberOfDaysFromBeginingOfYear(int Day, int Month, int Year)
{

    int TotalDays = 0;
    for (short i = 1; i < Month; i++)
    {
        TotalDays += NumberOfDaysInAMonth(Year, i);
    }
    TotalDays += Day;

    return TotalDays;
}

stDate GetDateFromDayOrderInYear(int NumberOfDays, int Year)
{

    stDate stDate;
    stDate.Year = Year;
    stDate.Month = 1;

    short RemainingDays= NumberOfDays;

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

stDate AddDaysToDate(int AdditionalDays ,stDate stDate)
{

    int RemainingDays = AdditionalDays + NumberOfDaysFromBeginingOfYear(stDate.Day,stDate.Month,stDate.Year);

    int MonthDays = 0;
    stDate.Month = 1;


    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(stDate.Year, stDate.Month);

        if (RemainingDays> MonthDays)
        {
            RemainingDays-= MonthDays;
            stDate.Month++;
            if(stDate.Month >12){
                stDate.Year++;
                stDate.Month = 1;
            }
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

        //  Problem 12
        // write  a program to read date and read how many days to add to it
        // Then print the new date after the previous operation

        int Day = UserInputs::ReadPositiveNumber("Please Enter The Day : ");
        int Month = UserInputs::ReadPositiveNumber("Please Enter The Month  : ");
        int Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");
        int AdditionalDays = UserInputs::ReadPositiveNumber("How Many Days You Want To Add : ");

        int NumberOfDays = NumberOfDaysFromBeginingOfYear(Day, Month, Year);

        stDate stDate = GetDateFromDayOrderInYear(NumberOfDays, Year);
        stDate = AddDaysToDate(AdditionalDays,stDate);


        cout << "Number Of Days From Begining Of The Year Is " << NumberOfDays << endl;
        cout << "Date After Adding [" << AdditionalDays << "] is : " << stDate.Day << "/" << stDate.Month << "/" << stDate.Year << endl;
        return 0;
    }