#include <iostream>
#include "../../MyLib.h"
using namespace std;

struct stDate
{
    short Day;
    short Month;
    int Year;
};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

stDate ReadDate(stDate Date)
{
    
    Date.Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");
    Date.Month = UserInputs::ReadNumberInRange("Please Enter The Month  : ",1,12);
    Date.Day = UserInputs::ReadNumberInRange("Please Enter The Day : ",1,31);

    while (Date.Month == 2 && Date.Day > 29){
        Date.Day = UserInputs::ReadPositiveNumber("\nInvalid Input, Month 2 Have Maximum 28 Days Please Enter Valid Day : ");
        cout << endl;
    }

    while (isLeapYear(Date.Year) && Date.Month == 2 && Date.Day > 28)
    {

        cout << "Invalid  Input , Month 2 in the Year " << Date.Year << " Have Maximum 28 Days Please Enter Valid Day : ";
        Date.Day = UserInputs::ReadPositiveNumber("");
    }

    return Date;
}



bool isDateOneEqualDateTwo(stDate DateOne, stDate DateTwo)
{

    return (DateOne.Year == DateTwo.Year) ? (DateOne.Month == DateTwo.Month) ? DateOne.Day == DateTwo.Day :false :false;

}

int main()
{

    //  Problem 14
    // write  a program to read two date and check if DateOne Equal DateTwo Or Not

    stDate DateOne, DateTwo;

    char Answer = 'Y';

    do
    {
        cout << "----- Date One -----\n";
        DateOne = ReadDate(DateOne);
        cout << "----- Date Two -----\n";
        DateTwo = ReadDate(DateTwo);

        cout << (isDateOneEqualDateTwo(DateOne, DateTwo) ? "Yes Date One Equal Date Two" : "No Date One Is Not Equal Date Two") << endl;

        cout << "\nDo You Want To Try Answer Two Dates ?(Y/N) ";
        cin >> Answer;
    } while (toupper(Answer) == 'Y');

    return 0;
}