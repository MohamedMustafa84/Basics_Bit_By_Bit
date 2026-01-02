#include <iostream>
#include "../ClsBankClient.h"
#include "ClsScreen.h"
#include <iomanip>

using namespace std;

class clsClientsList : protected clsScreen
{
private:
    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(15) << Client.Phone();
        cout << "| " << left << setw(25) << Client.Email();
        cout << "| " << left << setw(20) << Client.PinCode();
        cout << "| " << left << setw(20) << to_string(Client.AccountBalance()) << endl;
    }

public:
    static void ShowClientsList()
    {

        vector<clsBankClient> vClients;
        vClients = clsBankClient::GetClientsList();

        int ClientsNumber = vClients.size();

        string Title = "\t Client List Screen ";
        string SubTitle = "\t (" + to_string(ClientsNumber) + ") Client(s)";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << "\n___________________________________________________________________________________________________________________\n";

        cout << "| " << left << setw(15) << "AccountNumber";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(20) << "PIN Code";
        cout << "| " << left << setw(20) << "Balance";
        cout << "\n___________________________________________________________________________________________________________________\n";

        if (ClientsNumber == 0)
        {
            cout << "\n\n\t\t\tNo Clients Available in The System !";
        }
        else
        {
            for (clsBankClient &Client : vClients)
            {
                PrintClientRecordLine(Client);
            }
        }
        cout << "\n___________________________________________________________________________________________________________________\n";
    }
};
