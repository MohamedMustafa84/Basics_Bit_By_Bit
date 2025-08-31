#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string Str;
    cout << "Please enter you String :" << endl;
    getline(cin, Str);
    return Str;
}

void SplitStringInVector(string Str, vector<string> &vStringItems, string separator)
{
    short postion = 0;
    string sWord;
    while ((postion = Str.find(separator)) != string::npos)
    {
        sWord = Str.substr(0, postion);
        if (sWord != "")
        {
            vStringItems.push_back(sWord);
        }
        Str.erase(0, postion + separator.length());
    }
    if (Str != "")
    {
        vStringItems.push_back(sWord);
    }
}

string JoinVectorContent(vector<string> & vectorItems, string separator)
{
    string JoinedString="";
    for (string &word: vectorItems){
        JoinedString += (word + separator);
    }

    return JoinedString.substr(0, JoinedString.length() - separator.length());
}

void PrintVectorContent(vector<string> &vStringItems)
{
    for (string &item : vStringItems)
    {
        cout << item << "\n";
    }
}
    int main()
    {

        // Problem
        // write a program to to join vector fo string into a one String with separators

        vector<string> vStringItems;

        SplitStringInVector(ReadString(), vStringItems, " ");

        cout << "Vector Token = " << vStringItems.size();

        cout << "\n vector Content :\n";
        PrintVectorContent(vStringItems);

        cout << "\n vector after join :\n";
        cout << JoinVectorContent(vStringItems, "#") << endl;

        return 0;
    }