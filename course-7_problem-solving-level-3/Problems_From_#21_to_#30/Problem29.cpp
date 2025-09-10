#include <iostream>
#include <string>
#include "../MyLib.h"
using namespace std;

enum enWhatToCount
{
    CapitalLetters = 1,
    SmallLetters = 2,
    All = 3
};



short countLetters(string Str,enWhatToCount countType){
    if(countType == enWhatToCount::All){
        return (short)Str.length();
    }

    short counter = 0;
    for (size_t i = 0; i < Str.length();i++){
        if(countType== enWhatToCount::CapitalLetters && isupper(Str[i]))
            counter++;

        if (countType == enWhatToCount::SmallLetters && islower(Str[i]))
            counter++;
    }
    return counter;
}

int main()
{

    // Problem
    // write a program to  read string then count small / capital  letter in that string

    string Str = UserInputs::ReadString("please Enter Your String: ");

    cout << "String Length = " << countLetters(Str, enWhatToCount::All)<<endl;
    cout << "Capital Letters Count  = " << countLetters(Str, enWhatToCount::CapitalLetters) << endl;
    cout << "Small Letters Count  = " << countLetters(Str, enWhatToCount::SmallLetters) << endl;

    return 0;
}