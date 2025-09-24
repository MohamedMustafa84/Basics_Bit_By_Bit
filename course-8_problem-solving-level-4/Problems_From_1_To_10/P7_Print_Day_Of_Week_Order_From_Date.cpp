#include <iostream>
#include "../../MyLib.h"
using namespace std;


int   DayOfWeekOrder( int Day,int Month, int Year ){
    int a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string DayShortName(int DayOfWeekOrder){
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}




int main()
{

//  Problem 7
// write  a program to  read the Date and print the day name of the week 


    int Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");
    int Month = UserInputs::ReadNumber("Please Enter The Month : ");
    int Day = UserInputs::ReadNumber("Please Enter The Day : ");


    int  Day_Of_Week_Order = DayOfWeekOrder(Day, Month, Year);
    

    cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << Day_Of_Week_Order;
    cout << "\nDay Name   : " << DayShortName(Day_Of_Week_Order);

    return 0;
}