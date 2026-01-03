#pragma once
#include <iostream>
#include "../../../Libs/ClsInputsValidate.h"
#include "../ClsBankClient.h"
#include "ClsScreen.h"

class clsWithdrawScreen : protected clsScreen
{

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nEnter Account Number :";
        cin >> AccountNumber;
        cout << "\n";
        return AccountNumber;
    }

public:
    static bool ShowWithdrawScreen()
    {
        clsScreen::_DrawScreenHeader("WithDraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client With  Account Number (" << AccountNumber << ") Is Not Exist";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        Client.Print();

        float Amount = 0.0f;
        cout << "\nEnter Withdraw Amount : ";
        Amount = clsInputValidate::ReadNumber<float>();
        
        char Answer = 'n';
        cout << "Are You Shower You Want To Preform this transaction?(Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            
            while (!Client.Withdraw(Amount)){
                cout << "\nAmount Exceed the balance (" << Client.AccountBalance()<< ")Please retry :\n ";
                Amount = clsInputValidate::ReadNumber<float>();
            }
            cout << "\nthe Operation Done Successfully :-)";
            cout << "\n New Balance is " << Client.AccountBalance() << endl;

            return true;
        }
        cout << "\nThe Operation Was Cancelled\n ";
        return false;
    }
};
