#include <iostream>
#include <string>
using namespace std;

char ReadCharacter()
{
    char character;
    cout << "please Enter  character to invert it  : ";
    cin >> character;
    return character;
}
char invertCharacterCase(char Character)
{

    return isupper(Character) ? tolower(Character) : toupper(Character);
}

int main()
{

    // Problem
    // write a program to  Read character  then  invert its Case and Print it
    char Character = ReadCharacter();

    Character= invertCharacterCase(Character);
    cout << "the Character after inverting the case :" << endl;
    cout << Character << endl;

    return 0;
}