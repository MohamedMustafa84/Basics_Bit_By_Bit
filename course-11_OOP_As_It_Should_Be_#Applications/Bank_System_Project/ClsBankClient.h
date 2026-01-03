#pragma once

#include <iostream>
#include <vector>
#include "../../Libs/clsString.h" 
#include "ClsPerson.h"
#include <cmath>
#include <fstream>


class clsBankClient:public clsPerson{

    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode=2
    };

    enMode _Mode;
    
    
    string _AccountNumber = "";
    string _PinCode = "";
    float  _AccountBalance = 0.00;
    bool _MarkForDelete = false;

    static clsBankClient
    _ConvertLineToClientObject(string Line, string separator = "#//#")
    {
        vector<string> vClientData = clsString::Split(Line, separator);

        // Validate record integrity
        if (vClientData.size() != 7)
        {
            return _GetEmptyClientObject();
        }

        float balance = 0.0f;

        try
        {
            balance = stof(vClientData[6]);
        }
        catch (...)
        {
            return _GetEmptyClientObject();
        }

        return clsBankClient(
            enMode::UpdateMode,
            vClientData[0], // FirstName
            vClientData[1], // LastName
            vClientData[2], // Email
            vClientData[3], // Phone
            vClientData[4], // AccountNumber
            vClientData[5], // PinCode
            balance);
    }

    static clsBankClient _GetEmptyClientObject(){
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "","",0);
    }

        static string  _ConvertClientObjectToLine(clsBankClient &Client,string Separator="#//#" ){

            string ClientRecord = "";

            ClientRecord += Client.FirstName() + Separator;
            ClientRecord += Client.LastName() + Separator;
            ClientRecord += Client.Email() + Separator;
            ClientRecord += Client.Phone() + Separator;
            ClientRecord += Client.AccountNumber() + Separator;
            ClientRecord += Client.PinCode() + Separator;
            ClientRecord += to_string(Client.AccountBalance());

            return ClientRecord;
        }

        static vector <clsBankClient> _LoadClientsDataFromFile(string FilePath="../Clients.txt"){
            vector<clsBankClient> vClients;

            fstream ClientsFile;

            ClientsFile.open(FilePath, ios::in);

            if (ClientsFile.is_open()){
                string Line;

                while(getline(ClientsFile,Line)){

                    clsBankClient Client = _ConvertLineToClientObject(Line);
                    if (!Client.IsEmpty())
                    {
                        vClients.push_back(Client);
                    }
                }

                ClientsFile.close();
            }
            return vClients;
        }

        static void _SaveClientsDataToFile(vector<clsBankClient> vClients, string FilePath = "../Clients.txt")
        {
            

            fstream ClientsFile;

            ClientsFile.open(FilePath, ios::out); //overwrite

            string DataLine;

            if (ClientsFile.is_open())
            {

                for (clsBankClient &ClientObject: vClients)
                {
                     
                    if(ClientObject._MarkForDelete){
                        continue;
                    }
                    DataLine = _ConvertClientObjectToLine(ClientObject);

                    ClientsFile << DataLine<<endl;
                }

                ClientsFile.close();
            }
        }

        void _Update(){
            vector<clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();

            for (clsBankClient &Client :_vClients){

                if(Client.AccountNumber() == AccountNumber()){
                    Client = *this;
                    break;
                }
            }

            _SaveClientsDataToFile(_vClients);
        }



        void _AddNewClient(){
           _AddDataLineToFile (_ConvertClientObjectToLine(*this));

        }

        void _AddDataLineToFile(string DataLine){
            fstream ClientsFile;

            ClientsFile.open("../Clients.txt", ios::out | ios::app);

            if(ClientsFile.is_open()){

                ClientsFile << DataLine << endl;

                ClientsFile.close();
            }

        }

        public:
            clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
                : clsPerson(FirstName, LastName, Email, Phone)
            {

                _Mode = Mode;
                _AccountNumber = AccountNumber;
                _AccountBalance = AccountBalance;
                _PinCode = PinCode;

            }

            bool IsEmpty()
            {
                return (_Mode == enMode::EmptyMode);
            }

            string AccountNumber()const
            {
                return _AccountNumber;
            }
            void SetAccountNumber(string AccountNumber)
            {
                _AccountNumber = AccountNumber;
            }

            float AccountBalance()
            {
                return _AccountBalance;
            }
            void SetAccountBalance(float AccountBalance)
            {
                _AccountBalance = AccountBalance;
            }

            string PinCode()
            {
                return _PinCode;
            }
            void SetPinCode(string PinCode)
            {
                _PinCode = PinCode;
            }

            void Print()
            {
                cout << "\n Client Card ";
                cout << "\n-----------------------------------";
                cout << "\nFirst Name     : " << FirstName();
                cout << "\nLast Name      : " << LastName();
                cout << "\nFull Name      : " << FullName();
                cout << "\nEmail          : " << Email();
                cout << "\n Phone         : " << Phone();
                cout << "\n PIN Code      : " << _PinCode;
                cout << "\nAccount Number : " << _AccountNumber;
                cout << "\n Balance       : " << _AccountBalance;
                cout << "\n-----------------------------------\n";
            }

            static clsBankClient Find(string AccountNumber)
            {

                vector<clsBankClient> vClients;

                fstream ClientsFile;

                ClientsFile.open("../Clients.txt", ios::in);
                if (ClientsFile.is_open())
                {

                    string Line;

                    while (getline(ClientsFile, Line))
                    {
                        clsBankClient Clinet = _ConvertLineToClientObject(Line);
                        if (Clinet.AccountNumber() == AccountNumber)
                        {
                            ClientsFile.close();
                            return Clinet;
                        }
                        vClients.push_back(Clinet);
                    }

                    ClientsFile.close();
                }
                return _GetEmptyClientObject();
            }

            static clsBankClient Find(string AccountNumber, string PINCode)
            {

                vector<clsBankClient> vClients;

                fstream ClientsFile;

                ClientsFile.open("../Clients.txt", ios::in);
                if (ClientsFile.is_open())
                {

                    string Line;

                    while (getline(ClientsFile, Line))
                    {
                        clsBankClient Clinet = _ConvertLineToClientObject(Line);
                        if (Clinet._AccountNumber == AccountNumber && Clinet._PinCode == PINCode)
                        {
                            ClientsFile.close();
                            return Clinet;
                        }
                        vClients.push_back(Clinet);
                    }

                    ClientsFile.close();
                }
                return _GetEmptyClientObject();
            }

            static bool IsClientExist(string AccountNumber)
            {
                clsBankClient Client = clsBankClient::Find(AccountNumber);
                return (!Client.IsEmpty());
            }

            enum enSaveResult
            {
                svFailEmptyObject = 0,
                svSucceeded = 1,
                svFailAccountNumberExists=2
            };

            enSaveResult Save()
            {

                switch (_Mode)
                {
                case enMode::EmptyMode:
                {
                    if (IsEmpty())
                    {

                        return enSaveResult::svFailEmptyObject;
                    }
                    break;
                }

                case enMode::UpdateMode:
                {

                    _Update();

                    return enSaveResult::svSucceeded;

                    break;
                }

                case enMode::AddNewMode:
                {
                    if (clsBankClient::IsClientExist(_AccountNumber))
                    {
                        return enSaveResult::svFailAccountNumberExists;
                    }
                    else
                    {
                        _AddNewClient();

                        // We need to set the mode to update after add new
                        _Mode = enMode::UpdateMode;
                        return enSaveResult::svSucceeded;
                    }

                    break;
                }
                }

                return enSaveResult::svFailEmptyObject;
            }
            static clsBankClient GetAddNewClientObject(string AccountNumber)
            {
                return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
            }



            bool Delete(){
                vector<clsBankClient> vClients;
                bool Deleted = false;

                vClients= _LoadClientsDataFromFile("../Clients.txt");


                    for (clsBankClient &Client :vClients ){

                        if(Client._AccountNumber == _AccountNumber){
                            Client._MarkForDelete = true;
                            Deleted = true;
                            break;
                        }
                    }

                    _SaveClientsDataToFile(vClients);

                    *this = _GetEmptyClientObject();

                    return Deleted;
            }

            static vector <clsBankClient> GetClientsList(){
                return _LoadClientsDataFromFile();
            }

            static float GetTotalBalance()
            {
                vector<clsBankClient> vClients = clsBankClient::GetClientsList();

                float Total = 0;
                for (clsBankClient &Client : vClients)
                {
                    Total += Client.AccountBalance();
                }

                return Total;
            }

            bool Deposit(float Amount){

                this->_AccountBalance += abs(Amount);
                this->Save();
                return true;
            }
            
             bool Withdraw(float Amount){

                if(Amount >this->_AccountBalance){
                    return false;
                }
                this->_AccountBalance -= abs(Amount);
                this->Save();
                return true;
            }
        };
