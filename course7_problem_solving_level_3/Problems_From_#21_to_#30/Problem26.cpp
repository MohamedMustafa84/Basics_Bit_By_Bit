#include <iostream>
#include <string>
using namespace std;

string ReadParagraph()
{
    string paragraph;
    cout << "please Enter your Paragraph : ";
    getline(cin, paragraph);
    return paragraph;
}

void upperAllString(string &String)
{
    for (int i = 0; i < String.length(); i++)
    {
        String[i] = toupper(String[i]);
    }
}

void LowerAllString(string &String)
{
    for (int i = 0; i < String.length(); i++)
    {
            String[i] = tolower(String[i]);
    }

}




int main()
{

    // Problem
    // write a program to  Read string then upper all string
    // and the program should lower all string too . 

    string Str = ReadParagraph();

    upperAllString(Str);
    cout << "the string after upper:" << endl;
    cout << Str << endl;

    LowerAllString(Str);
    cout << "the string after Lower:" << endl;
    cout << Str << endl;

    return 0;
}