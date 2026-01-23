#pragma once

#include <iostream>
using namespace std;
#include "../../../Libs/ClsInputsValidate.h"
#include "../../../Libs/ClsString.h"
#include "ClsScreen.h"
#include "../ClsCurrencies.h"

class clsFindCurrency : protected clsScreen
{

    enum enFindCurrencyChoices
    {
        ByCode = 1,
        ByCountry = 2
    };

    static void _Print(clsCurrency &currency)
    {
        cout << "\n Currency Card ";
        cout << "\n-----------------------------------";
        cout << "\nCountry     : " << currency.Country();
        cout << "\nCode        : " << currency.CurrencyCode();
        cout << "\nName        : " << currency.CurrencyName();
        cout << "\nRate (1)$ =: " << currency.Rate();
        cout << "\n-----------------------------------\n";
    }

   static  enFindCurrencyChoices _ReadFindChoice()
    {
        cout << "\nFind Currency By [1]Code or [2]Country ? ";
        return enFindCurrencyChoices(clsInputValidate::ReadNumberBetween(1, 2));
    }



public:
    static void FindCurrency()
    {

        clsScreen::_DrawScreenHeader("Find Currency Screen");

        enFindCurrencyChoices FindType = _ReadFindChoice();

        clsCurrency Currency;
        string CurrencyCode;
        string CurrencyCountry;

        switch (FindType){
            case enFindCurrencyChoices::ByCode:
                cout << "\nPlease Enter Currency Code : ";
                CurrencyCode = clsInputValidate::ReadString();
                Currency = clsCurrency::FindByCode(clsString::UpperAllString(CurrencyCode));

                break;
            case enFindCurrencyChoices::ByCountry:
                cout << "\nPlease Enter Currency Country : ";
                CurrencyCountry = clsInputValidate::ReadString();
                Currency = clsCurrency::FindByCountry(clsString::UpperAllString(CurrencyCountry));
                break;
        }

        

        


        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _Print(Currency);
            return;
        }
        else
        {
            cout << "\nCurrency Not Found \n";
        }
    }
};
