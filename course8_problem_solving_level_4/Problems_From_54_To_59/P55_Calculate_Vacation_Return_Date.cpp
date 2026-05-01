#include <iostream>
#include "../../DateLib.h"
using namespace std;


Date::stDate calculateVacationReturnDate(Date::stDate Date, int VacationDays)
{

    while (VacationDays>0)
    {
        if (Date::checker::isBusinessDay(Date))
        {
            VacationDays--;
        }
        Date = Date::Increase::IncreaseDateByOneDay(Date);
    }
    return Date;
}

void PrintDate(Date::stDate Date)
{
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main()
{

    // Problem
    // write a aprogram to read vacation Start dateFrom and VacationDays, 
    // then make a function to calculate the vacation return Date.
    // Note: weekends are excluded

    cout << "Please Enter The Vacation StartDate :\n";
    Date::stDate VacationStartDate = Date::ReadFullDate();

    int VacationDays = UserInputs::ReadPositiveNumber("Please Enter The Vacation Days");

    Date::stDate ReturnDate = calculateVacationReturnDate(VacationStartDate, VacationDays);

    cout << "Return Date is  " << Date::DayShortName(Date::DayOfWeekOrder(ReturnDate)) << " , ";
    PrintDate(ReturnDate);

    return 0;
}