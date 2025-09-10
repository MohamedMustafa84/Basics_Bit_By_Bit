#include <iostream>
#include <string>
#include <vector>
#include "../MyLib.h"
using namespace std;

vector <string> splitString(string Str,string delim){
    vector<string> vString;

    int position = 0;
    string Word = "";

    while((position = Str.find(delim)) != string::npos){
        Word = Str.substr(0, position);

        if(Word !=""){
            vString.push_back(Word);
        }
        Str.erase(0, position + delim.length());
    }
    if(Str !=""){
        vString.push_back(Str);
    }

    return vString;
}

 string reverseWordsInString(string Str) {
     vector<string> vString;
    string S2="";

    vString = splitString(Str, " ");


    // declare iterator
    vector<string>::iterator iter = vString.end();

    while(iter != vString.begin()){
        --iter;
        S2 += *iter + " ";
    }
    
    S2 = S2.substr(0, S2.length() - 1);

    return S2;
 }

int main()
{

    // Problem
    // write a program to  read a string and reverse its words order

    string Str = UserInputs::ReadString("please Enter Your String: ");

    cout << "string after reversing  word :\n"
         << reverseWordsInString(Str) << endl;

    return 0;
}