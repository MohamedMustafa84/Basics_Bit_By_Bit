#pragma once

#include <iostream>
using namespace std;
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"
#include "../ClsBankClient.h"

class clsFindClient : protected clsScreen
{
public:
    static void FindClient()
    {
        string AccountNumber;

        clsScreen::_DrawScreenHeader("Find Client Screen");

        cout << "\nEnter Client Account Number\n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nThis Account Number Is Not Exist Please Retry : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if(!Client.IsEmpty()){
            cout <<"\nClient Found :-)\n";
            Client.Print();
            return;
        }else{
            cout << "\nClient Was Not Found \n";
        }
    }
};
