#include <iostream>
#include "../../MyLib.h"
using namespace std;


bool isLeapYear(int year){
    if (year % 400 == 0){
        return true;
    }else if (year % 4 ==0 && year % 100 !=0){
        return true;
    }
    return false;
}



int main()
{

    // Problem 2
    // Write  a program to check if year is a leap year or not 

    // Note 
    // all year which are perfectly divisible by 4 are leap years except for century year (year ending with 00)
    // which are leap year only if are perfectly divisible  by 400

    int year = UserInputs::ReadPositiveNumber("Please Enter The Year To Check If It Leap Year Or Not : ");

    cout << ((isLeapYear(year)) ? "Yes :This Year Is Leap Year" : "No:This Year Is Not Leap Year");

    return 0;
}