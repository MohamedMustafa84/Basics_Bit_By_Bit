#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../MyLib.h"
using namespace std;




struct stClientData
{
    string AccountNumber = "";
    string FullName = "";
    string Phone = "";
    string PinCode = "";
    bool markForDelete = false;
    double AccountBalance = 0.00;
};

enum enATMMainMenu
{
    QuickWithDraw = 1,
    NormalWithdraw = 2,
    Deposit = 3,
    CheckBalance = 4,
    Logout = 5
};

const string ClientsFilePath = "Clients.txt";


stClientData CurrentClient;
vector<stClientData> vClientsData;


int readClientChoice(short min, short max)
{
    return UserInputs::ReadNumberInRange("Choose What Do You Want To Do ? ", min, max);
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

string convertRecordToLine(stClientData Client, string Delim = "#//#")
{
   
    return Client.AccountNumber + Delim + Client.PinCode + Delim + Client.FullName + Delim + Client.Phone + Delim + to_string(Client.AccountBalance);
}

stClientData convertLineToRecord(string lineRecord, string Delim = "#//#")
{
    stClientData clientData;

    vector<string> vString = splitString(lineRecord, Delim);

    if (vString.size() < 5)
        return clientData;

    clientData.AccountNumber = vString[0];
    clientData.PinCode = vString[1];
    clientData.FullName = vString[2];
    clientData.Phone = vString[3];
    clientData.AccountBalance = stod(vString[4]);

    return clientData;
}

vector<stClientData> loadDataFromFileToVector(string FilePath)
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


bool findClientByAccountNumberAndPINCode(string clientAccountNumber, string PINCode)
{

    for (stClientData &C : vClientsData)
    {
        if (C.AccountNumber == clientAccountNumber && C.PinCode == PINCode)
        {

            CurrentClient = C;
            return true;
        }
    }
    return false;
}


vector<stClientData> save_Clients_Data_To_File(vector<stClientData> vClients_Data,string FilePath)
{
    fstream Clients_File;
    Clients_File.open(FilePath, ios::out);
    if (Clients_File.is_open())
    {

        for (stClientData &Client_info : vClients_Data)
        {
            if (Client_info.markForDelete== false)
            {
                Clients_File << convertRecordToLine(Client_info, "#//#") << endl;
            }
        }

        Clients_File.close();
    }
    return vClients_Data;
}

bool ShowATMMainMenuScreen();
void Login();


void back_To_ATM_Main_Menu()
{
    char backToATM;
    
    cout << "\n\nEnter Any Letter To Back To ATM Main Menu ...\n";
    cin >> backToATM;
    ShowATMMainMenuScreen();
}

bool ApplyAccountAmountChange( string AccountNumber, double DepositAmount)
{
    char Answer = 'Y';
    cout << "Are You Sure You Want to perform this transaction ?(Y/N) ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
    {

        for (stClientData &Client : vClientsData)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                Client.AccountBalance += DepositAmount;
                cout << "Done Successfully The New Balance is " << Client.AccountBalance << endl;
                CurrentClient = Client;
                save_Clients_Data_To_File(vClientsData, ClientsFilePath);
                vClientsData = loadDataFromFileToVector(ClientsFilePath);
                return true;
            }
        }
    }

    cout << "the transaction was canceled  ";
    return false;
}

double ReadDepositAmount(){

    double DepositAmount;
    do
    {
        cout << "Please Enter the Amount ? ";
        cin >> DepositAmount;
    } while (DepositAmount <= 0);
    return DepositAmount;
}

bool preformDeposit()
{

    double DepositAmount = ReadDepositAmount();

    ApplyAccountAmountChange(CurrentClient.AccountNumber, DepositAmount);
    return true;
}

void showDepositScreen()
{

    cout << "=======================================================\n";
    cout << "\t\t Deposit Menu Screen \n";
    cout << "=======================================================\n";

    preformDeposit();
}

double validateWithdrawAmountInBalanceRange(double WithdrawAmount,double ClientBalance)
{
    WithdrawAmount = abs(WithdrawAmount);

    while (WithdrawAmount > ClientBalance)
    {
        cout << "Amount Exceed The Balance You Cannot Withdraw Up To :" << ClientBalance << endl;
        cout << "please Enter Another Amount ?";
        cin >> WithdrawAmount; 
    }
    return WithdrawAmount;
}

bool preformQuickWithDraw(stClientData &stClientData, double WithdrawAmount)
{

    WithdrawAmount = validateWithdrawAmountInBalanceRange(WithdrawAmount, stClientData.AccountBalance);

    ApplyAccountAmountChange(stClientData.AccountNumber, WithdrawAmount * -1);
    return true;
}



double ReadWithdrawAmount(){

    double WithdrawAmount = 0.0000;
    do
    {
        cout << "Enter An Amount Multiple Of 5,s ?";
        cin >> WithdrawAmount;

    } while ((int)WithdrawAmount % 5 != 0);
    return WithdrawAmount;
}

bool preformNormalWithdraw(stClientData &stClientData)
{
    
    double WithdrawAmount = ReadWithdrawAmount();

    WithdrawAmount = validateWithdrawAmountInBalanceRange(WithdrawAmount,stClientData.AccountBalance);

    ApplyAccountAmountChange(stClientData.AccountNumber, WithdrawAmount * -1);

    return true;
}



void showNormalWithdrawScreen()
{

    cout << "============================================================\n";
    cout << "\t\t Withdraw Menu Screen \n";
    cout << "============================================================\n";

    preformNormalWithdraw(CurrentClient);
}



void showCheckBalanceScreen(){

    cout << "\n============================================================\n";
    cout << "\t\t\t\t Check Balance Screen";
    cout << "\n============================================================\n";
    cout << "Your Balance is :" << CurrentClient.AccountBalance << endl;
    
}




short  GetQuickWithdrawAmount(short choice){
    switch (choice)
    {
        case 1:
            return 20;
        case 2:
            return 40;
        case 3:
            return 100;
        case 4:
            return 200;
        case 5:
            return 400;
        case 6:
            return 600;
        case 7:
            return 800;
        case 8:
            return 1000;
        case 9:
            Login();
            return 0;
    
    }
    return 0;
}


void showQuickWithdrawScreen(){
    cout << "\n============================================================\n";
    cout << "\t\t Quick Withdraw Screen";
    cout << "\n============================================================\n";
    cout << "\t\t[1]20\t\t\t[2]50\n";
    cout << "\t\t[3]100\t\t\t[4]200\n";
    cout << "\t\t[5]400\t\t\t[6]600\n";
    cout << "\t\t[7]800\t\t\t[8]1000\n";
    cout<< "\t\t[9]Exit"<<endl;
    cout << "\n============================================================\n";
    double WithdrawAmount = (double)GetQuickWithdrawAmount((short)UserInputs::ReadNumberInRange("Choose What To Do ", 1, 9));
    preformQuickWithDraw(CurrentClient, WithdrawAmount);
}

void EndProgramScreen()
{
    cout << "\n----------------------------------------------------------------\n";
    cout << "\t\t\tProgram End :)";
    cout << "\n----------------------------------------------------------------\n";
}

bool preformATMMainMenu(enATMMainMenu ClientChoice)
{
    vClientsData = loadDataFromFileToVector(ClientsFilePath);
    switch (ClientChoice)
    {
    case enATMMainMenu::QuickWithDraw:
        //system("cls");
        showQuickWithdrawScreen();
        back_To_ATM_Main_Menu();
        return true;
    case enATMMainMenu::NormalWithdraw:
        // system("cls");
        showNormalWithdrawScreen();
        back_To_ATM_Main_Menu();
        return true;
    case enATMMainMenu::Deposit:
        // system("cls");
        showDepositScreen();
        back_To_ATM_Main_Menu();
        return true;
    case enATMMainMenu::CheckBalance:
        // system("cls");
        showCheckBalanceScreen();
        back_To_ATM_Main_Menu();
        return true;
    case enATMMainMenu::Logout:
        // system("cls");
        EndProgramScreen();
        return true;

    default:

        return false;
    }
    return false;
}

bool ShowATMMainMenuScreen(){
    cout << "\n===============================================================\n";
    cout << "\t\t ATM Main Menu Screen";
    cout << "\n===============================================================\n";
    cout << "\t\t[1] Quick Withdraw \n";
    cout << "\t\t[2] Normal Withdraw \n";
    cout << "\t\t[3] Deposit \n";
    cout << "\t\t[4] Check Balance \n";
    cout << "\t\t[5] Logout  \n";
    cout << "===============================================================" << endl;
    return preformATMMainMenu((enATMMainMenu)readClientChoice(1, 5));
}

void Login()
{

    bool LoginFailed = false;
    short tries = 5;
    string AccountNumber,PINCode;

    do
    {
        cout << "\n======================================================\n";
        cout << "\t\t\tLogin Screen";
        cout << "\n======================================================\n\n";

        if (LoginFailed)
        {
            cout << "\nInvalid AcountNumber/PIN code\n";
            tries--;
        }

        if(tries ==0){
            cout << "Your Have Zero Tries ,Please Try Again Later :( " << endl;

            return EndProgramScreen();
        }

        cout << "\nEnter Account Number? ";
        getline(cin >> ws, AccountNumber);
        cout << "\nEnter PIN Code ? ";
        getline(cin, PINCode);

        LoginFailed = !findClientByAccountNumberAndPINCode(AccountNumber,PINCode);
    } while (LoginFailed);

    ShowATMMainMenuScreen();
}


int main()
{

    vClientsData = loadDataFromFileToVector(ClientsFilePath);
    Login();

    return 0;
}