#pragma once
#include <iostream>
#include "../ClsGlobal.h"
#include "../ClsBankUser.h"
#include "../../../Libs/ClsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n\n\n\t\t\t\t--------------------------------------------";
        cout << "\n\t\t\t\t\t" << Title;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t" << SubTitle;
        }
        cout << "\n\t\t\t\t--------------------------------------------\n";

        cout << "\t\t\t\t User:" << CurrentUser.UserName();
        cout << "\n\t\t\t\t Date : " << clsDate::DateToString(clsDate::GetSystemDate())<<"\n\n";
    }

    static bool CheckAccessRight(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\n\t\t\t\t\t-------------------------------------------------------\n";
            cout << "\n\t\t\t\t\t Access Denied! Contact Your Admin ";
            cout << "\n\t\t\t\t\t-------------------------------------------------------\n";
            return false;
        }
        return true;
    }
};