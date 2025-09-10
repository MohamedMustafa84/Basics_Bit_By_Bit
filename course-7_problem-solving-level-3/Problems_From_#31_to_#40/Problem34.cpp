#include <iostream>
#include "../MyLib.h"
#include <string>
using namespace std;

bool isVowel(char Char)
{
    Char = tolower(Char);
    return (Char == 'a' || Char == 'e' || Char == 'i' || Char == 'o' || Char == 'u');
}

void  printStringVowels(string Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        if (isVowel(Str[i]))
        {
            cout << Str[i] << " ";
        }
    }
}

int main()
{

    // Problem
    // write a program to  read a string then print  all vowels in that string   (Vowel are : a e i o u)

    string Str = UserInputs::ReadString("please Enter Your String :");

    cout << "Vowels in string are : ";
     printStringVowels(Str);
     cout << endl;
     return 0;
}