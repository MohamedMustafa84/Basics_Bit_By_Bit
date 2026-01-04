#include <iostream>
#include "../ClsBankUser.h"
#include "ClsScreen.h"
#include <iomanip>

using namespace std;

class clsUsersList : protected clsScreen
{
private:
    static void PrintUserRecordLine(clsUser User)
    {
        cout << "| " << left << setw(20) << User.FullName();
        cout << "| " << left << setw(15) << User.Phone();
        cout << "| " << left << setw(25) << User.Email();
        cout << "| " << left << setw(20) << User.Password();
        cout << "| " << left << setw(20) << to_string(User.Permissions()) << endl;
    }

public:
    static void ShowUsersList()
    {

        vector<clsUser> vUsers;
        vUsers = clsUser::GetUsersList();
        int UsersNumber = vUsers.size();

        string Title = "\t Client List Screen ";
        string SubTitle = "\t (" + to_string(UsersNumber) + ") Client(s)";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << "\n___________________________________________________________________________________________________________________\n";

        cout << "| " << left << setw(15) << "Full Name";
        cout << "| " << left << setw(20) << "Phone";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << "\n___________________________________________________________________________________________________________________\n";

        if (UsersNumber == 0)
        {
            cout << "\n\n\t\t\tNo Users Available in The System !";
        }
        else
        {
            for (clsUser &User : vUsers)
            {
                PrintUserRecordLine(User);
            }
        }
        cout << "\n___________________________________________________________________________________________________________________\n";
    }
};
