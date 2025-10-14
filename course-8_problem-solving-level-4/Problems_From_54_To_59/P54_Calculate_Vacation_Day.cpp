#include <iostream>
#include "../../DateLib.h"
using namespace std; 

struct stPeriod{
    Date::stDate DateFrom;
    Date::stDate DateTo;
};

stPeriod ReadPeriod(string PeriodName){
    stPeriod Period;
    cout << "Please Enter " << PeriodName << " Start  Date :\n";
    Period.DateFrom = Date::ReadFullDate();
    cout << "Now Enter The End " << PeriodName << " Date :\n";
    Period.DateTo = Date::ReadFullDate();

    return Period;
}



int calculateActualVacationDays(stPeriod Period){
    
    int VacationDays=0;
    while(Date::checker::isDateOneBeforeDateTwo(Period.DateFrom,Period.DateTo)){
        if (Date::checker::isBusinessDay(Period.DateFrom))
        {
            VacationDays++;
        }
        Period.DateFrom = Date::Increase::IncreaseDateByOneDay(Period.DateFrom);
    }
    return VacationDays;
}

void PrintDate(Date::stDate Date)
{
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main(){
    
    // Problem 
    // write a aprogram to read vacation period dateFrom and dateTo  and make a function to 
    // calculate the actual vacation day 
    // Note: weekends are excluded

    stPeriod Period = ReadPeriod("Vacation");

    cout << "Vacation From :" << Date::DayShortName(Date::DayOfWeekOrder(Period.DateFrom))<<" , ";
    PrintDate(Period.DateFrom);

    cout << "Vacation To :" << Date::DayShortName(Date::DayOfWeekOrder(Period.DateTo)) << " , ";
    PrintDate(Period.DateTo);

    cout << "Actual Vacation Days Is " << calculateActualVacationDays(Period) << " Day(s)" << endl;
    

    return 0;
}