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

void SplitStringInVector(string Str,vector <string > &vStringItems,string separator)
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
        Str.erase(0, postion +separator.length());
    }
    if (Str != "")
    {
        vStringItems.push_back(Str);
    }
}

void PrintVectorContent(vector <string> &vStringItems){
    for(string &item :vStringItems){
        cout << item << "\n";
    }
}

int main()
{

    // Problem
    // write a program to  read a string then make a function split each word in vector

    vector<string> vStringItems;

    SplitStringInVector(ReadString(),vStringItems," ");

    cout << "Vector Token = " << vStringItems.size();

    cout << "\n vector Content :\n";
     PrintVectorContent(vStringItems);

    return 0;
}