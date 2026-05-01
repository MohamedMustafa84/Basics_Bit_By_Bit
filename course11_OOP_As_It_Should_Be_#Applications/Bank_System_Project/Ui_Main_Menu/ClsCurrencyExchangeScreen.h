#pragma once
#include <iostream>
#include <iomanip>
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"

#include "ClsCurrenciesListScreen.h"
#include "ClsFindCurrency.h"
#include "ClsUpdateCurrencyRate.h"
#include "ClsCurrenciesCalculator.h"


using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
    enum _enCurrencyExchangeOptions
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateRate = 3,
        eCurrencyCalculator = 4,
        eMainMenu = 5

    };

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesList();
    }
    
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrency::FindCurrency();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateRateScreen::UpdateCurrencyRate();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrenciesCalculator::Calculator();
    }



    static void _BackTCurrencyExchangeMenu()
    {
        char Key;
        cout << setw(37) << left << "\nEnter Any Key to Back To Currency Exchange Menu ...\n";
        cin >> Key;
        // system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _PerformCurrencyExchangeOptions(_enCurrencyExchangeOptions Choice)
    {

        switch (Choice)
        {
        case _enCurrencyExchangeOptions::eListCurrencies:
            _ShowListCurrenciesScreen();
            _BackTCurrencyExchangeMenu();

            break;
        case _enCurrencyExchangeOptions::eFindCurrency:
            _ShowFindCurrencyScreen();
            _BackTCurrencyExchangeMenu();

            break;

        case _enCurrencyExchangeOptions::eUpdateRate:

            _ShowUpdateRateScreen();
            _BackTCurrencyExchangeMenu();
            break;
        case _enCurrencyExchangeOptions::eCurrencyCalculator:
            _ShowCurrencyCalculatorScreen();
            _BackTCurrencyExchangeMenu();
            break;

        case _enCurrencyExchangeOptions::eMainMenu:
            break;
        }
    }

public:
    static void ShowCurrencyExchangeScreen()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }
        _DrawScreenHeader("Currencies Exchange Screen");

        cout << setw(37) << left << "" << "================================================\n";
        cout << setw(37) << left << "" << "\t\t\t Currency Exchange Menu \n";
        cout << setw(37) << left << "" << "================================================\n";
        cout << setw(37) << left << "" << "\t[1] Currencies List \n";
        cout << setw(37) << left << "" << "\t[2] Find Currency\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu \n";

        cout << setw(37) << left << "" << "================================================\n";

        cout << setw(37) << left << "" << "\tChose What To Do From 1 to 5? ";
        _PerformCurrencyExchangeOptions(_enCurrencyExchangeOptions(clsInputValidate::ReadNumberBetween(1, 5)));
    }
};
