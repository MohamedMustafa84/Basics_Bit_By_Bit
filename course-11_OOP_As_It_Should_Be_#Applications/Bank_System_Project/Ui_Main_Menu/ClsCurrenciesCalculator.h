#pragma once

#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "../ClsCurrencies.h"
#include "../../../Libs/ClsInputsValidate.h"
#include "../../../Libs/ClsString.h"

class clsCurrenciesCalculator: public clsScreen
{
    static void _PrintCurrencyCard(clsCurrency &Currency,string Message)
    {
        cout <<"\n"<< Message;
        cout << "\n_______________________________________\n";
        cout << "Currency Country : " << Currency.Country();
        cout << "\nCurrency Code  : " << Currency.CurrencyCode();
        cout << "\nCurrency Name  : " << Currency.CurrencyName();
        cout << "\nCurrency Rate  : " << Currency.Rate();
        cout << "\n_______________________________________\n";
    }


    static clsCurrency _GetCurrency(string Message)
    {
        cout << "\n"<<Message;
        string CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::isCurrencyExist(CurrencyCode))
        {
            cout << "\n Currency Is Not Found chose Another :";
            CurrencyCode = clsInputValidate::ReadString();
        }

        return clsCurrency::FindByCode(CurrencyCode);
    }

    static float _ReadAmount(){
        cout << "\nEnter Amount To Exchange :";
        return clsInputValidate::ReadNumber<float>();
    }




    static void _PrintCalculationResult(clsCurrency &Currency1, clsCurrency &Currency2,float &Amount){

        _PrintCurrencyCard(Currency1, "Convert From");

        float AmountInUSD = Currency1._ConvertToUSD(Amount);

        cout << Amount << Currency1.CurrencyCode();
        cout << " = " << AmountInUSD <<" USD\n";

        if (Currency2.CurrencyCode() == "USD"){
            return;
        }

        cout << "\nConverting From USD To :";
        _PrintCurrencyCard(Currency2, "To");

        float AmountInCurrency2 = Currency1._ConvertToOtherCurrency(Currency2, Amount);

        cout << Amount << Currency1.CurrencyCode();
        cout << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << endl;
    }

public:
    static void Calculator()
    {

        _DrawScreenHeader("Currency Calculator");

        char Answer = 'n';

        do{

            clsCurrency CurrencyFrom = _GetCurrency("Enter Currency1 Code :");
            clsCurrency CurrencyTo = _GetCurrency("Enter Currency2 Code :");
            float Amount = _ReadAmount();

            _PrintCalculationResult(CurrencyFrom, CurrencyTo, Amount);

            cout<< "\nDo You Want To Preform Another Calculation ?(Y/N) ";
            cin >> Answer;
        } while (toupper(Answer) == 'Y');
    }
};