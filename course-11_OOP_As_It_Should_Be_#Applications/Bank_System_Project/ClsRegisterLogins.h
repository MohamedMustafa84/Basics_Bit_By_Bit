#pragma once 
#include <iostream>
#include <fstream>
#include <vector>
#include  "ClsGlobal.h"
#include "../../Libs/ClsDate.h"
#include "../../Libs/ClsUtil.h"

using namespace std;


class clsRegisterLogins{

    

    static string _PrepareLoginRecord( string Separator = "#//#")
    {

        string UserLoginInfoRecord = "";

        UserLoginInfoRecord+= clsDate::GetSystemDateTimeString()+ Separator;
        UserLoginInfoRecord+= CurrentUser.UserName() + Separator;
        UserLoginInfoRecord += clsUtil::EncryptText(CurrentUser.Password()) + Separator;
        UserLoginInfoRecord += to_string(CurrentUser.Permissions());

        return UserLoginInfoRecord;
    }

  
    public :
        struct _stLoginInfo
        {
            string DateAndTime = "";
            string UserName = "";
            string Password = "";
            string Permission = "";
        };

          static _stLoginInfo ConvertLineToLoginInfoObject(string Line, string separator = "#//#")
    {
        vector<string> vUserLoginsInfo = clsString::Split(Line, separator);

        _stLoginInfo stLoginInfoRecord;

        stLoginInfoRecord.DateAndTime = vUserLoginsInfo[0];
        stLoginInfoRecord.UserName = vUserLoginsInfo[1];
        stLoginInfoRecord.Password = clsUtil::DecryptText(vUserLoginsInfo[2]);
        stLoginInfoRecord.Permission = vUserLoginsInfo[3];

        return stLoginInfoRecord;
    }

    static bool RegisterUserLoginInfo(string FilePath = "UsersLoginInfo.txt")
    {
        fstream LogsFile;

        LogsFile.open(FilePath, ios::out | ios::app);

        if (LogsFile.is_open())
        {

            LogsFile <<_PrepareLoginRecord() << endl;

            LogsFile.close();
        }
        return true;
    }

    static vector<_stLoginInfo> GetUsersLoginsData(string FilePath ="UsersLoginInfo.txt")
    {
        vector<_stLoginInfo> stUsersRegisteringInfo;

        fstream LoginsLogFile;

        LoginsLogFile.open(FilePath, ios::in);

        if (LoginsLogFile.is_open())
        {
            string Line;

            while (getline(LoginsLogFile, Line))
            {

                _stLoginInfo UserLoginInfo = ConvertLineToLoginInfoObject(Line);
                
                stUsersRegisteringInfo.push_back(UserLoginInfo);

            }

            LoginsLogFile.close();
        }
        return stUsersRegisteringInfo;
    }
};