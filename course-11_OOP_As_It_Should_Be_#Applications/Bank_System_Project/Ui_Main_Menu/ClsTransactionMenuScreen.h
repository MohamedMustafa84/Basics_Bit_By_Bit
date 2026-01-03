#include <iostream>
#include <iomanip>
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"
#include "ClsTotalBalancesScreen.h"
#include "ClsDepositScreen.h"
#include "ClsWithDrawScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen
{
    enum _enTransactionMenuOptions
    {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalances = 3,
        eMainMenu = 4

    };

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }
    
    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen(); 
    }
    
    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalances::PrintTotalBalances();
    }
    
    static void _ShowMainMenuScreen()
    {
        // do nothing here the main screen will handle it 
    }

    static void _BackToTransactionMenu()
    {
        char Key;
        cout << setw(37) << left << "\nEnter Any Key to Back To Transaction Menu ...\n";
        cin >> Key;
        // system("pause>0");
        ShowTransactionScreen();
    }

    static void _PerformTransactionOptions(_enTransactionMenuOptions Choice)
    {

        switch (Choice)
        {
        case _enTransactionMenuOptions::eDeposit:
            _ShowDepositScreen();
            _BackToTransactionMenu();
            
            break;
        case _enTransactionMenuOptions::eWithdraw:
            _ShowWithdrawScreen();
            _BackToTransactionMenu();

            break;

        case _enTransactionMenuOptions::eTotalBalances:

            _ShowTotalBalancesScreen();
            _BackToTransactionMenu();
            break;

        case _enTransactionMenuOptions::eMainMenu:
            _ShowMainMenuScreen();
            break;
        
        }
    }

public:
    static void ShowTransactionScreen()
    {

        _DrawScreenHeader("Transaction Screen");

        cout << setw(37) << left << "" << "================================================\n";
        cout << setw(37) << left << "" << "\t\t\t Transaction Screen \n";
        cout << setw(37) << left << "" << "================================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit \n";
        cout << setw(37) << left << "" << "\t[2] Withdraw\n";
        cout << setw(37) << left << "" << "\t[3] TotalBalances \n";
        cout << setw(37) << left << "" << "\t[4] Main Menu \n";

        cout << setw(37) << left << "" << "================================================\n";

        cout << setw(37) << left << "" << "\tChose What To Do From 1 to 4? ";
        _PerformTransactionOptions(_enTransactionMenuOptions(clsInputValidate::ReadNumberBetween(1, 4)));
    }
};
