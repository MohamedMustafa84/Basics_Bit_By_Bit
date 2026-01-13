#pragma once
#include "Ui_Main_Menu/ClsMainScreen.h"
#include "Ui_Main_Menu/ClsScreen.h"

#include "ClsGlobal.h"


class clsLoginScreen :protected clsScreen{

    static void _Login(){
        bool LoginFiled = false;
        string UserName = "", Password = "";

        do{
            if(LoginFiled){
                cout << "\nInvalid UserName/Password:\n";
            }

            cout << "\nEnter UserName : ";
            cin >> UserName;
            cout << "\nEnter Password : ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);
            LoginFiled = CurrentUser.IsEmpty();
        } while (LoginFiled);

        clsMainScreen::ShowMainMenuScreen();
    }

    public :
         static void  ShowLoginScreen(){

             _DrawScreenHeader("Login Screen");
             _Login();
         }
};