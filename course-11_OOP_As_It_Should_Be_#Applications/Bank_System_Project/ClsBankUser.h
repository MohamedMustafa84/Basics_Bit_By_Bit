#pragma once

#include <iostream>
#include <vector>
#include "../../Libs/clsString.h" 
#include "ClsPerson.h"
#include <cmath>
#include <fstream>


class clsUser:public clsPerson{

    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode=2
    };

    enMode _Mode;
    
    
    string _UserName = "";
    string _Password = "";
    int  _Permissions =0;
    bool _MarkForDelete = false;

    static clsUser _ConvertLineToUserObject(string Line, string separator = "#//#")
    {
        vector<string> vUserData = clsString::Split(Line, separator);

        // Validate record integrity
        if (vUserData.size() != 7)
        {
            return _GetEmptyUserObject();
        }


        return clsUser(
            enMode::UpdateMode,
            vUserData[0], // FirstName
            vUserData[1], // LastName
            vUserData[2], // Email
            vUserData[3], // Phone
            vUserData[4], // UserName
            vUserData[5], // Password
            stoi(vUserData[6])); // Permissions
    }

    static clsUser _GetEmptyUserObject(){
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

        static string  _ConvertUserObjectToLine(clsUser &User,string Separator="#//#" ){

            string UserRecord = "";

            UserRecord += User.FirstName() + Separator;
            UserRecord += User.LastName() + Separator;
            UserRecord += User.Email() + Separator;
            UserRecord += User.Phone() + Separator;
            UserRecord += User.UserName() + Separator;
            UserRecord += User.Password() + Separator;
            UserRecord += to_string(User.Permissions());

            return UserRecord;
        }

        static vector <clsUser> _LoadUsersDataFromFile(string FilePath="../Users.txt"){
            vector<clsUser> vUsers;

            fstream UsersFile;

            UsersFile.open(FilePath, ios::in);

            if (UsersFile.is_open()){
                string Line;

                while(getline(UsersFile,Line)){

                    clsUser User = _ConvertLineToUserObject(Line);
                    if (!User.IsEmpty())
                    {
                        vUsers.push_back(User);
                    }
                }

                UsersFile.close();
            }
            return vUsers;
        }

        static void _SaveUsersDataToFile(vector<clsUser> vUsers, string FilePath = "../Users.txt")
        {

            fstream UsersFile;
            UsersFile.open(FilePath, ios::out); //overwrite

            string DataLine;

            if (UsersFile.is_open())
            {

                for (clsUser &UserObject: vUsers)
                {

                    if(UserObject._MarkForDelete){
                        continue;
                    }
                    DataLine = _ConvertUserObjectToLine(UserObject);

                    UsersFile << DataLine<<endl;
                }

                UsersFile.close();
            }
        }

        void _Update(){
            vector<clsUser> _vUsers;
            _vUsers = _LoadUsersDataFromFile();

            for (clsUser &User :_vUsers){

                if(User.UserName() == UserName()){
                    *this = User;
                    break;
                }
            }

            _SaveUsersDataToFile(_vUsers);
        }



        void _AddNewClient(){
           _AddDataLineToFile (_ConvertUserObjectToLine(*this));
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
            clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
                : clsPerson(FirstName, LastName, Email, Phone)
            {

                _Mode = Mode;
                _UserName = UserName;
                _Password = Password;
                _Permissions = Permissions;

            }

            bool IsEmpty()
            {
                return (_Mode == enMode::EmptyMode);
            }

            string UserName()
            {
                return _UserName;
            }
            void SetUserName(string UserName)
            {
                _UserName = UserName;
            }

            string Password()
            {
                return _Password;
            }
            void SetPassword(string Password)
            {
                _Password = Password;
            }
            int Permissions()
            {
                return _Permissions;
            }
            void SetPermissions(int Permissions)
            {
                _Permissions = Permissions;
            }

            bool MarkedForDelete()
            {
                return _MarkForDelete;
            }

            void Print()
            {
                cout << "\n User Card ";
                cout << "\n-----------------------------------";
                cout << "\nFull Name      : " << FullName();
                cout << "\nEmail          : " << Email();
                cout << "\n Phone         : " << Phone();
                cout << "\nPassword       : " << _Password;
                cout << "\n Permissions   : " << _Permissions;
                cout << "\n-----------------------------------\n";
            }

            static clsUser Find(string UserName)
            {

                vector<clsUser> vUsers;

                fstream UsersFile;

                UsersFile.open("../Users.txt", ios::in);
                if (UsersFile.is_open())
                {

                    string Line;

                    while (getline(UsersFile, Line))
                    {
                        clsUser User = _ConvertLineToUserObject(Line);
                        if (User.UserName() == UserName)
                        {
                            UsersFile.close();
                            return User;
                        }
                        vUsers.push_back(User);
                    }

                    UsersFile.close();
                }
                return _GetEmptyUserObject();
            }

            static clsUser Find(string UserName, string Password)
            {

                vector<clsUser> vUsers;

                fstream UsersFile;

                UsersFile.open("../Users.txt", ios::in);
                if (UsersFile.is_open())
                {

                    string Line;

                    while (getline(UsersFile, Line))
                    {
                        clsUser User = _ConvertLineToUserObject(Line);
                        if (User.UserName() == UserName && User.Password() == Password)
                        {
                            UsersFile.close();
                            return User;
                        }
                        vUsers.push_back(User);
                    }

                    UsersFile.close();
                }
                return _GetEmptyUserObject();
            }

            static bool IsUserExist(string UserName)
            {
                clsUser User = clsUser::Find(UserName);
                return (!User.IsEmpty());
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
                    if (clsUser::IsUserExist(_UserName))
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
            static clsUser GetAddNewUserObject(string UserName)
            {
                return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
            }



            bool Delete(){
                vector<clsUser> vUsers;
                bool Deleted = false;

                vUsers= _LoadUsersDataFromFile("../Users.txt");


                    for (clsUser &User :vUsers ){

                        if(User._UserName == _UserName){
                            User._MarkForDelete = true;
                            Deleted = true;
                            break;
                        }
                    }

                    _SaveUsersDataToFile(vUsers);

                    *this = _GetEmptyUserObject();

                    return Deleted;
            }

            static vector <clsUser> GetUsersList(){
                return _LoadUsersDataFromFile("../Users.txt");
            }

        };
