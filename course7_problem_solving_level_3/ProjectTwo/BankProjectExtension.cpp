#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../Mylib.h"
using namespace std;

string FilePath = "Clients.txt";

enum enMainMenu
{
    ShowClientsList = 1,
    AddClients = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Transactions=6,
    Exit = 7
};

enum enTransactionMenu
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalances = 3,
    eMainMenu = 4,
    eExit=5
};

struct stClientData
{
    string AccountNumber = "";
    string PinCode = "";
    string FullName = "";
    string Phone = "";
    double AccountBalance = 0.00;
    bool markforDelete = false;
};

int readUserChoice(short min, short max);
bool preformMainScreenMenu(enMainMenu UserChoice);
bool preformTransactionsScreenMenu(enTransactionMenu UserChoice);

void ShowMainMenu()
{
    cout << "=======================================================================\n";
    cout << "\t\t\t\t Main Menu Screen \n";
    cout << "=======================================================================\n";
    cout << "\t\t[1] Show Clients List \n";
    cout << "\t\t[2] Add New Clients \n";
    cout << "\t\t[3] Delete Client \n";
    cout << "\t\t[4] Update Client Info \n";
    cout << "\t\t[5] Find Client \n";
    cout << "\t\t[6] Transactions \n";
    cout << "\t\t[7] Exit \n";
    cout << "=======================================================================" << endl;
    preformMainScreenMenu((enMainMenu)readUserChoice(1, 7));
}

int readUserChoice(short min, short max)
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
    string ClientRecord = "";
    ClientRecord += Client.AccountNumber += Delim += Client.PinCode += Delim;
    ClientRecord += Client.FullName += Delim += Client.Phone += Delim;
    ClientRecord += to_string( Client.AccountBalance);

    return ClientRecord;
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

bool isClientExist(string NewClientAccountNumber)
{

    vector<stClientData> vClients_Data;
    fstream ClientsFile;

    ClientsFile.open(FilePath, ios::in);

    if (ClientsFile.is_open())
    {
        string line;
        stClientData Client;

        while (getline(ClientsFile, line))
        {
            Client = convertLineToRecord(line);
            if (Client.AccountNumber == NewClientAccountNumber)
            {
                ClientsFile.close();
                return true;
            }
            vClients_Data.push_back(Client);
        }
    }

    ClientsFile.close();
    return false;
}


void printClientInfo(stClientData ClientInfo)
{
    cout << "| " << left << setw(15) << ClientInfo.AccountNumber << "| " << left << setw(10)
         << ClientInfo.PinCode << "| " << left << setw(40) << ClientInfo.FullName << "| " << left << setw(12)
         << ClientInfo.Phone << "| " << left << setw(12) << ClientInfo.AccountBalance << endl;
}

void showClientsData() 
{

    vector<stClientData> Clients_Info;
    
    Clients_Info = loadDataFromFileToVector();
    
    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t Show Clients Data\n ";
    cout << "-------------------------------------------------------------------------------\n";
    
    cout << "\n\t\t\t\tClients List (" << Clients_Info.size() << ") Client(s)\n";
    
    cout << "_______________________________________________________________________________________________\n";
    cout << "| " << left << setw(15) << "Account Number" << "| " << left << setw(10)
    << "Pin Code" << "| " << left << setw(40)
    << "Client Name" << "| " << left << setw(12)
    << "Phone" << "| " << left << setw(12)
    << "Balance" << endl;
    cout << "_______________________________________________________________________________________________\n";

    for (stClientData &ClientInfo : Clients_Info)
    {
        printClientInfo(ClientInfo);
    }
    cout << "_______________________________________________________________________________________________\n";

}

stClientData ReadNewClient()
{
    stClientData Client;

    cout << "Enter The Account Number : ";
    getline(cin >> ws, Client.AccountNumber);

    while (isClientExist(Client.AccountNumber))
    {
        cout << "the Client With Account Number [" << Client.AccountNumber << "] Already exist Please Retry :";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "\nEnter PinCode : ";
    getline(cin >> ws, Client.PinCode);

    cout << "\nEnter the Full Name : ";
    getline(cin, Client.FullName);
    cout << "\nEnter the  Phone Number : ";
    getline(cin, Client.Phone);

    cout << "\nEnter Account Balance : ";
    cin >> Client.AccountBalance;
    cout << endl;

    return Client;
}

bool SaveClientRecordToFile(stClientData NewClientData)
{
    fstream ClientsFile;

    string ClinetLine = convertRecordToLine(NewClientData, "#//#");

    ClientsFile.open(FilePath, ios::out | ios::app);

    if (ClientsFile.is_open())
    {
        ClientsFile << ClinetLine << endl;
        ClientsFile.close();
    }

    cout << "Your Client data Added Successfully" << endl;
    return true;
}
void addNewClient()
{

    stClientData NewClient = ReadNewClient();

    SaveClientRecordToFile(NewClient);
}

void addNewClients()
{

    char AddNewClient = 'Y';

    do
    {
        cout << "Add New Client \n";

        addNewClient();
        cout << "Client Added Successfully, Do You Want To Add Another Client ? ";
        cin >> AddNewClient;

    } while (toupper(AddNewClient) == 'Y');
}

void showAddClientsScreen()
{
    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t Add New Client Screen \n";
    cout << "-------------------------------------------------------------------------------\n";
    addNewClients();
}

bool findClientByAccountNumber(string clientAccountNumber, vector<stClientData> vClients_Data, stClientData &Client)
{

    for (stClientData &C : vClients_Data)
    {
        if (C.AccountNumber == clientAccountNumber)
        {

            Client = C;
            return true;
        }
    }
    return false;
}

void printClientCard(stClientData client)
{
    cout << "\n_______________________ Client Info __________________________________\n";
    cout << "Account Number : " << client.AccountNumber;
    cout << "\nPin Code : " << client.PinCode;
    cout << "\nFullName : " << client.FullName;
    cout << "\nPhone : " << client.Phone;
    cout << "\nAccount Balance : " << client.AccountBalance;
    cout << "\n_______________________________________________________________________" << endl;
}

bool markClientForDelete(vector<stClientData> &vClients_Data, string clientAccountNumber)
{
    for (stClientData &clientInfo : vClients_Data)
    {
        if (clientInfo.AccountNumber == clientAccountNumber)
        {
            clientInfo.markforDelete = true;
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

bool deleteClientByAccountNumber(string clientAccountNumber)
{

    stClientData clientCard;
    vector<stClientData> vClients_Data = loadDataFromFileToVector();
    char Answer = 'Y';

    if (findClientByAccountNumber(clientAccountNumber, vClients_Data, clientCard))
    {
        printClientCard(clientCard);
        cout << "are you sure you want to delete this Account ?(Y/N) ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            markClientForDelete(vClients_Data, clientAccountNumber);
            save_Clients_Data_To_File(vClients_Data);
            cout << "the Account Deleted successfully :)" << endl;
            vClients_Data = loadDataFromFileToVector();
        }
        else
        {
            cout << "the Account Deletion is canceled :)" << endl;
        }
    }
    else
    {

        cout << "\nClient With The Account Number " << clientAccountNumber << " Is Not Found :(" << endl;
    }
    return false;
}

bool delete_Clients()
{

    string clientAccountNumber;
    char deleteClient = 'Y';

    do
    {
        clientAccountNumber = UserInputs::ReadString("Enter the Client account number you want to delete : ");
        deleteClientByAccountNumber(clientAccountNumber);

        cout << "Do You Want To Another Account ? (Y/N) ";
        cin >> deleteClient;
    } while (toupper(deleteClient) == 'Y');

    return true;
}

bool showDeleteClientByScreen()
{

    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t Delete Client Screen \n";
    cout << "-------------------------------------------------------------------------------\n";

    delete_Clients();

    return true;
}

stClientData changeClientData(string AccountNumber)
{
    stClientData Client;
    Client.AccountNumber = AccountNumber;

    cout << "\nEnter PinCode : ";
    getline(cin >> ws, Client.PinCode);

    cout << "\nEnter the Full Name : ";
    getline(cin, Client.FullName);
    cout << "\nEnter the  Phone Number : ";
    getline(cin, Client.Phone);

    cout << "\nEnter Account Balance : ";
    cin >> Client.AccountBalance;
    cout << endl;

    return Client;
}

bool UpdateClientdata()
{

    vector<stClientData> vClients_Data = loadDataFromFileToVector();
    stClientData clientCard;

    char Answer;

    string AccountNumber = UserInputs::ReadString("Enter Client Account Number you want to update : ");

    if (findClientByAccountNumber(AccountNumber, vClients_Data, clientCard))
    {

        printClientCard(clientCard);
        cout << "\nare you sure you want to Update this Account ?(Y/N) ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            for (stClientData &oldClient : vClients_Data)
            {
                if (oldClient.AccountNumber == AccountNumber)
                {
                    oldClient = changeClientData(AccountNumber);
                    break;
                }
            }
            save_Clients_Data_To_File(vClients_Data);
            cout << "the Account Updated successfully :)" << endl;
            vClients_Data = loadDataFromFileToVector();
        }
        else
        {
            cout << "the Account Updating is canceled :)" << endl;
        }
    }
    else
    {

        cout << "the Client With Account Number [" << AccountNumber << "] is Not found :(";
    }
    return false;
}

bool Update_Clients_Data()
{
    char updateClientData = 'Y';
    stClientData ClientData;

    do
    {
        UpdateClientdata();

        cout << "\nDo You Want To update Anther Client  Account ? ";
        cin >> updateClientData;

    } while (toupper(updateClientData) == 'Y');

    return true;
}

bool showUpdateClientsScreen()
{
    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t Update Client Screen \n";
    cout << "-------------------------------------------------------------------------------\n";

    Update_Clients_Data();

    return true;
}

bool find_Client(vector<stClientData> vClients_Data, string ClientAccountNumber)
{

    stClientData client;
    if (findClientByAccountNumber(ClientAccountNumber, vClients_Data, client))
    {

        printClientCard(client);
        return true;
    }

    cout << "\nSorry they is no Client with the Account Number " << ClientAccountNumber << " exist " << endl;

    return false;
}

bool showFind_Clients_Screen()
{

    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t Find Client Screen \n";
    cout << "-------------------------------------------------------------------------------\n";

    vector<stClientData> vClients_Data = loadDataFromFileToVector();

    string ClientAccountNumber;
    char Answer = 'Y';
    
    do
    {
        ClientAccountNumber = UserInputs::ReadString("Enter the Client Account number you want to search for : ");
        find_Client(vClients_Data, ClientAccountNumber);

        cout << "Do You Want To Search For Another Client :";
        cin >> Answer;
    } while (toupper(Answer) == 'Y');

    return true;
}

bool preformMainScreenMenu(enMainMenu UserChoice);

void backToMainMenu()
{
    char backToMain;
    cout << "\n\nEnter Any LetterTo Back To  Main Menu ...\n";
    cin >> backToMain;
    ShowMainMenu();
}

bool DepositAccountByAccountNumber(vector<stClientData> vClients_Data, string AccountNumber, double DepositAmount)
{
    char Answer = 'Y';
    cout << "Are You Sure You Want to perform this transaction ? ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
    {

        for (stClientData &Client : vClients_Data)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                Client.AccountBalance += DepositAmount;
                save_Clients_Data_To_File(vClients_Data);
                cout << "Done Successfully The New Balance is " << Client.AccountBalance << endl;
                return true;
            }
        }
    }

    cout << "the transaction was canceled  ";
    return false;
}

bool preformDeposit()
{

    vector<stClientData> vClients_Data = loadDataFromFileToVector();
    string AccountNumber = UserInputs::ReadString("Enter Account Number : ");
    stClientData Client;
    double DepositAmount;

    while (!(findClientByAccountNumber(AccountNumber, vClients_Data, Client)))
    {
        cout << "Client With Account Number " << AccountNumber << " Is Not Exist " << endl;
        AccountNumber = UserInputs::ReadString("Enter Account Number : ");
    }

    printClientCard(Client);

    cout << "Please Enter the Amount ? ";
    cin >> DepositAmount;

    DepositAccountByAccountNumber(vClients_Data, AccountNumber, DepositAmount);
    return true;
}

void showDepositScreen()
{

    cout << "=======================================================================\n";
    cout << "\t\t\t\t Deposit Menu Screen \n";
    cout << "=======================================================================\n";

    preformDeposit();
}

bool preformWithdraw()
{

    vector<stClientData> vClients_Data = loadDataFromFileToVector();
    string AccountNumber = UserInputs::ReadString("Enter Account Number : ");
    stClientData Client;
    double WithdrawAmount = 0.0000;
    while (!(findClientByAccountNumber(AccountNumber, vClients_Data, Client)))
    {
        cout << "Client With Account Number " << AccountNumber << " Is Not Exist Please Retry " << endl;
        AccountNumber = UserInputs::ReadString("Enter Account Number : ");
    }

    printClientCard(Client);

    cout << "Please Enter Withdraw Amount ? ";
    cin >> WithdrawAmount;

    while (WithdrawAmount > Client.AccountBalance)
    {
        cout << "Amount Exceed The Balance You Cannot Withdraw Up To :" << Client.AccountBalance << endl;
        cout << "please Enter Another Amount ?";
        cin >> WithdrawAmount;
    }

    DepositAccountByAccountNumber(vClients_Data, AccountNumber, WithdrawAmount * -1);
    return true;
}

void showWithdrawScreen()
{

    cout << "=======================================================================\n";
    cout << "\t\t\t\t Withdraw Menu Screen \n";
    cout << "=======================================================================\n";

    preformWithdraw();
}

void print_Client_Balance_Info(stClientData ClientInfo)
{
    cout << "| " << left << setw(15) << ClientInfo.AccountNumber << "| " << left << setw(40) << ClientInfo.FullName
         <<"| "<< left << setw(12) << ClientInfo.AccountBalance << endl;
}

void show_Clients_Balances_Info()
{


    vector<stClientData> Clients_Info;

    Clients_Info = loadDataFromFileToVector();
    double TotalBalances = 0.00;

    cout << "\n\t\t\t\tBalances List (" << Clients_Info.size() << ") Client(s)\n";

    cout << "_______________________________________________________________________________________________\n";
    cout << "| " << left << setw(15) << "Account Number"
         << "| " << left << setw(40)
         << "Client Name" << "| " << left << setw(12)
         << "Balance" << endl;
    cout << "_______________________________________________________________________________________________\n";

    for (stClientData &ClientInfo : Clients_Info)
    {
        print_Client_Balance_Info(ClientInfo);
        TotalBalances += ClientInfo.AccountBalance;
    }
    cout << "_______________________________________________________________________________________________\n";
    cout << "\n\t\t\t\tTotal Balances = " << TotalBalances << endl;

}


void showTransactionsMenu(){

    cout << "=======================================================================\n";
    cout << "\t\t\t\t Transactions Menu Screen \n";
    cout << "=======================================================================\n";
    cout << "\t\t[1] Deposit \n";
    cout << "\t\t[2] Withdraw \n";
    cout << "\t\t[3] Total Balances \n";
    cout << "\t\t[4] Main Menu \n";
    cout << "\t\t[5] Exit  \n";

    cout << "=======================================================================" << endl;
    preformTransactionsScreenMenu((enTransactionMenu)readUserChoice(1,5));
}

void backToTRansactionsMenu()
{

    char back;
    cout << "Enter Any Letter To Back To Transactions Menu ...\n";
    cin >> back;
    showTransactionsMenu();
}

void EndProgramScreen()
{
    cout << "\n----------------------------------------------------------------\n";
    cout << "\t\t\tProgram End :)";
    cout << "\n----------------------------------------------------------------\n";
}

bool preformTransactionsScreenMenu(enTransactionMenu UserChoice){
    switch (UserChoice)
    {
    case enTransactionMenu::eDeposit:
        //system("cls");
        showDepositScreen();
        backToTRansactionsMenu();
        return true;
    case enTransactionMenu::eWithdraw:
        // system("cls");
        showWithdrawScreen();
        // showWithDrawScreen();
        backToTRansactionsMenu();
        return true;
    case enTransactionMenu::eTotalBalances:
        // system("cls");
        show_Clients_Balances_Info();
        backToTRansactionsMenu();
        return true;
    case enTransactionMenu::eMainMenu:
        // system("cls");
        backToMainMenu();
        return true;
    case enTransactionMenu::eExit:
        // system("cls");
        EndProgramScreen();
            return true;

        default:

        return false;
    }
    return false;
}

bool preformMainScreenMenu(enMainMenu UserChoice)
{
    switch (UserChoice)
    {
    case enMainMenu::ShowClientsList:
        ////system("cls");
        showClientsData();
        backToMainMenu();
        return true;

    case enMainMenu::AddClients:
        ////system("cls");
        showAddClientsScreen();
        backToMainMenu();
        return true;

    case enMainMenu::DeleteClient:
        // system("cls");
        showDeleteClientByScreen();
        backToMainMenu();
        return true;

    case enMainMenu::UpdateClientInfo:
        // system("cls");
        showUpdateClientsScreen();
        backToMainMenu();
        return true;

    case enMainMenu::FindClient:
        // system("cls");
        showFind_Clients_Screen();
        backToMainMenu();
        return true;
        
    case enMainMenu::Transactions:
        //system("cls");
        showTransactionsMenu();
        return true;
    case enMainMenu::Exit:
        // system("cls");
        EndProgramScreen();
        return true;

    default:
        return false;
    }
}

int main()
{


    ShowMainMenu();

    return 0;
}