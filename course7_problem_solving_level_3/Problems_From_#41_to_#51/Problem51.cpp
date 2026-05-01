#include <iostream>
#include <string>
#include <fstream>
#include "../MyLib.h"
#include <iomanip>
#include <vector>
using namespace std;

string FilePath = "Clients.txt";

struct stClientData
{
    string AccountNumber = "";
    string PinCode = "";
    string FullName = "";
    string Phone = "";
    double AcountBalance = 0.00;
    bool markforDelete = false;
};

stClientData changeClientData(string AccountNumber)
{
    stClientData Client;

    Client.AccountNumber = AccountNumber;

    cout << "\nEnter PinCode : ";
    getline(cin >> ws, Client.PinCode);

    cout << "\nEnter Full Name : ";
    getline(cin, Client.FullName);
    cout << "\nEnter Phone Number : ";
    getline(cin, Client.Phone);

    cout << "\nEnter Account Balance : ";
    cin >> Client.Phone;
    cout << endl;

    return Client;
}

vector<string> splitString(string Str, string delim)
{
    vector<string> vString;

    int position = 0;
    string Word = "";

    while ((position = Str.find(delim)) != string::npos)
    {
        Word = Str.substr(0, position);

        if (Word != "")
        {
            vString.push_back(Word);
        }
        Str.erase(0, position + delim.length());
    }
    if (Str != "")
    {
        vString.push_back(Str);
    }

    return vString;
}

stClientData convertLineToRecord(string lineRecord, string Delim)
{
    stClientData clientData;

    vector<string> vString = splitString(lineRecord, Delim);

    if (vString.size() < 5)
        return clientData;

    clientData.AccountNumber = vString[0];
    clientData.PinCode = vString[1];
    clientData.FullName = vString[2];
    clientData.Phone = vString[3];
    clientData.AcountBalance = stod(vString[4]);

    return clientData;
}

string convertRecordToLine(stClientData Client, string Delim = "#//#")
{
    string ClientRecord = "";

    ClientRecord += Client.AccountNumber += Delim += Client.PinCode += Delim;
    ClientRecord += Client.FullName += Delim += Client.Phone += Delim;
    ClientRecord += Client.AcountBalance;

    return ClientRecord;
}

vector<stClientData> loadDataFromFileToVector()
{
    vector<stClientData> vClients_Data;
    fstream MyFile;
    stClientData Client;

    MyFile.open(FilePath, ios::in);

    if (MyFile.is_open())
    {
        string line;

        while (getline(MyFile, line))
        {
            Client = convertLineToRecord(line, "#//#");
            vClients_Data.push_back(Client);
        }
        MyFile.close();
    }

    return vClients_Data;
}

void printClientCard(stClientData client)
{
    cout << "\n_______________________ Client Info __________________________________\n";
    cout << "Account Number : " << client.AccountNumber;
    cout << "\nPin Code : " << client.PinCode;
    cout << "\nFullName : " << client.FullName;
    cout << "\nPhone : " << client.Phone;
    cout << "\nAccount Balance : " << client.AcountBalance;
    cout << "\n_______________________________________________________________________" << endl;
}

bool isClientExist(vector<stClientData> vClients_Data, string ClientAccountNumber, stClientData &client)
{

    for (stClientData &clientInfo : vClients_Data)
    {
        if (clientInfo.AccountNumber == ClientAccountNumber)
        {
            client = clientInfo;
            return true;
        }
    }
    return false;
}



vector<stClientData> save_Clients_Data_To_File(vector<stClientData> vClients_Data)
{
    fstream Clients_File;
    Clients_File.open(FilePath, ios::out);
    if (Clients_File.is_open())
    {

        for (stClientData &Client_info : vClients_Data)
        {
            if (Client_info.markforDelete == false)
            {
                Clients_File << convertRecordToLine(Client_info, "#//#") << endl;
            }
        }

        Clients_File.close();
    }
    return vClients_Data;
}



bool UpdateClientData(vector<stClientData> &vClients_Data, string clientAccountNumber)
{
    stClientData clientCard;
    
    char UpdateAccount = 'Y';
    
    if (isClientExist(vClients_Data, clientAccountNumber, clientCard))
    {
        printClientCard(clientCard);
        cout << "\nare you sure you want to Update this Account ?(Y/N) ";
        cin >> UpdateAccount;
        if (toupper(UpdateAccount) == 'Y')
        {
            for(stClientData &OldClient :vClients_Data){
                if(OldClient.AccountNumber ==clientAccountNumber){
                    OldClient = changeClientData(clientAccountNumber);
                    break;
                }

            }

            save_Clients_Data_To_File(vClients_Data);
            cout << "the Account Updated successfully :)" << endl;
            
            return true;
        }
        else
        {
            cout << "the Account Updating is canceled :)" << endl;
            return false;
        }
    }

    cout << "\nClient With The Account Number " << clientAccountNumber << " Is Not Found :(" << endl;

    return false;
}

int main()
{

    // problem : write a program to Update  client informations  

    vector<stClientData> vClients_Data = loadDataFromFileToVector();

    string clientAccountNumber = UserInputs::ReadString("Enter the Client account number you want to Update : ");

    UpdateClientData(vClients_Data, clientAccountNumber);

    return 0;
}