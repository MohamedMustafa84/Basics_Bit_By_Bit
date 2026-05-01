 #pragma once

#include <iostream>
using namespace std;
#include "../../../Libs/ClsInputsValidate.h"
#include "../ClsBankClient.h"
#include "ClsScreen.h"


class clsUpdateClient :protected clsScreen {

    static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "Enter First Name : ";
        Client.SetFirstName(clsInputValidate::ReadString());
        cout << "\nEnter Last Name : ";
        Client.SetLastName(clsInputValidate::ReadString()) ;
        cout << "\nEnter Email : ";
        Client.SetEmail(clsInputValidate::ReadString()) ;
        cout << "\nEnter Phone : ";
        Client.SetPhone(clsInputValidate::ReadString()) ;
        cout << "\nEnter PIN Code : ";
        Client.SetPinCode(clsInputValidate::ReadString()) ;

        cout << "\nEnter Balance : ";
        Client.SetAccountBalance(clsInputValidate::ReadNumber<float>());
    }

    public:
        static void UpdateClient()
        {

            clsScreen::_DrawScreenHeader("Update Client Screen");

            cout << "Enter Account Number ? ";
            string AccountNumber = clsInputValidate::ReadString();

            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount Number is not fount ,Chose Another One : ";
                AccountNumber = clsInputValidate::ReadString();
            }
            cout << endl;
            clsBankClient Client = clsBankClient::Find(AccountNumber);
            Client.Print();

            cout << "\n\n\t\tUpdate Client Info \n";
            cout << "-------------------------------------------\n";
            _ReadClientInfo(Client);

            clsBankClient::enSaveResult SaveResult;

            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResult::svSucceeded:
                cout << "\nClient Updated Successfully :-)\n";
                Client.Print();
                break;
            case clsBankClient::enSaveResult::svFailEmptyObject:
                cout << "\nError Account Was Not Saved Because Its Empty :-(";
                break;
            
            }
        }

};
