#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string ClientsFilePath = "Clients.txt";

struct stClientData
{
    string AccountNumber = "";
    string PinCode = "";
    string FullName = "";
    string Phone = "";
    double AcountBalance = 0.00;
};


stClientData ReadNewClient()
{
    stClientData Client;
    cout << "Adding New Client :\n\n";

    cout << "Enter Account Number : ";
    getline(cin>>ws, Client.AccountNumber);
    cout << "\nEnter PinCode : ";
    getline(cin, Client.PinCode);

    cout << "\nEnter Your Full Name : ";
    getline(cin, Client.FullName);
    cout << "\nEnter Your Phone Number : ";
    getline(cin, Client.Phone);

    cout << "\nEnter Your Account Balance : ";
    cin >> Client.Phone;
    cout << endl;

    return Client;
}

string convertRecordToLine(stClientData Client, string Delim = "#//#")
{
    string ClientRecord = "";

    ClientRecord += Client.AccountNumber += Delim += Client.PinCode += Delim;
    ClientRecord += Client.FullName += Delim += Client.Phone += Delim;
    ClientRecord += Client.AcountBalance;

    return ClientRecord;
}

void SaveClientRecordToFile(){
    fstream ClientsFile;
    string NewClinet = convertRecordToLine(ReadNewClient(), "#//#");

    ClientsFile.open(ClientsFilePath, ios::out | ios::app);

    if(ClientsFile.is_open()){
        ClientsFile << NewClinet<<endl;
        ClientsFile.close();
    }

    cout << "Your Client data Added Successfully" << endl;
}
void addClients()
{

    char addMore = 'Y';
    do
    {
        SaveClientRecordToFile();

        cout << "Do You Want To Add More Client ? (Y/N) ";
        cin >> addMore;
        // system("cls");

    } while (toupper(addMore) == 'Y');
}

int main()
{

  

    // write a program to ask you to enter client  and  save them to file

    addClients();
    



    return 0;
}

