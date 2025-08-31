#include <iostream>
#include "../MyLib.h"
#include <string>
using namespace std;

string ReadString()
{
    string Str;
    cout << "Please enter you String :" << endl;
    getline(cin, Str);
    return Str;
}


short  CountStringWords(string S)
{
    short WordCount = 0;
    string delim = " ";
    short postion = 0;
    string sWord;
    while ((postion = S.find(delim)) != string::npos)
    {
        sWord = S.substr(0, postion);
        if (sWord != "")
        {
            WordCount++;
        }
        S.erase(0, postion + delim.length());
    }
    if (S != "")
    {
        WordCount++;
    }
    return WordCount;
}

int main()
{

    // Problem
    // write a program to  read a string then count  each word in that string
    short wordCount =CountStringWords(ReadString());

    cout << "the Number of words in your string is " << wordCount <<endl;

    return 0;
}