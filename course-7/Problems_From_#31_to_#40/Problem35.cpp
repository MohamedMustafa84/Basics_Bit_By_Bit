#include <iostream>
#include "../MyLib.h"
#include <string>
using namespace std;

string ReadString(){
 string Str;
    cout << "Please enter you String :" << endl;
    getline(cin, Str);
    return Str;
}

// ----solution1 ------
void printStringWords(string Str)
{
    cout << "your string words are : \n";
    for (size_t i = 0; i <Str.length(); i++)
    {
        if(Str[i] !=' '){
            cout << Str[i];
        }else{
            cout << endl;
        }
    }
}
// ----solution2 ------
void printEachWordInString(string S)
{
    string delim = " ";
    cout << "your string words are : \n";
    short postion = 0;
    string sWord;
    while ((postion = S.find(delim)) != string::npos)
    {
        sWord = S.substr(0, postion);
        if(sWord!=""){
            cout<<sWord<<endl;
        }
        S.erase(0, postion + delim.length());
    }
    if(S!=""){
        cout<<S<<
    }
}

int main()
{
    
    // Problem
    // write a program to  read a string then print  each word in that string

    

    
    // ----solution1 ------
    printStringWords (ReadString());
    // ----solution2 ------
    printEachWordInString(ReadString());
    
    return 0;
}