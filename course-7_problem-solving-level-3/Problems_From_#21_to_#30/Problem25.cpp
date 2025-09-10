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
void UpperFirstLetterOfEachWord(string &String)
{
    bool isFirstLetter = true;
    for (short i = 0; i < String.length(); i++)
    {
        if (String[i] != ' ' && isFirstLetter == true)
        {
            String[i] = tolower(String[i]);
        }

        isFirstLetter = (String[i] == ' ') ? true : false;
    }
}

int main()
{

    // Problem
    // write a program to  Read string then Lower the first letter of each word in the string
    string Str = ReadParagraph();

    UpperFirstLetterOfEachWord(Str);
    cout << "the string after Lowercase :" << endl;
    cout << Str << endl;

    return 0;
}