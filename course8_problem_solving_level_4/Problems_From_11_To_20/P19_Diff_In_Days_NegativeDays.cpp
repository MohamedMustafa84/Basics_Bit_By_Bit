#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;


void SwapDates(Date::stDate &DateOne, Date::stDate &DateTwo)
{
    Date::stDate Temp = DateOne;
    DateOne = DateTwo;
    DateTwo = Temp;
}


int Get_Difference_In_Days(Date::stDate DateOne, Date::stDate DateTwo, bool IncludeEndDay = false)
{

    int Days = 0;
    short SwapFlagValue = 1;

    if(!Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
    {
        SwapDates(DateOne, DateTwo);
        SwapFlagValue = -1;

    }

    while (Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
    {
        Days++;
        DateOne = Date::Increase::IncreaseDateByOneDay(DateOne);
    }

    return (IncludeEndDay ? Days+1: Days) *SwapFlagValue;
}

int main()
{

    //  Problem 19

    // write  a program to read dateOne and DateTwo And Make A Function To calculate The Difference Between DateOne And DateTwo And Include Optional Parameter To Include Last Day
    

    Date::stDate DateOne,
        DateTwo;
    cout << "Enter Date One:\n";
    DateOne = Date::ReadFullDate();
    cout << "Enter Date Two:\n";
    DateTwo = Date::ReadFullDate();

    short DifferenceByDays = Get_Difference_In_Days(DateOne, DateTwo);

    cout << "Difference Between Two Dates is :" << DifferenceByDays << endl;

    cout << "Difference Between Two Dates Including Last Day is :" << Get_Difference_In_Days(DateOne, DateTwo, true) << endl;
    return 0;
}