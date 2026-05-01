#include <iostream>
#include <string>
#include <fstream>
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
};

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

vector<stClientData> loadDataFromFileToVector()
{
    vector<stClientData> vClients_Data;
    fstream MyFile;
    stClientData Client;

    MyFile.open(FilePath, ios::in); // read Mode

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

bool findClientByAccountNumber( string ClientAccountNumber,stClientData &client) 
{

    vector<stClientData> vClients_Data = loadDataFromFileToVector();

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




int main()
{
    
    // problem : write a program to find client by account number
    string clientAccountNumber;
    stClientData clientCard;
    cout
        << "Enter the Client account number you want to search for : ";
    cin >> clientAccountNumber;


        if (findClientByAccountNumber(clientAccountNumber,clientCard)){
            printClientCard(clientCard);
        }else{

            cout << "\nSorry they is no Client with the Account Number " << clientAccountNumber << " exist " << endl;
        }
    



    return 0;
    }