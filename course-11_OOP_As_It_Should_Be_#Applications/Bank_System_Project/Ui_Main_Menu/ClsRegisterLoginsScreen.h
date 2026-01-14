#include <iostream>
#include "../ClsRegisterLogins.h"
#include "ClsScreen.h"
#include <iomanip>

using namespace std;

class clsRegisterLoginScreen : protected clsScreen
{
   


    static void _PrintUserLoginInfo(clsRegisterLogins::_stLoginInfo &LoginInfo)
    {
        cout << "| " << left << setw(35) << LoginInfo.DateAndTime;
        cout << "| " << left << setw(20) << LoginInfo.UserName;
        cout << "| " << left << setw(20) << LoginInfo.Password;
        cout << "| " << left << setw(15) << LoginInfo.Permission<<"\n";
    }

public:
    static void ShowLoginsList()
    {

        vector<clsRegisterLogins::_stLoginInfo> vUsersLoginsInfo;
        vUsersLoginsInfo = clsRegisterLogins::GetUsersLoginsData();

        string Title = "\t  List Screen ";

        clsScreen::_DrawScreenHeader("Users Logins Info Screen");

        cout << "______________________________________________________________________________________________________________\n";

        cout << "| " << left << setw(35) << "Date /Time";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(15) << "Permissions";
        cout << "\n______________________________________________________________________________________________________________\n";
        
        for (clsRegisterLogins::_stLoginInfo &LoginInfo : vUsersLoginsInfo)
        {
            _PrintUserLoginInfo(LoginInfo);
        }
        cout << "\n______________________________________________________________________________________________________________\n";
        
    }
};
