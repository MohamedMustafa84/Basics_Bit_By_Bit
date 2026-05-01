#include <iostream>
#include "../../MyLib.h"
using namespace std;

struct stDate
{
    short Day;
    short Month;
    int Year;
};

stDate ReadDate(){
    stDate Date;

    Date.Day= UserInputs::ReadPositiveNumber("Please Enter The Day : ");
    Date.Month = UserInputs::ReadPositiveNumber("Please Enter The Month  : ");
    Date.Year= UserInputs::ReadPositiveNumber("Please Enter The Year  : ");
    return Date;
}

bool isDateOneBeforeDateTwo(stDate DateOne,stDate DateTwo){

    return (DateOne.Year < DateTwo.Year) ? true : (DateOne.Year == DateTwo.Year) ? 
    (DateOne.Month < DateTwo.Month) ? true : (DateOne.Month == DateTwo.Month) ? 
    DateOne.Day < DateTwo.Day : false:false;

}

    int main()
{

        //  Problem 13
        // write  a program to read two date and check if DateOne less Than DateTwo Or Not

        stDate DateOne, DateTwo;

        char Answer = 'Y';

        do{
            cout << "----- Date One -----\n";
            DateOne = ReadDate();
            cout << "----- Date Two -----\n";
            DateTwo = ReadDate();

            cout << (isDateOneBeforeDateTwo(DateOne, DateTwo) ? "Yes Date One Is before Date Two" : "No Date One Is Not before Date Two") << endl;

            cout << "\nDo You Want To Try Answer Two Dates ?(Y/N) ";
            cin >> Answer;
        } while (toupper(Answer) == 'Y');

        return 0;
    }