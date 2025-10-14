#include <iostream>
#include "../../MyLib.h"
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth( int Year,int Month)
{

    if (2==Month){
        return isLeapYear(Year)? 29:28;
    }

    short arrMonthsWith31Days[7]={1,3,5,7,8,10,12};

    for(short index :arrMonthsWith31Days){
        if(Month == arrMonthsWith31Days[index])
            return 31;
    }
    return 30;
}
short NumberOfHoursInAMonth(short DaysInAMonth)
{
     return DaysInAMonth * 24;
}
int NumberOfMinutesInAMonth( short DaysInAMonth)
{
    return NumberOfHoursInAMonth(DaysInAMonth) * 60;
}

int NumberOfSecondInAMonth(short DaysInAMonth)
{
    return NumberOfMinutesInAMonth(DaysInAMonth) * 60;
}

void PrintNumber_OF_days_hours_minutes_secondsInAMonth( int Month,short DaysInAMonth)
{

    cout << "Numbers Of Days in The Month " << Month << " is : " << DaysInAMonth<< endl;
    cout << "Numbers Of Hours in The Month " << Month << " is : " << NumberOfHoursInAMonth(DaysInAMonth) << endl;
    cout << "Numbers Of Minutes in The Month " << Month << " is : " << NumberOfMinutesInAMonth( DaysInAMonth) << endl;
    cout << "Numbers Of Minutes in The Month " << Month << " is : " << NumberOfSecondInAMonth( DaysInAMonth) << endl;
}

int main()
{

    // Problem 5
    // write  a program to print number of days hours minutes  seconds In Specific Month

    int Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");

    int Month = UserInputs::ReadNumberInRange("Please Enter The Month ",1,12);

    

    short DaysInAMonth = NumberOfDaysInAMonth(Year, Month);

    PrintNumber_OF_days_hours_minutes_secondsInAMonth(Month,DaysInAMonth);

    return 0;
}