#pragma once

#include <iostream>
using namespace std;
#include "../../../Libs/ClsInputsValidate.h"
#include "../ClsBankUser.h"
#include "ClsScreen.h"

class clsUpdateUser : protected clsScreen
{

    static void _ReadUserInfo(clsUser& User)
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

    static int _ReadPermissionToSet()
    {
        int Permissions = 0;
        char Answer;

        cout << "\nDo You Want Full Access ? (Y/N) ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
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
    static void UpdateUser()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pUpdateClient))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("Update User Screen");
        string UserName= "";
        cout
            << "Enter User Name ? ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nthis User is not fount ,Chose Another One : ";
            UserName = clsInputValidate::ReadString();
        }
        cout << endl;

        if(UserName == "Admin"){
            cout << "You Can not Update this User \n";
            cout << "Please Contact Your Admin \n";
            return;
        }
        clsUser User = clsUser::Find(UserName);
        _Print(User);

        char Answer = 'N';
        cout <<"\nAre Your Shower You Want To Update This User ?(Y/N) ";
        cin >> Answer;
        
        if (toupper(Answer)!='Y'){
            return;
        }

        cout << "\n\n\t\tUpdate User Info \n";
        cout << "-------------------------------------------\n";
        _ReadUserInfo(User);

        clsUser::enSaveResult SaveResult;

        SaveResult = User.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResult::svSucceeded:
            cout << "\nUser Updated Successfully :-)\n";
            _Print(User);
            break;
        case clsUser::enSaveResult::svFailEmptyObject:
            cout << "\nError User Was Not Updated Because Its Empty :-(";
            break;
        }
    }
};
