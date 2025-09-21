#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

namespace UserInputs
{
     int ReadNumber(string Message)
    {
        int Number;
        cout << Message;
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


