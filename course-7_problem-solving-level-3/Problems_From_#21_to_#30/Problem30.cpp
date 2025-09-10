#include <iostream>
#include <string>
#include "../MyLib.h"
using namespace std;



char ReadCharacter(){
    char Letter;
    cout << "please Enter a Character : ";
    cin >> Letter;
    return Letter;
}

short LetterCountInString(string Str, char Letter){
    short Counter = 0;
    for (short  i = 0; i < Str.length(); i++){
        if(Str[i]== Letter){
            Counter++;
        }
    }

    return Counter;
}

    int main()
{

    // Problem
    // write a program to  read string and read character then count the character in the string


    string Str = UserInputs::ReadString("please Enter Your String: ");
    char Letter = ReadCharacter();

    cout << "Letter " << Letter << " Count = " << LetterCountInString(Str, Letter);

    return 0;
}