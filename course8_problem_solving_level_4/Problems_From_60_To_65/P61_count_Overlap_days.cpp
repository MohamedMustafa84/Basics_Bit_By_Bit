#include <iostream>
#include "../../DateLib.h"
using namespace std;




int CountOverlapDays(Date::stPeriod PeriodOne, Date::stPeriod PeriodTwo){

    int OverlapDays = 0;
    if(Date::checker::isItOverLapPeriods(PeriodOne,PeriodTwo)){

        if (!Date::checker::isDateOneBeforeDateTwo(PeriodOne.DateFrom, PeriodTwo.DateFrom)){
            Date::SwapDates(PeriodOne.DateFrom, PeriodTwo.DateFrom);
        }

            while (Date::checker::isDateOneBeforeDateTwo(PeriodOne.DateFrom, PeriodTwo.DateFrom))
            {
                PeriodOne.DateFrom = Date::Increase::IncreaseDateByOneDay(PeriodOne.DateFrom);
            }

        while (Date::checker::isDateOneEqualDateTwo(PeriodOne.DateFrom, PeriodTwo.DateFrom) && Date::checker::isDateOneBeforeDateTwo(PeriodOne.DateFrom, PeriodOne.DateTo)){

            if (Date::checker::isDateOneBeforeDateTwo(PeriodTwo.DateFrom, PeriodTwo.DateTo)){

                OverlapDays++;
                PeriodOne.DateFrom = Date::Increase::IncreaseDateByOneDay(PeriodOne.DateFrom);
                PeriodTwo.DateFrom = Date::Increase::IncreaseDateByOneDay(PeriodTwo.DateFrom);
            }
        }
    }

    return OverlapDays;
}

int main()
{
    // problem
    // write a program to read two period then count Overlap Days

    Date::stPeriod PeriodOne = Date::ReadPeriod("Period One");
    Date::stPeriod PeriodTwo = Date::ReadPeriod("Period Two");

    cout << "Is It OverLap Period?\n";
    cout << "Overlap Days Between the Two Period Is : " << CountOverlapDays(PeriodOne, PeriodTwo) << " Day(s)" << endl;
    

    return 0;
}