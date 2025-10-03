#include <iostream>
#include "../../MyLib.h"
#include "../../DateLib.h"
#include <cmath>
using namespace std;



short GetDifferenceInDays(Date::stDate DateOne, Date::stDate DateTwo ,bool IncludeEndDay=false){

    short Days = 0;

    while(!Date::checker::isDateOneBeforeDateTwo(DateOne,DateTwo)){
        cout << "\nOperation Field , Because Date Two Is Less Than Date One Please ReInput The Two Dates : \n";
        cout << "Enter Date One :\n ";
        DateOne = Date::ReadFullDate();

        cout << "Enter Date Two :\n ";
        DateTwo = Date::ReadFullDate();
    }

    while(Date::checker::isDateOneBeforeDateTwo(DateOne,DateTwo)){
        Days++;
        DateOne = Date::Increase::IncreaseDateByOneDay(DateOne);
    }


        return IncludeEndDay?++Days:Days;



}

int main()
{

    //  Problem 17

        // write  a program to read dateOne and DateTwo And Make A Function To calculate The Difference Between DateOne And DateTwo And Include Optional Parameter To Include Last Day
        // Note : DateOne Should Be Less Than DateTwo
        //

        Date::stDate DateOne,
        DateTwo;
        cout << "Enter Date One:\n";
        DateOne = Date::ReadFullDate();
        cout << "Enter Date Two:\n";
        DateTwo = Date::ReadFullDate();

        short DifferenceByDays = GetDifferenceInDays(DateOne, DateTwo);

        cout << "Difference Between Two Dates is :" << DifferenceByDays << endl;

        cout << "Difference Between Two Dates Including Last Day is :" << GetDifferenceInDays(DateOne, DateTwo, true) << endl;
        return 0;
}