#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;

Date::stDate Increase_Year_ByXDays(Date::stDate stDate,int &NumberOfIncreaseDays){
    
    while (NumberOfIncreaseDays >= (Date::checker::isLeapYear(stDate.Year)?366:365))
    {

        NumberOfIncreaseDays -= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365);
        stDate.Year++;
    }
    return stDate;
}

Date::stDate Increase_Month_ByXDays(Date::stDate stDate,int &NumberOfIncreaseDays){

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
    stDate=Increase_Month_ByXDays(stDate, RemainingDays);

    stDate.Day += RemainingDays;

    while(stDate.Day > Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year))
    {
        stDate.Day -= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);
        if(stDate.Month ==12){

            stDate.Month = 1;
            stDate.Year++;
        }else{

            stDate.Month++;
        }
    }
        return stDate;
}

int main()
{
 
    //  Problem 20

    // write  a program to read dateAnd Increase it By X Days And Print The New Date

    Date::stDate Date,NewDate;
    Date = Date::ReadFullDate();

    int NumOfAddingDays = UserInputs::ReadPositiveNumber("Please Enter Number Of Days To Add : ");

    NewDate = Increase_Date_ByXDays(Date, NumOfAddingDays);

    cout << "Date After Adding " << NumOfAddingDays << " is :";
    cout << NewDate.Day << "/" << NewDate.Month<<"/"<<NewDate.Year << endl;

    return 0;
}