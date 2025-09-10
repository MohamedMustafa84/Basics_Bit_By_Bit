#include <iostream>
#include <string>
#include <vector>
#include "../MyLib.h"
using namespace std;



vector<string>  SplitStringInVector(string Str, string separator)
{
    vector<string> vStringItems;
    short postion = 0;
    string sWord;
    while ((postion = Str.find(separator)) != string::npos)
    {
        sWord = Str.substr(0, postion);
        if (sWord != "")
        {
            vStringItems.push_back(sWord);
        }
        Str.erase(0, postion + separator.length());
    }
    if (Str != "")
    {
        vStringItems.push_back(Str);
    }
    return vStringItems;
}

string LowerAllString(string String)
{
    for (int i = 0; i < String.length(); i++)
    {
        String[i] = tolower(String[i]);
    }
    return String;
}

string JoinVectorContent(vector<string> &vectorItems, string separator)
{
    string JoinedString = "";
    for (string &word : vectorItems)
    {
        JoinedString += (word + separator);
    }

    return JoinedString.substr(0, JoinedString.length() - separator.length());
}

string Replace_Word_In_String_Using_custom_Function(string Str,string  stringToReplace, string StrReplaceTo,bool MatchCase =true){

    if(Str.find(stringToReplace)== std::string::npos){
        return "Sorry : The String You want To Replace Is Not Exist in This String :( \n";
    }

    vector<string> vString = SplitStringInVector(Str, " ");

    for (string &word : vString)
    {
        if(MatchCase){
            if(word== stringToReplace){
                word = StrReplaceTo;
            }
        }else {
            if(LowerAllString(word)==LowerAllString(stringToReplace)){
                word = StrReplaceTo;
            }
        }

    }

    return JoinVectorContent(vString, " ");
}



int main()
{
    
    // Problem
    // write a program to  replace word in string using custom Function and with optoin match case or not 
    
    string Str = UserInputs::ReadString("please Enter Your String: ");
    string strToReplace = UserInputs::ReadString("\nEnter The string You Want To Replace: ");
    string strReplaceTo = UserInputs::ReadString("\nEnter Your new string : ");
   
    cout
        << "Replace with match case :\n"
        << Replace_Word_In_String_Using_custom_Function(Str, strToReplace, strReplaceTo) << endl;
    cout << "Replace with not match case  :\n"
        << Replace_Word_In_String_Using_custom_Function(Str, strToReplace, strReplaceTo,false) << endl;

    return 0;
}