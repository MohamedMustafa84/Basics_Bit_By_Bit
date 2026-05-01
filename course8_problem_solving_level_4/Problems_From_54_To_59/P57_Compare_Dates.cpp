#include <iostream>
#include "../../DateLib.h"
using namespace std;

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1,
};



enDateCompare CompareTwoDates(Date::stDate DateOne, Date::stDate DateTwo){

    if (Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo)){
        return enDateCompare::Before;
    }
    else if (Date::checker::isDateOneEqualDateTwo(DateOne, DateTwo)){
        return enDateCompare::Equal;

    }
        return enDateCompare::After;
}

    int main()
{

    // Problem
    // write a aprogram to read DateOne And DateTwo and write a function to compare Dates it Should return 
    // 
    // -1 Before
    // 0 Equal
    // 1 After

    Date::stDate DateOne, DateTwo;

    cout << "Enter Date One :\n";
    DateOne = Date::ReadFullDate();

    cout << "Enter Date Two :\n";
    DateTwo = Date::ReadFullDate();

    cout << "Compare Result = " << CompareTwoDates(DateOne, DateTwo) << endl;

    return 0;
}