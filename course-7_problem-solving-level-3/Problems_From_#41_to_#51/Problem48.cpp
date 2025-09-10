#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using  namespace std;

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

void printClientInfo(stClientData ClientInfo){
    cout << "| " << left << setw(15) << ClientInfo.AccountNumber << "| " << left << setw(10)
         << ClientInfo.PinCode << "| " << left << setw(40) << ClientInfo.FullName << "| " << left << setw(12)
         << ClientInfo.Phone << "| " << left << setw(12) << ClientInfo.AcountBalance << endl;
}


void showClientsData(){
    vector <stClientData>Clients_Info;

    Clients_Info = loadDataFromFileToVector();

    cout << "\n\t\t\t\tClients List (" << Clients_Info.size() << ") Client(s)\n";

    cout << "_______________________________________________________________________________________________\n";
    cout <<"| "<<left<< setw(15) << "Account Number" <<"| "<<left<< setw(10)
    << "Pin Code" <<"| "<<left<< setw(40) 
    << "Client Name" <<"| "<<left<< setw(12)
    << "Phone" <<"| "<<left<< setw(12)
    << "Balance" << endl;
    cout << "_______________________________________________________________________________________________\n";
    
    for(stClientData &ClientInfo :Clients_Info){
        printClientInfo(ClientInfo);
    }
    cout << "_______________________________________________________________________________________________\n";

}

    int main()
{

    // problem : write a program to read client data and show them  on the screen

    showClientsData();



    return 0;
}