
#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string String;
    cout << "please Enter  character to invert it  : ";
    cin >> String;
    return String;
}
char invertCharacterCase(char Character)
{

    return isupper(Character) ? tolower(Character) : toupper(Character);
}

string invertStringCase(string str){
    for (size_t i = 0; i < str.length(); i++){
        str[i] = invertCharacterCase(str[i]);
    }
    return str;
}

int main()
{

    // Problem
    // write a program to  invert the string case
    string Str = ReadString();

    cout << "the String after inverting  all letters case :" << endl;
    cout << invertStringCase(Str) << endl;

    return 0;
}