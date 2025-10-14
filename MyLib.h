#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
using namespace std; 

namespace UserInputs
{
     int ReadNumber(string Message)
    {
        int Number;
        cout <<" "<< Message;
        cin >> Number;
        cout << "\n";
        while (cin.fail())
        {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\nInvalid input , Please Enter A Number:" << endl;
            cin >> Number;
        }

        return Number;
    }

    int ReadPositiveNumber(string message){
         int  Number = ReadNumber(message);
        while(Number<=0){
            Number = ReadNumber("Invalid Input The Number Most Be Greater Than Zero Please Retry : ");
        }
        return Number;
    }



    int ReadNumberInRange(string Message, int from ,int to){


        int Number;
        cout << Message << " from "<<from<<" to "<<to<<" : ";
        cin >> Number;
        while (cin.fail())
        {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\nInvalid input , Please Enter A Number:" << endl;
            cin >> Number;
        }


        while(Number <from ||Number>to){
            cout << "\nThe Number Most be Between " << from << " and " << to << " Please retry :";
            Number = ReadNumber("");
        }
        cout << endl;
        
        return Number;
    }

    string ReadString(string prompt)
    {
        string Str;
        cout << prompt << endl;
        getline(cin>>ws, Str);
        return Str;
    }
}

namespace Checker
{
    bool isPositiveNumber(int Number)
    {
        return (Number >= 0) ? true : false;
    }
}

namespace Random{


    int RandomNumber(){
        return rand();
    }

    int RandomNumberInRange(int from ,int to){
        return rand() % (to - from + 1) + from;
    }

}


namespace Invert{
    char invertCharacterCase(char Character)
    {

        return isupper(Character) ? tolower(Character) : toupper(Character);
    }
}


namespace String {

    vector<string> splitString(string Str, string delim)
    {
        vector<string> vString;

        int position = 0;
        string Word = "";

        while ((position = Str.find(delim)) != string::npos)
        {
            Word = Str.substr(0, position);

            if (Word != "")
            {
                vString.push_back(Word);
            }
            Str.erase(0, position + delim.length());
        }
        if (Str != "")
        {
            vString.push_back(Str);
        }

        return vString;
    }

    string Replace_Word_In_String(string Str, string StringToReplace, string StrReplaceTo)
    {

        int position = Str.find(StringToReplace);

        while (position != std::string::npos)
        {
            Str.replace(position, StringToReplace.length(), StrReplaceTo);
            position = Str.find(StringToReplace);
        }

        return Str;
    }
}

