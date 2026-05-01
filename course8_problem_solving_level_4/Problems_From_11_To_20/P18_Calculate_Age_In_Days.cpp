#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
using namespace std;

short  CalculateAgeInDays(Date::stDate DateOFBirth, Date::stDate CurrentDate)
{
    return Date::GetDifferenceInDays(DateOFBirth, CurrentDate);
}

int main()
{

    //  Problem 18

    // write  a program to Calculate Age IN Days

    Date::stDate DateOFBirth, CurrentDate;
    cout << "Please Enter The Date Of Birth :\n";
    DateOFBirth = Date::ReadFullDate();
    CurrentDate = Date::GetCurrentDate();

    cout << "The Age Is :" << CalculateAgeInDays(DateOFBirth, CurrentDate)<<" Days" << endl;

    return 0;
}