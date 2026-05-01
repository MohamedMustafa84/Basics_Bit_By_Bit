#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;




Date::stDate DecreaseDateByOneDay(Date::stDate stDate)
{
    if (1==stDate.Day)
    {

        if (1==stDate.Month)
        {
            stDate.Day = 31;
            stDate.Month = 12;
            stDate.Year--;
        }
        else
        {
            stDate.Day = Date::NumberOfDaysInAMonth(stDate.Month -1,stDate.Year);
            stDate.Month--;
        }
    }
    else
    {
        stDate.Day--;
    }
    return stDate;
}

Date::stDate DecreaseYearByXDays(Date::stDate stDate, int &NumberOfSubtractDays)
{

    while (NumberOfSubtractDays >= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365))
    {

        NumberOfSubtractDays -= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365);
        stDate.Year--;
    }

    return stDate;
}
Date::stDate DecreaseMonthByXDays(Date::stDate stDate, int &NumberOfSubstractDays)
{
    while (NumberOfSubstractDays >= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year))
    {
        NumberOfSubstractDays -= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);

        if (stDate.Month == 1)
        {
            stDate.Month = 12;
            stDate.Year--;
        }
        else
        {
            stDate.Month--;
        }
    }

    while (NumberOfSubstractDays > 0)
    {
        stDate = DecreaseDateByOneDay(stDate);
        NumberOfSubstractDays--;
    }

    return stDate;
}

Date::stDate DecreaseDateByXDays(Date::stDate stDate, int RemainingDays)
{

    stDate = DecreaseYearByXDays(stDate, RemainingDays);
    stDate = DecreaseMonthByXDays(stDate, RemainingDays);
    while (RemainingDays > 0)
    {
        if (RemainingDays >= stDate.Day)
        {
            RemainingDays -= stDate.Day;

            if (stDate.Month == 1)
            {
                stDate.Month = 12;
                stDate.Year--;
            }
            else
            {
                stDate.Month--;
            }

            stDate.Day = Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);
        }
        else
        {
            stDate.Day -= RemainingDays;
            RemainingDays = 0;
        }
    }

    return stDate;
}

Date::stDate DecreaseDateByOneWeek(Date::stDate stDate)
{
    for (short i = 1; i <= 7; i++){
        stDate = DecreaseDateByOneDay(stDate);
    }
       return stDate ;
}

Date::stDate DecreaseDateByXWeeks(Date::stDate Date, int NumOfSubtractWeeks)
{
    for (short i = 1; i <= NumOfSubtractWeeks; i++){
        
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date ;
}



Date::stDate DecreaseDateByOneMonth(Date::stDate Date)
{
    if (1== Date.Month)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    short MonthDays = Date::NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > MonthDays)
    {
        Date.Day = MonthDays;
    }
    return Date;
}

Date::stDate DecreaseDateByXMonth(Date::stDate Date, int NumOfSubtractMonths)
{
    int totalMonths = (Date.Year * 12 + Date.Month - 1) - NumOfSubtractMonths;
    Date.Year = totalMonths / 12;
    Date.Month = totalMonths % 12 + 1;

    return Date;
}

Date::stDate DecreaseDateByOneYear(Date::stDate Date)
{
    Date.Year--;
    short maxDays = Date::NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > maxDays)
        Date.Day = maxDays;

    return Date;
}

Date::stDate DecreaseDateByXYear(Date::stDate Date, int NumOfSubtractYears)
{
    Date.Year = Date.Year - NumOfSubtractYears;
    short maxDays = Date::NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > maxDays)
        Date.Day = maxDays;

    return Date;
}

Date::stDate DecreaseDateByOneDecade(Date::stDate Date)
{
    Date.Year = Date.Year - 10;
    return Date;
}

Date::stDate DecreaseDateByXDecade(Date::stDate Date, int NumOfSubtractDecades)
{
    Date.Year -= NumOfSubtractDecades * 10;
    short maxDays = Date::NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > maxDays)
        Date.Day = maxDays;

    return Date;
}

Date::stDate DecreaseDateByOneCentury(Date::stDate Date)
{
    Date.Year = Date.Year - 100;
    short maxDays = Date::NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > maxDays)
        Date.Day = maxDays;

    return Date;
}

Date::stDate DecreaseDateByOneMillennium(Date::stDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{

    //  Problems from 33 to 45

    // write  a program to read date and make a functions to Decrease date as follows:

    Date::stDate Date, NewDate;
    Date = Date::ReadFullDate();

    cout << "Date After:" << endl;

    // p33 Decrease date by One Day

    NewDate = DecreaseDateByOneDay(Date);

    cout << "Subtracting One Day is : ";

    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;


    // p34 Decrease date by X Days
    int NumOfSubtractDays = UserInputs::ReadPositiveNumber("Please Enter Number Of Days To Subtract : ");

    NewDate= DecreaseDateByXDays(NewDate, NumOfSubtractDays);

    cout << "Date After Subtracting "<<NumOfSubtractDays<<" Days is : ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p35 Decrease date by One week

    NewDate = DecreaseDateByOneWeek(NewDate);

    cout << "Date After Subtracting One Week is : ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p36 Decrease date by x week
    int NumOfSubtractWeeks = UserInputs::ReadPositiveNumber("Please Enter Number Of Weeks To Subtract : ");

    NewDate = DecreaseDateByXWeeks(NewDate, NumOfSubtractWeeks);

    cout << "Date After Subtracting " << NumOfSubtractWeeks << " Weeks is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p37 Decrease date by One Month

    NewDate = DecreaseDateByOneMonth(NewDate);

    cout << "Date After Subtracting One Month is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // P38 Decrease date by x Month
    int NumOfSubtractMonths = UserInputs::ReadPositiveNumber("Please Enter Number Of Months To Subtract : ");

    NewDate = DecreaseDateByXMonth(NewDate, NumOfSubtractMonths);

    cout << "Date After Subtract " << NumOfSubtractMonths << " Months is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // P40 Decrease date by One Year

    NewDate = DecreaseDateByOneYear(NewDate);

    cout << "Date After Subtracting Year is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // P42 Decrease date by x Years
    int NumOfSubtractingYears = UserInputs::ReadPositiveNumber("Please Enter Number Of Year To Subtract : ");

    NewDate = DecreaseDateByXYear(NewDate, NumOfSubtractingYears);

    cout << "Date After Subtracting " << NumOfSubtractingYears << " Years is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // P43 Decrease date by One Decade

    NewDate = DecreaseDateByOneDecade(NewDate);

    cout << "Date After Subtracting One Decade is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // P44 Decrease date by x Decade
    int NumOfSubtractingDecades = UserInputs::ReadPositiveNumber("Please Enter Number Of Decade To Subtract : ");

    NewDate = DecreaseDateByXDecade(NewDate, NumOfSubtractingDecades);

    cout << "Date After Subtracting " << NumOfSubtractingDecades << " Decade is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p45 Decrease date by One Century

    NewDate = DecreaseDateByOneCentury(NewDate);

    cout << "Date After Subtracting One Century is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p46 Decrease date by One Millennium

    NewDate = DecreaseDateByOneMillennium(NewDate);

    cout << "Date After Subtracting One Millennium is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    return 0;
}