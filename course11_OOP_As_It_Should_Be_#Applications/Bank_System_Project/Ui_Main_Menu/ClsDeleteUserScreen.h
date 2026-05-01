#pragma once

#include <iostream>
using namespace std;
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"
#include "../ClsBankUser.h"

class clsDeleteUser :protected clsScreen
{
    static void _Print(clsUser User ){

    cout << "\n User Card ";
    cout << "\n-----------------------------------";
    cout << "\nFirst Name     : " << User.FirstName();
    cout << "\nLast Name      : " << User.LastName();
    cout << "\nUser Name      : " << User.UserName();
    cout << "\nEmail          : " << User.Email();
    cout << "\n Phone         : " << User.Phone();
    cout << "\n-----------------------------------\n";
            
}

    public : static void DeleteUser()
    {
        string UserName;

        clsScreen::_DrawScreenHeader("Delete User Screen");

        cout << "\nEnter User Name To Be Deleted : \n";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nThis User Name Is Not Exist Please Retry : ";
            UserName = clsInputValidate::ReadString();
        }

        if (UserName == "Admin")
        {
            cout << "\n you can not Delete this User\n";
            cout << "Please Contact Your Admin  \n";
            return;
        }

        clsUser User = clsUser::Find(UserName);

        _Print(User);

        cout << "\nAre You Shower You Want To Delete This User ? (Y/N) ";
        char Answer = 'N';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-) " << endl;
            }
            else
            {
                cout << "\nError User Was Not Deleted :-( " << endl;
            }
        }
        else
        {
            cout << "\nThe Operation Was canceled " << endl;
        }
    }
};
