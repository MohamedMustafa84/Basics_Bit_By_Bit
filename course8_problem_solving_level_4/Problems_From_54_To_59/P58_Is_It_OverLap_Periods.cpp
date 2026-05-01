#include <iostream>
#include "../../DateLib.h"
using namespace std;

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1,
};

enDateCompare Compare_Two_Dates(Date::stDate DateOne, Date::stDate DateTwo)
{

    if (Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
    {
        return enDateCompare::Before;
    }
    else if (Date::checker::isDateOneEqualDateTwo(DateOne, DateTwo))
    {
        return enDateCompare::Equal;
    }
    return enDateCompare::After;
}

bool isItOverLapPeriods(Date::stPeriod PeriodOne, Date::stPeriod PeriodTwo){

    if (Compare_Two_Dates(PeriodTwo.DateTo, PeriodOne.DateFrom) == enDateCompare::Before ||
        Compare_Two_Dates(PeriodTwo.DateFrom, PeriodOne.DateTo) == enDateCompare::After)
    {
        return false;
    }
    return true;
    
}

int main()
{
    // problem 
    // write a program to read two period and check if they any  overlap period or not 

    Date::stPeriod PeriodOne=  Date::ReadPeriod("Period One");
    Date::stPeriod PeriodTwo = Date::ReadPeriod("Period Two");

    cout << "Is It OverLap Period?\n";
    cout << (isItOverLapPeriods(PeriodOne, PeriodTwo)? "Yes , its OverLap Period" : "No, it Is Not Overlap Period");

    return 0;
}