#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData {
    string AccountNumber="";
    string PinCode="";
    string FullName = "";
    string Phone = "";
    double AcountBalance = 0.00;
};

stClientData ReadNewClient(){
    stClientData Client;
    cout << "Please Enter Client Data :\n\n";

    cout << "Enter Account Number : ";
    getline(cin, Client.AccountNumber);
    cout<<"\nEnter PinCode : ";
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

string convertRecordToLine(stClientData Client,string Delim= "#//#"){
    string ClientRecord ="";

    ClientRecord += Client.AccountNumber += Delim += Client.PinCode += Delim;
    ClientRecord += Client.FullName += Delim += Client.Phone += Delim;
    ClientRecord += Client.AcountBalance;

    return ClientRecord;
}

    int main()
{

    // write a program to read bank client data record and convert it to one line

    stClientData Client = ReadNewClient();

    cout << "Client Record For Saving Is :\n";
    cout << convertRecordToLine(Client,"#//#");

    return 0;
}