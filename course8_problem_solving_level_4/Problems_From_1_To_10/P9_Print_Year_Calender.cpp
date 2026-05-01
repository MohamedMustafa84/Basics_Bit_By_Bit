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

int DayOfWeekOrder(int Day, int Month, int Year)
{
    int a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}
string DayShortName(int DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

string MonthShortName(int Month)
{
    string arrMonthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return arrMonthNames[Month - 1];
}

void PrintMonthDays(int Year, int Month)
{
    short NumberOfMonthDays = NumberOfDaysInAMonth(Year, Month);
    short Current = DayOfWeekOrder(1, Month, Year);
    short NumOfWeekDays = 7;

    short i;
    for (i = 0; i < Current; i++)
    {
        cout << "\t";
    }

    for (short j = 1; j <= NumberOfMonthDays; j++)
    {

        cout << j << "\t";

        if (++i == NumOfWeekDays)
        {
            cout << "\n";
            i = 0;
        }
    }
}

void PrintMonthCalender(int Year, int Month)
{

    cout << "\n\n________________________ " << MonthShortName(Month) << " _______________________\n\n";
    for (short i = 0; i < 7; i++)
    {
        cout << DayShortName(i) << "\t";
    }
    cout << "\n";
    PrintMonthDays(Year, Month);
    cout << "\n_____________________________________________________\n\n";
}


void PrintYearCalender(int Year){

    cout << "======================== "<< Year << " Calender ==========================\n\n";
    for (int i=1; i<=12 ; i++){
        PrintMonthCalender(Year,i);
    }
}

int main()
{

    //  Problem 9
    // write  a program to Print Year Calender

    int Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");

    PrintYearCalender(Year);

    return 0;
}