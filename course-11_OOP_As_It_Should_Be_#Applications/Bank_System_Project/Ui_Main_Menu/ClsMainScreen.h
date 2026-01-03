#include <iostream>
#include <iomanip>
#include "../../../Libs/ClsInputsValidate.h"
#include "ClsScreen.h"
#include "ClsClientsListScreen.h"
#include "ClsAddNewClientScreen.h"
#include "ClsDeleteClientScreen.h"
#include "ClsUpdateClientScreen.h"
#include "ClsFindClientScreen.h"
#include "ClsTransactionMenuScreen.h"
using namespace std;



class clsMainScreen :protected clsScreen{
    enum _enMainMenuOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionMenu=6,
        eMangeUsers=7,
        eExit = 8

    };


    static void _ShowAllClientsScreen(){
        clsClientsList::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientsScreen()
    {
        clsDeleteClient::DeleteClient();
    }

    static void _ShowUpdateClientsScreen()
    {
        clsUpdateClient::UpdateClient();
    }

    static void _ShowFindClientsScreen()
    {
        clsFindClient::FindClient();
    }

    static void _ShowTransactionMenuScreen()
    {
        clsTransactionScreen::ShowTransactionScreen();
    }

   

    static void _ShowMangeUsersScreen()
    {
        cout << "Mange Users Screen Will Be Here" << endl;
    }

    static void _ShowEndScreen()
    {
        cout << "End Screen Will Be Here" << endl;
    }

    static void _BackToMainMenu()
    {
        char Key;
        cout << setw(37) << left << "\nEnter Any Key to Back To Main Menu ...\n";
        cin>>Key;
        // system("pause>0");
        ShowMainMenuScreen();
    }

    static void _PreformMainMenuOptions(_enMainMenuOptions Choice)
    {

        switch (Choice)
        {
        case _enMainMenuOptions::eListClients:
            _ShowAllClientsScreen();
            _BackToMainMenu();

            break;
        case _enMainMenuOptions::eAddNewClient:
            _ShowAddNewClientsScreen();
            _BackToMainMenu();

            break;

        case _enMainMenuOptions::eDeleteClient:
            _ShowDeleteClientsScreen();
            _BackToMainMenu();
            break;

        case _enMainMenuOptions::eFindClient:
            _ShowFindClientsScreen();
            _BackToMainMenu();
            break;
        case _enMainMenuOptions::eMangeUsers:
            _ShowMangeUsersScreen();
            _BackToMainMenu();
            break;
        case _enMainMenuOptions::eShowTransactionMenu:
            _ShowTransactionMenuScreen();
            _BackToMainMenu();
            break;
        case _enMainMenuOptions::eUpdateClient:
            _ShowUpdateClientsScreen();
            _BackToMainMenu();
            break;
        case _enMainMenuOptions::eExit:
            _ShowEndScreen();
            break;
        }
    }

    

     public: 
         static void ShowMainMenuScreen()
         {

             _DrawScreenHeader("Main Screen");

             cout << setw(37) << left << "" << "================================================\n";
             cout << setw(37) << left << "" << "\t\t\t Main Screen \n";
             cout << setw(37) << left << "" << "================================================\n";
             cout << setw(37) << left << "" << "\t[1] Show Clients List \n";
             cout <<setw(37)<<left<<""<< "\t[2] Add New Client\n";
             cout <<setw(37)<<left<<""<< "\t[3] Delete Client \n";
             cout <<setw(37)<<left<<""<< "\t[4] Update Client Info \n";
             cout <<setw(37)<<left<<""<< "\t[5] Find Client \n";
             cout <<setw(37)<<left<<""<< "\t[6] Transaction Menu\n";
             cout <<setw(37)<<left<<""<< "\t[7] Mange Users \n";
             cout <<setw(37)<<left<<""<< "\t[8] Logout \n";
             cout << setw(37) << left << "" << "================================================\n";

             cout << setw(37) << left << ""<<"\tChose What To Do From 1 to 8? ";
             _PreformMainMenuOptions(_enMainMenuOptions(clsInputValidate::ReadNumberBetween(1,8)));
         }
     };
