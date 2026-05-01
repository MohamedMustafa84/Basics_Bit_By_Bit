#include <iostream>
#include "../MyLib.h"
#include <string>
using namespace std;



bool isVowel(char Char)
{
    // Char =tolower(Char);
    Char = tolower((unsigned char)Char);
    return (Char == 'a' || Char == 'e' || Char == 'i' || Char == 'o' || Char == 'u');
}

short CountVowelsInString(string Str){
    short vowelCount = 0;
    for (short i = 0; i < Str.length();i++){
        if(isVowel(Str[i])){
            vowelCount++;
        }
    }
    return vowelCount;
}

    int main()
{

    // Problem
    // write a program to  read a string then count all vowels in that string   (Vowel are : a e i o u)

    string Str = UserInputs::ReadString("Please enter you String :");
    cout << "Number of Vowels is : " << CountVowelsInString(Str) << endl;

    
    return 0;
}