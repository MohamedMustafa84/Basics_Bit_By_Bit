#include <iostream>
#include <string>
#include <vector>
using namespace std;



string JoinString(vector<string> &vectorItems, string separator)
{
    string JoinedString="";
    for (string &word: vectorItems){
        JoinedString += (word + separator);
    }

    return JoinedString.substr(0, JoinedString.length() - separator.length());
}

string JoinString( string arrItems[],short length, string separator)
{
    string JoinedString = "";
    for (short i = 0; i<length;i++)
    {
        JoinedString += (arrItems[i]+ separator);
    }

    return JoinedString.substr(0, JoinedString.length() - separator.length());
}

    int main()
    {

        // Problem
        // write a program to to join vector fo string into a one String with separators

        vector<string> vStringItems = {"mohamed", "ahmed", "Ali", "osman"};

        string arrItems[] = {"mohamed", "ahmed", "Ali", "osman"};



        cout << "\n vector after join :\n";
        cout << JoinString(vStringItems, "#") << endl;

        cout << "\n Array after join :\n";
        cout << JoinString(arrItems,4, "_") << endl;

        return 0;
    }