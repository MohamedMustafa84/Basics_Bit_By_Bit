#pragma once
#include "Ui_Main_Menu/ClsMainScreen.h"
#include "Ui_Main_Menu/ClsScreen.h" 
#include "ClsRegisterLogins.h"

#include "ClsGlobal.h"


class clsLoginScreen :protected clsScreen{

    static bool _Login(){
        bool LoginFiled = false;
        string UserName = "", Password = "";
        short LoginTrials = 3;

        do{
            

            cout << "\nEnter UserName : ";
            cin >> UserName;
            cout << "\nEnter Password : ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);
            LoginFiled = CurrentUser.IsEmpty();

             
            if(LoginFiled){
                LoginTrials--;
                cout << "\nInvalid UserName/Password:\n";
                cout << "You Have " << LoginTrials << " Trail(s) To Login \n";

                
            }

            if (LoginTrials == 0)
            {
                cout << "\nYou Are Locked After " << 3 - LoginTrials << " Failed Trails :-(\n ";
                cout << "Please Contact Your Admin \n";
                return false;
            }

        } while (LoginFiled && LoginTrials >= 0);

        clsRegisterLogins::RegisterUserLoginInfo();

        clsMainScreen::ShowMainMenuScreen();
        return true;
    }

    public :
         static bool  ShowLoginScreen(){

             _DrawScreenHeader("Login Screen");
             return _Login();
         }
};