#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>
#include "../../../Libs/ClsUtil.h"
#include "ClsScreen.h"
#include "../ClsBankClient.h"



class clsTotalBalances :protected clsScreen{

    static void _PrintClientBalanceRow(clsBankClient Client)
    {

        cout << "|" << left << setw(15) << Client.AccountNumber();
        cout << "|" << left << setw(25) << Client.FullName();
        cout << "|" << left << setw(15) << to_string(Client.AccountBalance()) << endl;
    }

       public :

        static void PrintTotalBalances()
        {
            vector<clsBankClient> vClients;
            vClients = clsBankClient::GetClientsList();

            float TotalBalance;

            int ClientsNumber = vClients.size();

            string Title = "Balances List ";
            string SubTitle = "(" + to_string(ClientsNumber) +")Clients";

            clsScreen::_DrawScreenHeader(Title, SubTitle);

            cout << "_______________________________________________________________________________\n";

            cout << "|" << left << setw(15) << "Account Number";
            cout << "|" << left << setw(25) << "Client Name ";
            cout << "|" << left << setw(15) << "Balance" << endl;
            cout << "_______________________________________________________________________________\n";

            if (vClients.size() == 0)
            {
                cout << "\n\n\t\t\tNo Clients Available in The System !";
            }
            else
            {

                for (clsBankClient &Client : vClients)
                {
                    _PrintClientBalanceRow(Client);
                }
            }
            cout << "_______________________________________________________________________________\n";

            TotalBalance = clsBankClient::GetTotalBalance();
            cout << "\n\t\t\t Total Balance : " << TotalBalance << endl;
            cout << "\n\t\t\t" << clsUtil::ConvertNumberToText(TotalBalance) << endl;
        }
};