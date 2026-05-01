#pragma once

#include <iostream>
using namespace std;
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"
#include "../ClsBankUser.h"

class clsFindUser: protected clsScreen
{
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
    static void FindUser()
    {
        string UserName="";

        clsScreen::_DrawScreenHeader("Find User Screen");

        cout << "\nEnter User Name :\n";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nThis User Is Not Exist Please Retry : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
            _Print(User);
            return;
        }
        else
        {
            cout << "\nUser Was Not Found \n";
        }
    }
};
