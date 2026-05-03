#pragma once 

#include <iostream>
#include "../ClsBankClient.h"
#include "../../../Libs/ClsInputsValidate.h"
using namespace std;
 


class clsAddNewClientScreen
{
    static void ReadClientInfo(clsBankClient &Client)
    {
        cout << "Enter First Name : ";
        Client.SetFirstName(clsInputValidate::ReadString());
        cout << "\nEnter Last Name : ";
        Client.SetLastName( clsInputValidate::ReadString()) ;
        cout << "\nEnter Email : ";
        Client.SetEmail( clsInputValidate::ReadString()) ;
        cout << "\nEnter Phone : ";
        Client.SetPhone( clsInputValidate::ReadString()) ;
        cout << "\nEnter PIN Code : ";
        Client.SetPinCode( clsInputValidate::ReadString()) ;

        cout << "\nEnter Balance : ";
        Client.SetAccountBalance(clsInputValidate::ReadNumber<float>());
    }

    public:

    
static void AddNewClient(){
    string AccountNumber;
    cout <<"Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();
    
    while(clsBankClient::IsClientExist(AccountNumber)){
        cout << "\nAccount Number Is Already Exist ,Chose Another One : ";
        AccountNumber = clsInputValidate::ReadString();

    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);



    clsBankClient::enSaveResult SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult){
        case clsBankClient::enSaveResult::svSucceeded:

            cout << "\nAccount Added Successfully :-)\n";
            NewClient.Print();
            break;
        case clsBankClient::enSaveResult::svFailEmptyObject:
            cout << "\nError Account Was Not Saved Because Its Empty" << endl;
            break;
        case clsBankClient::enSaveResult::svFailAccountNumberExists:
            cout << "\nError Account Number Already Used , Chose Another One " << endl;
            break;
    }
}



};








