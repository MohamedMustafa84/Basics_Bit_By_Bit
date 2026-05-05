#pragma once
#include <iostream>
#include "../../../Libs/ClsInputsValidate.h"
#include "../ClsBankClient.h"
#include "ClsScreen.h"
#include "../ClsGlobal.h"

class clsTransferScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client){
        cout << "\nClient Card :";
        cout << "\n------------------------------------------";
        cout << "\nFull Name       :" << Client.FullName();
        cout << "\nAccount Number  :" << Client.AccountNumber();
        cout << "\nBalance         :" << Client.AccountBalance();
        cout << "\n------------------------------------------\n";
    }

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber = "";
        cout << "\n"<<Message<<": ";
        cin >> AccountNumber;
        cout << "\n";

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With  Account Number (" << AccountNumber << ") Is Not Exist please retry ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;
        cout << "Enter Transfer Amount ? ";
        Amount = clsInputValidate::ReadNumber<float>();

        while (Amount > SourceClient.AccountBalance())
        {
            cout << "\nThe Amount Exceeds the available Balance ,Enter Another Amount :";
            Amount = clsInputValidate::ReadNumber<float>();
        }
        return Amount;
    }

   

public:

    static void  ShowTransferScreen()
    {
        clsScreen::_DrawScreenHeader("Transfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Enter Client Account Number You Want To Transfer From"));

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Enter Client Account Number You Want To Transfer To"));

        _PrintClient(DestinationClient);
        float Amount = _ReadAmount(SourceClient);
        char Answer = 'n';
        cout << "\nAre You Shower You Want to Preform This Operation? (Y/N)";
        cin >> Answer;

        if(toupper(Answer)){
            if (SourceClient.Transfer(Amount, DestinationClient)){
                cout<< "\nTransfer Done Successfully :-) \n";
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);
            }else{
                cout << "\nTransfer Failed :-(\n";
            }
        }else{
            cout<< "\nThe Operation Was Cancelled \n";
        }

        
    }
};
