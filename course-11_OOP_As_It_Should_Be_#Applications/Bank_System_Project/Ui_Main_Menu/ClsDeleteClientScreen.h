#pragma once

#include <iostream>
using namespace std;
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"
#include "../ClsBankClient.h"

class clsDeleteClient :protected clsScreen
{
    public :
    static void DeleteClient(){
    string AccountNumber;

   
    clsScreen::_DrawScreenHeader("Delete Client Screen");

    cout << "\nEnter Client Account Number\n";
    AccountNumber = clsInputValidate::ReadString();
    
    while(!clsBankClient::IsClientExist(AccountNumber)){
        cout << "\nThis Account Number Is Not Exist Please Retry : ";
        AccountNumber = clsInputValidate::ReadString();

    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);

    Client.Print();

    cout << "\nAre You Shower You Want To Delete This Account ? (Y/N) ";
    char Answer = 'N';
    cin >> Answer;

    if(toupper(Answer)=='Y'){

        if(Client.Delete()){
            cout << "\nClient Deleted Successfully :-) " << endl;
        }else{
            cout << "\nError Client Was Not Deleted :-( "<<endl;
        }
        
    }else {
        cout << "\nThe Operation Was canceled " << endl;
    }
}
};
