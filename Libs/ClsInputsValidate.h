#pragma once
#include <iostream>
#include <string>
#include <limits>

#include "ClsString.h"
#include "ClsDate.h"


class clsInputValidate{
    public :

        static int ReadNumberInRange(string Message, int from, int to)
        {

            int Number;
            cout << Message << " from " << from << " to " << to << " : ";
            cin >> Number;

            while (!IsNumberBetween(Number, from, to))
            {
                cout << "\nThe Number Most be Between " << from << " and " << to << " Please retry :";
                cin >> Number;
            }
            cout << endl;

            return Number;
        }

    static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number , int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
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

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }
    

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDoubleNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadDoubleNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDoubleNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDoubleNumber();
        }
        return Number;
    }

    static int ReadPositiveIntNumber(string message , string ErrorMessage = "The Number Most Be Greater Than Zero Please Retry : ")
    {
        int Number = ReadIntNumber(message);
        while (Number <= 0)
        {
            Number = ReadIntNumber(ErrorMessage);
        }
        return Number;
    }

    static short ReadPositiveShortNumber(string message, string ErrorMessage = "The Number Most Be Greater Than Zero Please Retry : ")
    {
        short Number = ReadIntNumber(message);
        while (Number <= 0)
        {
            Number = ReadIntNumber(ErrorMessage);
        }
        return Number;
    }

    static float ReadPositiveFloatNumber(string message, string ErrorMessage = "The Number Most Be Greater Than Zero Please Retry : ")
    {
        float Number = ReadIntNumber(message);
        while (Number <= 0)
        {
            Number = ReadIntNumber(ErrorMessage);
        }
        return Number;
    }

    static double ReadPositiveDoubleNumber(string message, string ErrorMessage = "The Number Most Be Greater Than Zero Please Retry : ")
    {
        double Number = ReadIntNumber(message);
        while (Number <= 0)
        {
            Number = ReadIntNumber(ErrorMessage);
        }
        return Number;
    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

};