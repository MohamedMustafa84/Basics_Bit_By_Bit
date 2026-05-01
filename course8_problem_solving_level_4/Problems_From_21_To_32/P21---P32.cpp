#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;

Date::stDate Increase_Year_ByXDays(Date::stDate stDate, int &NumberOfIncreaseDays)
{

    while (NumberOfIncreaseDays >= 365)
    {
        stDate.Year++;
        if (Date::checker::isLeapYear(stDate.Year))
        {
            NumberOfIncreaseDays -= 365;
        }
        else
        {
            NumberOfIncreaseDays -= 364;
        }
    }
    return stDate;
}

Date::stDate Increase_Month_ByXDays(Date::stDate stDate, int &NumberOfIncreaseDays)
{

    while (NumberOfIncreaseDays >= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year))
    {

        NumberOfIncreaseDays -= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);

        if (stDate.Month == 12)
        {
            stDate.Month = 1;
            stDate.Year++;
        }
        else
        {
            stDate.Month++;
        }
    }
    return stDate;
}

Date::stDate Increase_Date_ByXDays(Date::stDate stDate, int RemainingDays)
{

    stDate = Increase_Year_ByXDays(stDate, RemainingDays);
    stDate = Increase_Month_ByXDays(stDate, RemainingDays);

    stDate.Day += RemainingDays;

    if (stDate.Day > Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year))
    {
        if (stDate.Month == 12)
        {

            stDate.Month = 1;
            stDate.Year++;
        }
        stDate.Month++;
        stDate.Day -= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);
    }
    return stDate;
}


Date::stDate Increase_Date_ByOneWeek(Date::stDate stDate)
{
    return Increase_Date_ByXDays(stDate, 7);
}

Date::stDate Increase_Date_ByXWeeks(Date::stDate Date, int NumOfAddingWeeks){
    return Increase_Date_ByXDays(Date, NumOfAddingWeeks * 7);
}



Date::stDate Increase_Date_ByOneMonth(Date::stDate Date){
    if(Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    return Date;
}

Date::stDate Increase_Date_ByXMonth(Date::stDate Date,int  NumOfAddingMonths){
    Date.Year = Date.Year + (NumOfAddingMonths / 12);
    Date.Month = Date.Month + (NumOfAddingMonths % 12);
     if (Date.Month > 12){
        Date.Month = Date.Month - 12;
        Date.Year++;
     }

     return Date;
}

Date::stDate Increase_Date_ByOneYear(Date::stDate  Date){
    Date.Year++;
    return Date;
}

Date::stDate Increase_Date_ByXYear(Date::stDate Date,int NumOfAddingYears){
    Date.Year = Date.Year + NumOfAddingYears;
    return Date;
}

Date::stDate Increase_Date_ByOneDecade(Date::stDate Date){
    Date.Year = Date.Year + 10;
    return Date;
}

Date::stDate Increase_Date_ByXDecade(Date::stDate Date,int NumOfAddingDecades){
    Date.Year+= NumOfAddingDecades * 10;
    return Date;
}

Date::stDate Increase_Date_ByOneCentury(Date::stDate Date){
    Date.Year = Date.Year + 100;
    return Date;
}

Date::stDate Increase_Date_ByOneMillennium(Date::stDate Date){
    Date.Year += 1000;
    return Date;
}

    int main()
{

    //  Problems from  21 to 32

    // write  a program to read date and make a functions to increase date as follows:

    Date::stDate Date, NewDate;
    Date = Date::ReadFullDate();


    // p21 increase date by One week 
 
    NewDate = Increase_Date_ByOneWeek(Date);

    cout << "Date After AddingOne Week is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p22 increase date by x week
    int NumOfAddingWeeks = UserInputs::ReadPositiveNumber("Please Enter Number Of Weeks To Add : ");

    NewDate = Increase_Date_ByXWeeks(NewDate, NumOfAddingWeeks);

    cout << "Date After Adding " << NumOfAddingWeeks <<" Weeks is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;


    // p23 increase date by One Month

    NewDate = Increase_Date_ByOneMonth(NewDate);

    cout << "Date After Adding One Month is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p24 increase date by x Month
    int NumOfAddingMonths = UserInputs::ReadPositiveNumber("Please Enter Number Of Months To Add : ");

    NewDate = Increase_Date_ByXMonth(NewDate, NumOfAddingMonths);

    cout << "Date After Adding " << NumOfAddingMonths << " Months is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p25 increase date by One Year

    NewDate = Increase_Date_ByOneYear(NewDate);

    cout << "Date After Adding Year is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p26 increase date by x Years
    int NumOfAddingYears = UserInputs::ReadPositiveNumber("Please Enter Number Of Year To Add : ");

    NewDate = Increase_Date_ByXYear(NewDate, NumOfAddingYears);

    cout << "Date After Adding " << NumOfAddingYears << " Years is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p28 increase date by One Decade

    NewDate = Increase_Date_ByOneDecade(NewDate);

    cout << "Date After Adding One Decade is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p29 increase date by x Decade
    int NumOfAddingDecades = UserInputs::ReadPositiveNumber("Please Enter Number Of Decade To Add : ");

    NewDate = Increase_Date_ByXDecade(NewDate, NumOfAddingDecades);

    cout << "Date After Adding " << NumOfAddingDecades << " Decade is ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p31 increase date by One Century

    NewDate = Increase_Date_ByOneCentury(NewDate);

    cout << "Date After Adding One Century is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    // p32 increase date by One Millennium

    NewDate = Increase_Date_ByOneMillennium(NewDate);

    cout << "Date After Adding One Millennium is  ";
    cout << NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year << endl;

    return 0;
}

