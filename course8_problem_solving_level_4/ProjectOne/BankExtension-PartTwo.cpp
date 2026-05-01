#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../MyLib.h"
using namespace std;

string ClientsFilePath = "Clients.txt";

enum enMainMenu
{
    ShowClientsList = 1,
    AddClients = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Transactions=6,
    MangeUsers=7,
    Logout= 8
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

struct stUserData
{
    string UserName = "";
    string Password = "";
    short permission = 0;
    bool MarkForDelete = false;
};

enum enMangeUsersMenu
{

    showUsersList = 1,
    AddUser = 2,
    DeleteUser = 3,
    UpdateUserInfo = 4,
    FindUser = 5,
    backToMainMenu = 6

};
enum enMainMenuPermission
{
    pAll = -1,
    pListClient = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClient = 8,
    pFindClient = 16,
    pTransactions = 32,
    pManageUsers = 64
};

stUserData CurrentUser;

string UsersFilePath = "Users.txt";

bool CheckAccessPermission(enMainMenuPermission Permission ){
    if(CurrentUser.permission ==enMainMenuPermission::pAll){
        return true;
    }

    if((Permission & CurrentUser.permission ) == Permission){
        return true;
    }
    return false;
}

void ShowAccessDeniedMessage(){
    cout << "\n--------------------------------------------\n";
    cout <<"Access Denied ,\n You Dont Have Permission To Do This ,\n";
    cout <<"Please Contact Your Admin\n";
    cout << "\n--------------------------------------------\n";

}

void ShowMainMenu();

bool IsUserHasAccess(enMainMenuPermission Permissions){
    if(!CheckAccessPermission(Permissions)){
        ShowAccessDeniedMessage();
        ShowMainMenu();
        return false;
    }
    return true;
}

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
    cout << "\t\t[7] Mange Users \n";
    cout << "\t\t[8] Logout \n";
    cout << "=======================================================================" << endl;
    preformMainScreenMenu((enMainMenu)readUserChoice(1, 8));
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

bool isClientExist(string NewClientAccountNumber, string FilePath)
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

     if(!IsUserHasAccess(enMainMenuPermission::pListClient)){
         return;
     }

    vector<stClientData> Clients_Info;
    
    Clients_Info = loadDataFromFileToVector(ClientsFilePath);
    
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

    while (isClientExist(Client.AccountNumber, ClientsFilePath))
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

bool SaveClientRecordToFile(stClientData NewClientData, string FilePath)
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

    SaveClientRecordToFile(NewClient, ClientsFilePath);
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

    if (!IsUserHasAccess(enMainMenuPermission::pAddNewClient))
    {
        return;
    }
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

vector<stClientData> save_Clients_Data_To_File(vector<stClientData> vClients_Data,string FilePath)
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
    vector<stClientData> vClients_Data = loadDataFromFileToVector(ClientsFilePath);
    char Answer = 'Y';

    if (findClientByAccountNumber(clientAccountNumber, vClients_Data, clientCard))
    {
        printClientCard(clientCard);
        cout << "are you sure you want to delete this Account ?(Y/N) ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            markClientForDelete(vClients_Data, clientAccountNumber);
            save_Clients_Data_To_File(vClients_Data, ClientsFilePath);
            cout << "the Account Deleted successfully :)" << endl;
            vClients_Data = loadDataFromFileToVector(ClientsFilePath);
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

        cout << "Do You Want To Delete Another Account ? (Y/N) ";
        cin >> deleteClient;
    } while (toupper(deleteClient) == 'Y');

    return true;
}

bool showDeleteClientByAccountNumberScreen()
{

    if (!IsUserHasAccess(enMainMenuPermission::pDeleteClient))
    {
        return false;
    }
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

    vector<stClientData> vClients_Data = loadDataFromFileToVector(ClientsFilePath);
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
            save_Clients_Data_To_File(vClients_Data, ClientsFilePath);
            cout << "the Account Updated successfully :)" << endl;
            vClients_Data = loadDataFromFileToVector(ClientsFilePath);
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

    if (!IsUserHasAccess(enMainMenuPermission::pUpdateClient))
    {
        return false;
    }
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
    if (!IsUserHasAccess(enMainMenuPermission::pFindClient))
    {
        return false;
    }

    cout << "-------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t Find Client Screen \n";
    cout << "-------------------------------------------------------------------------------\n";

    vector<stClientData> vClients_Data = loadDataFromFileToVector(ClientsFilePath);

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

void back_To_Main_Menu()
{
    char backToMain;
    
    cout << "\n\nEnter Any Letter To Back To  Main Menu ...\n";
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
                save_Clients_Data_To_File(vClients_Data,ClientsFilePath);
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

    vector<stClientData> vClients_Data = loadDataFromFileToVector(ClientsFilePath);
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

    vector<stClientData> vClients_Data = loadDataFromFileToVector(ClientsFilePath);
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

    Clients_Info = loadDataFromFileToVector(ClientsFilePath);
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

    if (!IsUserHasAccess(enMainMenuPermission::pTransactions))
    {
        return;
    }

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
        back_To_Main_Menu();
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



// -------- Bank Extention 2 ---



stUserData convertUserLineToRecord(string lineRecord, string Delim = "#//#")
{
    stUserData UserData;

    vector<string> vString = splitString(lineRecord, Delim);

    if (vString.size() < 3)
        return UserData;

    UserData.UserName = vString[0];
    UserData.Password= vString[1];
    UserData.permission =stoi(vString[2]);

    return UserData;
}
string convertUserRecordToLine(stUserData User, string Delim = "#//#")
{

    return User.UserName + Delim + User.Password + Delim +to_string(User.permission);
    
}

vector<stUserData> loadUsersDataFromFileToVector(string FilePath)
{
    vector<stUserData> vUsersData;
    fstream MyFile;
    stUserData stUser;

    MyFile.open(FilePath, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string line;

        while (getline(MyFile, line))
        {
            stUser = convertUserLineToRecord(line, "#//#");
            vUsersData.push_back(stUser);
        }
        MyFile.close();
    }

    return vUsersData;
}

bool saveUserRecordToFile(stUserData UserData, string FilePath)
{
    fstream UsersFile;

    string UserLine = convertUserRecordToLine(UserData, "#//#");

    UsersFile.open(FilePath, ios::out | ios::app);

    if (UsersFile.is_open())
    {
        UsersFile << UserLine << endl;
        UsersFile.close();
    }

    return true;
}

vector<stUserData> save_Users_Data_To_File(vector<stUserData> vUsers_Data, string FilePath)
{
    fstream Users_File;
    Users_File.open(FilePath, ios::out);
    if (Users_File.is_open())
    {

        for (stUserData &User_info : vUsers_Data)
        {
            if (User_info.MarkForDelete == false)
            {
                Users_File << convertUserRecordToLine(User_info, "#//#") << endl;
            }
        }

        Users_File.close();
    }
    return vUsers_Data;
}

    bool isUserExist(string InputtedUserName, string FilePath)
{

    fstream UsersFile;

    UsersFile.open(FilePath, ios::in);

    if (UsersFile.is_open())
    {
        string line;
        stUserData User;

        while (getline(UsersFile, line))
        {
            User = convertUserLineToRecord(line);
            if (User.UserName == InputtedUserName)
            {
                UsersFile.close();
                return true;
            }
        }
    }

    UsersFile.close();
    return false;
}

bool isCorrectPassword(string InputtedUserName ,string inputtedPassword, vector<stUserData> vUsers)
{
    for(stUserData &user:vUsers){
        if(user.UserName ==InputtedUserName &&  user.Password == inputtedPassword){
            return true;
        }
    }
    return false;
}

bool preformMangeUsers(enMangeUsersMenu choice);

bool findUserByUserNameAndPassword(string UserName,string  Password){
    vector<stUserData> vUserDate = loadUsersDataFromFileToVector(UsersFilePath);

    for (stUserData &U:vUserDate){
        if(U.UserName ==UserName && U.Password == Password){
            CurrentUser = U;
            return true;
        }
    }
    return false;
}

    bool LoadUserInfo(string UserName, string Password)
{

    return findUserByUserNameAndPassword(UserName, Password);
}

void ShowLoginScreen()
{

    bool LoginFailed = false;
    string UserName, Password;

    do
    {
        cout << "\n======================================================\n";
        cout << "\t\t\tLogin Screen";
        cout << "\n======================================================\n\n";

        if (LoginFailed)
        {
            cout << "\nInvalid Username/Password\n";
        }

        cout << "\nEnter Username? ";
        getline(cin >> ws, UserName);
        cout << "\nEnter Password ? ";
        getline(cin, Password);

        LoginFailed = !LoadUserInfo(UserName, Password);
    } while (LoginFailed);

    ShowMainMenu();
}

    void showMangeUsersScreen()
{

    if (!IsUserHasAccess(enMainMenuPermission::pManageUsers))
    {
        return;
    }
    cout << "\n=======================================================================\n";
    cout << "\t\t\t\t Mange Users Screen";
    cout << "\n=======================================================================\n";
    cout << "\t\t[1] Show Users List \n";
    cout << "\t\t[2] Add New User \n";
    cout << "\t\t[3] Delete User \n";
    cout << "\t\t[4] Update User Info \n";
    cout << "\t\t[5] Find User \n";
    cout << "\t\t[6] Main Menu \n";
    cout << "=======================================================================" << endl;
    preformMangeUsers((enMangeUsersMenu)readUserChoice(1, 6));
}

void backToMangeUserMenu()
{
    char backToMange;
    cout << "\n\nEnter Any Letter To Back To  , Mange Menu ...\n";
    cin >> backToMange;
    showMangeUsersScreen();
}



void printUserInfo(stUserData UserInfo)
{
    cout << "| " << left << setw(30) << UserInfo.UserName << "| " << left << setw(20)
         << UserInfo.Password << "| " << left << setw(20) << UserInfo.permission << endl;
}

void showUsersData()
{

    vector<stUserData> vUsersInfo;

    vUsersInfo = loadUsersDataFromFileToVector(UsersFilePath);

  

    cout << "\n\t\t\tUsers List (" << vUsersInfo.size() << ") User(s)\n";

    cout << "_______________________________________________________________________________________________\n";
    cout << "| " << left << setw(30) << "User Full Name" << "| " << left << setw(20)
         << "Password " << "| " << left << setw(20)
         << "Permission" << "| " << endl;
    cout << "_______________________________________________________________________________________________\n";

    for (stUserData &UserInfo :vUsersInfo)
    {
        printUserInfo(UserInfo);
    }
    cout << "_______________________________________________________________________________________________\n";
}

void showUsersListScreen(){

    cout << "\n=================================================\n";
    cout << "\t\t\t Users Data Screen\n ";
    cout << "\n=================================================\n";

    showUsersData();
}

short ReadUserPermissionToSet()
{
    short Permission = 0;

    char Answer = 'n';
    cout << "\nDo You Want To Give This User Full Permission ?(Y/N) ";
    cin >> Answer;

    if(toupper(Answer)=='Y'){
       return  Permission = -1;
    }

    cout << "\nDo You Want To Give Access To :\n";

    cout << "\n show Clients  ?(Y/N) ";
    cin >> Answer;
    if (toupper(Answer)=='Y')
    {
        Permission +=enMainMenuPermission::pListClient;
    }

    cout << "\nAdd Clients ?(Y/N) ";
    cin >> Answer;
    if (toupper(Answer)=='Y')
    {
        Permission +=enMainMenuPermission::pAddNewClient ;
    }

    cout << "\nDelate Clients? (Y/N) ";
    cin >> Answer;
    if (toupper(Answer)=='Y')
    {
        Permission +=enMainMenuPermission::pDeleteClient;
    }

    cout << "\nUpdate Clients? (Y/N) ";
    cin >> Answer;
    if (toupper(Answer)=='Y')
    {
        Permission +=enMainMenuPermission::pUpdateClient;
    }

    cout << "\n Find Clients? (Y/N) ";
    cin >> Answer;
    if (toupper(Answer)=='Y')
    {
        Permission += enMainMenuPermission::pFindClient;
    }

    cout << "\n Transactions ? (Y/N) ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
    {
        Permission += enMainMenuPermission::pTransactions;
    }

    cout << "\n Mange Users ? (Y/N) ";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
    {
        Permission += enMainMenuPermission::pManageUsers;
    }

    return Permission;
}

stUserData ReadNewUser()
{
    stUserData stUser;

    cout << "Enter The User FullName : ";
    getline(cin >> ws, stUser.UserName);

    while (isUserExist(stUser.UserName, UsersFilePath))
    {
        cout << " User With The Name [" << stUser.UserName << "] Already exist Please Retry :";
        getline(cin >> ws, stUser.UserName);
    }

    cout << "\nEnter a Password : ";
    getline(cin >> ws, stUser.Password);

    stUser.permission = ReadUserPermissionToSet();


    return stUser;
}

void addNewUsers(){
    char Answer = 'Y';
    do
    {
        saveUserRecordToFile(ReadNewUser(),UsersFilePath);
        cout << "\nThe User Data  Added Successfully\n";
        cout << "\n Do You Want To Add More Users ? (Y/N) ";
        cin >> Answer;
    } while (toupper(Answer) == 'Y');
    
    

}

void showAddUsersScreen(){
    cout << "\n=================================================\n";
    cout << "\t\t Add Users Screen\n ";
    cout << "\n=================================================\n";
    addNewUsers();
}

bool findUserByUserName(string UserName, vector<stUserData> vUsersData, stUserData &User)
{

    for (stUserData &U : vUsersData)
    {
        if (U.UserName == UserName)
        {

            User= U;
            return true;
        }
    }
    return false;
}

void printUserCard(stUserData User)
{
    cout << "\n_______________________ User Info __________________________________\n";
    cout << "UserName : " << User.UserName;
    cout << "\nPassword : " << User.Password;
    cout << "\nPermission : " << User.permission;
    cout << "\n_______________________________________________________________________" << endl;
}

bool markUserForDelete(vector<stUserData> &vUserData, string InputtedUserName)
{

    for (stUserData &UserInfo : vUserData)
    {
        if (UserInfo.UserName == InputtedUserName)
        {
            UserInfo.MarkForDelete= true;
            return true;
        }
    }
    return false;
}

bool deleteUserByUserName(string UserName)
{

    if (UserName == "Admin")
    {
        cout << "\nSorry You Cant Delete this User" << endl;
        return false;
    }

    stUserData UserCard;
    vector<stUserData> vUsersData = loadUsersDataFromFileToVector(UsersFilePath);
    char Answer = 'Y';

    if (findUserByUserName(UserName, vUsersData,UserCard))
    {
        printUserCard(UserCard);
        cout << "are you sure you want to delete this User ?(Y/N) ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            markUserForDelete(vUsersData, UserName);
            save_Users_Data_To_File(vUsersData, UsersFilePath);
            cout << "this User Deleted successfully :)" << endl;
            vUsersData = loadUsersDataFromFileToVector(UsersFilePath);
        }
        else
        {
            cout << "the Operation is canceled :)" << endl;
        }
    }
    else
    {

        cout << "\nUser With The User Name " << UserName<< " Is Not Exist :(" << endl;
    }
    return false;
}

bool DeleteUsers()
{

    string UserName;
    char Answer = 'Y';

    do
    {
        UserName = UserInputs::ReadString("Enter the User FullName you want to delete : ");
        deleteUserByUserName(UserName);

        cout << "Do You Want To Delete Another User ? (Y/N) ";
        cin >> Answer;
    } while (toupper(Answer) == 'Y');

    return true;
}


void showDeleteUserScreen(){

    cout << "\n=================================================\n";
    cout << "\t\t Delete Users Screen\n ";
    cout << "\n=================================================\n";
    DeleteUsers();
}

bool FindUsers(){
    vector<stUserData> vUsersData = loadUsersDataFromFileToVector(UsersFilePath);
    string UserName;
    stUserData stUserInfo;
    char Answer = 'Y';

    do
    {
        UserName = UserInputs::ReadString("Enter the User FullName you want to Search For : ");
        if(findUserByUserName(UserName, vUsersData,stUserInfo)){
            printUserCard(stUserInfo);
        }else{
            cout << "User With The Name " << UserName << " Is Not Exist " << endl;
        }


        cout << "\nDo You Want To Search For Another User ? (Y/N) ";
        cin >> Answer;
    } while (toupper(Answer) == 'Y');

    return true;
}


void showFindUserScreen(){

    cout << "\n=================================================\n";
    cout << "\t\t\t Find Users Screen\n ";
    cout << "\n=================================================\n";
    FindUsers();
}

stUserData changeUserData(string inputtedUserName)
{
    stUserData stUser;
    stUser.UserName = inputtedUserName;

    cout << "\nEnter UserPassWord : ";
    getline(cin >> ws, stUser.Password);

    stUser.permission = ReadUserPermissionToSet();

    return stUser;
}

bool UpdateUserdata()
{

    vector<stUserData> vUsers_Data = loadUsersDataFromFileToVector(UsersFilePath);
    stUserData UserCard;

    char Answer;

    string inputtedUserName = UserInputs::ReadString("Enter The UserName you want to update : ");

    if (findUserByUserName(inputtedUserName, vUsers_Data, UserCard))
    {

        printUserCard(UserCard);
        cout << "\nare you sure you want to Update this User ?(Y/N) ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            for (stUserData &oldUserInfo : vUsers_Data)
            {
                if (oldUserInfo.UserName == inputtedUserName)
                {
                    oldUserInfo = changeUserData(inputtedUserName);
                    break;
                }
            }
            save_Users_Data_To_File(vUsers_Data, UsersFilePath);
            cout << "the Account Updated successfully :)" << endl;
            vUsers_Data = loadUsersDataFromFileToVector(UsersFilePath);
        }
        else
        {
            cout << "the User Updating is canceled :)" << endl;
        }
    }
    else
    {

        cout << "the User With the UserName [" << inputtedUserName << "] is Not found :(";
    }
    return false;
}

bool UpdateUsersData()
{
    char Answer = 'Y';
    stUserData UserData;

    do
    {
        UpdateUserdata();

        cout << "\nDo You Want To update Anther User ? ";
        cin >> Answer;

    } while (toupper(Answer) == 'Y');

    return true;
}



void showUpdateUserInfoScreen(){

    cout << "\n=================================================\n";
    cout << "\t\t\t Update Users Screen\n ";
    cout << "\n=================================================\n";
    UpdateUsersData();
}

bool preformMangeUsers(enMangeUsersMenu choice)
{
    switch (choice){
        case enMangeUsersMenu::showUsersList:
            showUsersListScreen();
            backToMangeUserMenu();
            return true;
        case enMangeUsersMenu::AddUser:
            showAddUsersScreen();
            backToMangeUserMenu();
            return true;
        case enMangeUsersMenu::DeleteUser:
            showDeleteUserScreen();
            backToMangeUserMenu();
            return true;
        case enMangeUsersMenu::FindUser:
            showFindUserScreen();
            backToMangeUserMenu();
            return true;
        case enMangeUsersMenu::UpdateUserInfo:
            showUpdateUserInfoScreen();
            backToMangeUserMenu();
            return true;
        case enMangeUsersMenu::backToMainMenu:
            ShowMainMenu();
            return true;
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
        back_To_Main_Menu();
        return true;

    case enMainMenu::AddClients:
        ////system("cls");
        showAddClientsScreen();
        back_To_Main_Menu();
        return true;

    case enMainMenu::DeleteClient:
        // system("cls");
        showDeleteClientByAccountNumberScreen();
        back_To_Main_Menu();
        return true;

    case enMainMenu::UpdateClientInfo:
        // system("cls");
        showUpdateClientsScreen();
        back_To_Main_Menu();
        return true;

    case enMainMenu::FindClient:
        // system("cls");
        showFind_Clients_Screen();
        back_To_Main_Menu();
        return true;
        
    case enMainMenu::Transactions:
        //system("cls");
        showTransactionsMenu();
        return true;
    case enMainMenu::MangeUsers:
        //system("cls");
        showMangeUsersScreen();
        return true;

    case enMainMenu::Logout:
        // system("cls");
      EndProgramScreen();
        return true;

    default:
        return false;
    }
}

int main()
{

    ShowLoginScreen();

    return 0;
}