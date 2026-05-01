#include <iostream>
#include "../../DateLib.h"
using namespace std;

bool isDateOneAfterDateTwo(Date::stDate DateOne, Date::stDate DateTwo){
    return (!Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo) &&
    !Date::checker::isDateOneEqualDateTwo(DateOne,DateTwo));

}

    int main()
{

    // Problem
    // write a aprogram to read DateOne And DateTwo and Check If DateOne Before DateTwo Or Not 


    Date::stDate DateOne,DateTwo;

    cout << "Enter Date One :\n";
    DateOne = Date::ReadFullDate();

    cout << "Enter Date Two :\n";
    DateTwo = Date::ReadFullDate();

    cout << (isDateOneAfterDateTwo(DateOne, DateTwo) ? "Yes , Date One Is After Date Two" : "No , Date One Is Not After Date Two") << endl;
    return 0;
}