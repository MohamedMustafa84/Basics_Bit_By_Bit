#pragma once

#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "../ClsCurrencies.h"
#include "../../../Libs/ClsInputsValidate.h"
#include "../../../Libs/ClsString.h"

class clsUpdateRateScreen :public clsScreen {
    static void _PrintCurrencyInfo(clsCurrency &Currency)
    {
        cout << "\n\t Currency Details ";
        cout << "\n_______________________________________\n";
        cout << "Currency Country : "<< Currency.Country();
        cout << "\nCurrency Code  : "<<Currency.CurrencyCode();
        cout << "\nCurrency Name  : "<<Currency.CurrencyName();
        cout << "\nCurrency Rate  : "<< Currency.Rate();
        cout << "\n_______________________________________\n";
    }

    public :
        static void UpdateCurrencyRate(){

            _DrawScreenHeader("Update Currency Rate");
            cout << "Enter Currency Code :";
            string CurrencyCode =clsString::UpperAllString( clsInputValidate::ReadString());
            short Tries = 0;
            while(!clsCurrency::isCurrencyExist(CurrencyCode)&& Tries >=5){
                Tries++;
                cout << "\n incorrect Code Please Enter Again :";
                CurrencyCode =clsString::UpperAllString( clsInputValidate::ReadString());
                
            }

            if(Tries>5){
                cout << "\nwarning :Too match Tries Please contact Your Admin " << endl;
                return;
            }

            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

            _PrintCurrencyInfo(Currency);

            char Answer = 'n';
            cout <<"\nAre You Shower You Wont To Update the Rate Of This Currency :(Y/N) ";
            cin >> Answer;

            if (toupper(Answer) =='Y'){
                cout << "\nEnter New Rate :";
                float NewRate = clsInputValidate::ReadNumber<float>();
                Currency.UpdateRate(NewRate);

                cout << "\nCurrency Rate Updated Successfully :-) \n";
                _PrintCurrencyInfo(Currency);
            }else{
                cout <<"\nthe Operation Was Canceled "<<endl;
                return;
            }
        }
};