#include <iostream>
#include "../ClsBankClient.h"
#include "ClsScreen.h"
#include <vector>
#include <iomanip>

using namespace std;

class clsTransferLogScreen : protected clsScreen
{

    static void _PrintTransferLogInfo(clsBankClient::stTransferLogRecord &TransferLogInfo)
    {
        cout << "| " << left << setw(25) << TransferLogInfo.DateTime;
        cout << "| " << left << setw(15) << TransferLogInfo.SourceAccountNumber;
        cout << "| " << left << setw(15) << TransferLogInfo.DestinationAccountNumber;
        cout << "| " << left << setw(15) << TransferLogInfo.Amount;
        cout << "| " << left << setw(15) << TransferLogInfo.srcBalanceAfter;
        cout << "| " << left << setw(15) << TransferLogInfo.desBalanceAfter;
        cout << "| " << left << setw(20) << TransferLogInfo.UserName<<"\n";
    }

public:
    static void ShowTransferLogList()
    {

        vector<clsBankClient::stTransferLogRecord> vTransferLogRecord;
        vTransferLogRecord = clsBankClient::GetTransferLogList();

        int RecordsNumber = vTransferLogRecord.size();

        string Title = "Transfer Log Screen";
        string SubTitle = "\t  (" + to_string(RecordsNumber) + ") Record(s)";

        clsScreen::_DrawScreenHeader(Title ,SubTitle);

        cout << "__________________________________________________________________________________________________________________________\n";
        
        cout << "| " << left << setw(25) << "Date /Time";
        cout << "| " << left << setw(15) << "S.Acct";
        cout << "| " << left << setw(15) << "D.Acct";
        cout << "| " << left << setw(15) << "Amount";
        cout << "| " << left << setw(15) << "S.Balance";
        cout << "| " << left << setw(15) << "D.Balance";
        cout << "| " << left << setw(20) << "User";
        cout << "\n__________________________________________________________________________________________________________________________\n";
        
        if (RecordsNumber == 0){
            cout << "\n\t\t\t No Transfer Available In The System " << endl;
        }else{
            
            for (clsBankClient::stTransferLogRecord &TransferInfo : vTransferLogRecord)
            {
                _PrintTransferLogInfo(TransferInfo);
            }
        }
        cout << "\n__________________________________________________________________________________________________________________________\n";
    }
};
