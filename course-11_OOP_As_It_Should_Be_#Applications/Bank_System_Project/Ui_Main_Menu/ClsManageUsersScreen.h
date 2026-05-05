#include <iostream>
#include <iomanip>
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"
#include "ClsUsersListScreen.h"
#include "ClsAddNewUserScreen.h"
#include "ClsDeleteUserScreen.h"
#include "ClsUpdateUserScreen.h"
#include "ClsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
    enum _enManageUsersOptions
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6

    };

    static void _ShowAllUsersScreen()
    {
        clsUsersList::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::AddNewUser();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUser::DeleteUser();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUser::UpdateUser();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUser::FindUser();
    }

    static void _ShowMainMenuScreen()
    {
        // do nothing here the main screen will handle it 
    }

    static void _BackToManageUsersMenu()
    {
        char Key;
        cout << setw(37) << left << "\nEnter Any Key to Back To Manage Users Menu ...\n";
        cin >> Key;
        // system("pause>0");
        ShowManageUsersScreen();
    }

    static void _PreformManageUsersOptions(_enManageUsersOptions Choice)
    {

        switch (Choice)
        {
        case _enManageUsersOptions::eListUsers:
            _ShowAllUsersScreen();
            _BackToManageUsersMenu();

            break;
        case _enManageUsersOptions::eAddNewUser:
            _ShowAddNewUserScreen();
            _BackToManageUsersMenu();

            break;

        case _enManageUsersOptions::eDeleteUser:
            _ShowDeleteUserScreen();
            _BackToManageUsersMenu();
            break;

        case _enManageUsersOptions::eFindUser:
            _ShowFindUserScreen();
            _BackToManageUsersMenu();
            break;
        
        case _enManageUsersOptions::eUpdateUser:
            _ShowUpdateUserScreen();
            _BackToManageUsersMenu();
            break;
        case _enManageUsersOptions::eMainMenu:
            _ShowMainMenuScreen();
            break;
        
        }
    }

public:
    static void ShowManageUsersScreen()
    {

        _DrawScreenHeader("Manage Users Screen");

        cout << setw(37) << left << "" << "================================================\n";
        cout << setw(37) << left << "" << "\t\t\t Manage Users Screen \n";
        cout << setw(37) << left << "" << "================================================\n";
        cout << setw(37) << left << "" << "\t[1] Users List \n";
        cout << setw(37) << left << "" << "\t[2] Add New User\n";
        cout << setw(37) << left << "" << "\t[3] Delete User \n";
        cout << setw(37) << left << "" << "\t[4] Update User \n";
        cout << setw(37) << left << "" << "\t[5] Find User\n";
        cout << setw(37) << left << "" << "\t[6] MainMenu\n";
        cout << setw(37) << left << "" << "================================================\n";

        cout << setw(37) << left << "" << "\tChose What To Do From 1 to 6? ";
        _PreformManageUsersOptions(_enManageUsersOptions(clsInputValidate::ReadNumberBetween(1, 6)));
    }
};
