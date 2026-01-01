#pragma once
#include <iostream>
#include <string>
#include <limits>

#include "ClsString.h"
#include "ClsDate.h"

using std::cin;
using std::cout;
using std::string;

class clsInputValidate{
    public :

       
    template <typename T>

    static bool IsNumberBetween(T Number, T From, T To)
	{
        return (Number >= From && Number <= To);
    }

	
    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date>=From && Date<=To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // Date>=To && Date<=From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    static  string ReadString()
    {
        string Str;
        // Usage std::ws will extract all the whitespace character
        getline(cin >> std::ws, Str);
        return Str;
    }

    template <typename T>


    static T ReadNumber(string ErrorMessage = "Invalid Input, Enter again\n")
    {
        T Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }
    template <typename T>

    static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number = ReadNumber<T>();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number =ReadNumber<T>();
        }
        return Number;
    }


    
    static bool IsValidDate(const clsDate & Date)
    {
        return clsDate::IsValidDate(Date);
    }

};