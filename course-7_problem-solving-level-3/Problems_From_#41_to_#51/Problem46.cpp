#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

    vector vString = splitString(lineRecord, Delim);

    clientData.AccountNumber = vString[0];
    clientData.PinCode = vString[1];
    clientData.FullName = vString[2];
    clientData.Phone= vString[3];
    clientData.AcountBalance= stod(vString[4]);

    return clientData;
}
void printClientData(stClientData Client){

    cout << "\nAccount Number : "<<Client.AccountNumber;
    cout << "\nPinCode : "<<Client.PinCode;

    cout << "\nFull Name : "<< Client.FullName;
    cout << "\nPhone Number : "<< Client.Phone;

    cout << "\nAccount Balance : "<<Client.Phone;
    cout << endl;
}


int main()
{

    // write a program to Convert line data to record and print it 

    string lineRecord = "A1150#//#1234#//#Mohamed mustafa#//#092433994#//#2348.0000";

    cout << "the following is the extracted client record :\n";

    printClientData(convertLineToRecord(lineRecord, "#//#"));


    return 0;
}