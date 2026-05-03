#pragma once

#include <iostream>
#include "../ClsBankUser.h"
#include "../../../Libs/ClsInputsValidate.h"
using namespace std;

class clsAddNewUserScreen
{
    static void _ReadUserInfo(clsUser &User)
    {
        cout << "Enter First Name : ";
        User.SetFirstName(clsInputValidate::ReadString());
        cout << "\nEnter Last Name : ";
        User.SetLastName(clsInputValidate::ReadString());
        cout << "\nEnter Email : ";
        User.SetEmail(clsInputValidate::ReadString());
        cout << "\nEnter Phone : ";
        User.SetPhone(clsInputValidate::ReadString());
        cout << "\nEnter Password : ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permission : ";
        User.SetPermissions(_ReadPermissionToSet());
    }

    static int _ReadPermissionToSet(){
        int Permissions =0;
        char Answer;

        cout << "\nDo You Want Full Access ? (Y/N) ";
        cin >> Answer;

        if(toupper(Answer)== 'Y'){
            return -1;
        }

        cout << "\nDo You Want This User To Access :\n";
        cout << "Show Clients List ? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "Add New Clients ? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "Delete Client? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "Update Client? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "Find Clients? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "Transaction ? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransaction;
        }

        cout << "Mange Users ? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "Register Login ? (Y/N)";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pRegisterLogin;
        }

        return Permissions;
    }

    static void _Print(clsUser &User)
    {
        cout << "\n User Card ";
        cout << "\n-----------------------------------";
        cout << "\nFull Name      : " << User.FullName();
        cout << "\nUser Name      : " << User.UserName();
        cout << "\nEmail          : " << User.Email();
        cout << "\n Phone         : " << User.Phone();
        cout << "\nPassword       : " << User.Password();
        cout << "\n Permissions   : " << User.Permissions();
        cout << "\n-----------------------------------\n";
    }

    public:
    static void AddNewUser()
    {
        string UserName;
        cout << "Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nThis User Name Is Already Exist ,Chose Another One : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResult SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResult::svSucceeded:

            cout << "\nUser Added Successfully :-)\n";
            _Print(NewUser);
            break;
        case clsUser::enSaveResult::svFailEmptyObject:
            cout << "\nError User Was Not Saved Because Its Empty" << endl;
            break;
        case clsUser::enSaveResult::svFailAccountNumberExists:
            cout << "\nError User Already Used , Chose Another One " << endl;
            break;
        }
    }
};
