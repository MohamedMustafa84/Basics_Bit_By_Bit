#include <iostream>
#include "../../MyLib.h"
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAYear(int Year){

    return (isLeapYear(Year)) ? 365 : 364;
}
short NumberOfHoursInAYear(int Year){
    return NumberOfDaysInAYear(Year) * 24;
}
short NumberOfMinutesInAYear(int Year)
{
    return NumberOfHoursInAYear(Year)* 60;
}

short NumberOfSecondInAYear(int Year)
{
    return NumberOfMinutesInAYear(Year) * 60 ;
}

void PrintNumber_OF_days_hours_minutes_secondsInAYear(int Year)
{

    cout << "The Numbers Of Days in The year " << Year << " is : " << NumberOfDaysInAYear(Year) << endl;
    cout << "The Numbers Of Hours in The year " << Year << " is : " << NumberOfHoursInAYear(Year) << endl;
    cout << "The Numbers Of Minutes in The year " << Year << " is : " << NumberOfMinutesInAYear(Year) << endl;
    cout << "The Numbers Of Minutes in The year " << Year << " is : " << NumberOfSecondInAYear (Year)<< endl;
}

int main(){
    
    // Problem 4
    // write  a program to print number of days hours minutes  seconds in specific Year

    int Year = UserInputs::ReadPositiveNumber("Please Enter The Year : ");
    PrintNumber_OF_days_hours_minutes_secondsInAYear(Year);

    return 0;
}