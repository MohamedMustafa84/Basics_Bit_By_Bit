#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;

void PrintDate(Date::stDate Date){
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}


bool isEndOfWeek(Date::stDate Date){
    return Date::DayOfWeekOrder(Date) == 6;
}

bool isWeekEnd(Date::stDate Date)
{
    short DayIndex = Date::DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool isBusinessDay(Date::stDate Date)
{
    return !isWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(Date::stDate Date)
{
    return 6 - Date::DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(Date::stDate Date){
    return Date::NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
}

short DaysUntilTheEndOfYear(Date::stDate Date){
    short DaysNumber = 0;
    DaysNumber += DaysUntilTheEndOfMonth(Date);
    Date.Month++;
    while(Date.Month<=12){
        DaysNumber += Date::NumberOfDaysInAMonth(Date.Month, Date.Year);
        Date.Month++;
    }
    return DaysNumber;
}

int main(){
    
    // Problems
    // Write A Program To Read Date And Make Function As Follows:

    Date::stDate Date = Date::ReadFullDate();

    // P47 OverLoad The DayOfWeekOrder To Take Date Structure

    int DayOrder = Date::DayOfWeekOrder(Date);
    cout<< "Today Is  " <<Date::DayShortName(DayOrder)<<", ";
    PrintDate(Date);

    // P48 check if it End Of Week
    cout << "is it End Of Week ? " << endl;
    
    cout << (isEndOfWeek(Date) ? "Yes , End Of Week" : "No , Not End Of Week") << endl;
    
    // P49 check if it WeekEnd Of Week
    cout << "is it the Weekend ? " << endl;
    cout << (isWeekEnd(Date) ? "Yes , This Is The Weekend" : "NO , This Is Not The Weekend") << endl;
    
    // P50 check if it Business Day
    cout << "is it the Business Day ? " << endl;
    cout << (isBusinessDay(Date) ? "Yes , It Business Day " : "NO , This Is Not a Business Day") << endl;

    // P51 Calculate Days Until The End Of Week
    cout << "The Number Of Days Until End Of Week Is : " << DaysUntilTheEndOfWeek(Date) <<" Day(s)"<< endl;

    // P52 Calculate Days Until The End Of Month
    cout << "The Number Of Days Until End Of Month Is : " << DaysUntilTheEndOfMonth(Date) <<" Day(s)"<< endl;

    // P53 Calculate Days Until The End Of Year
    cout << "The Number Of Days Until End Of Year Is : " << DaysUntilTheEndOfYear(Date) <<" Day(s)"<< endl;
    return 0;
}