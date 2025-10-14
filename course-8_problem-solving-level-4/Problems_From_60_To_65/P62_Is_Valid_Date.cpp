#include <iostream>
#include "../../DateLib.h"
using namespace std;

bool isValidDate(Date::stDate stDate)
{
    return (stDate.Year > 0 ? (stDate.Month >= 1 || stDate.Month <= 12) ? stDate.Day <= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year) : false : false);
}

int main()
{
    // problem
    // write a program to read Date and check if it A valid date oor not
    Date::stDate Date;

    Date.Day = UserInputs::ReadNumber("Enter the Day : ");
    Date.Month = UserInputs::ReadNumber("Enter the Month : ");
    Date.Year = UserInputs::ReadNumber("Enter the Year : ");

    cout << (isValidDate(Date) ? "Yes , the date is valid " : "No, the date is not valid") << endl;

    return 0;
}