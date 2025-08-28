#include <iostream>
#include <string>
using namespace std;

string ReadParagraph(){
    string paragraph;
    cout<< "please Enter your Paragraph : ";
    getline(cin,paragraph);
    return paragraph;
}
void PrintFirstLetter(string String){
    
    bool isFirstLetter = true;

    cout << "the first letter of each word in the paragraph :" << endl;

    for (short i = 0; i < String.length(); i++)
    {
        if (String[i] != ' ' && isFirstLetter == true)
        {
            cout << String[i] << endl;
        }

        isFirstLetter = (String[i] == ' ') ? true : false;
    }
}

int main(){
    
    // Problem 
    // write a program to print first letter from each word

   
    PrintFirstLetter(ReadParagraph());

    return 0;
}