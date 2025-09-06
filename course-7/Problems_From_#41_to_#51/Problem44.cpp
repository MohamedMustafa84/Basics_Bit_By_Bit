#include <iostream>
#include <vector>
#include "../MyLib.h"
using namespace std; 


string removeStringPunctuations(string Str){
    string S2 = "";
    for (short i = 0; i < Str.length();i++){
        if (!ispunct(Str[i])){
            S2 += Str[i];
        }
    }
    return S2;
}



int main(){
    
    //  write a program to remove all punctuations from a string

    string Str = UserInputs::ReadString("please enter your string :");


    cout << " Punctuations Removed : \n";
    cout << removeStringPunctuations(Str);

    return 0;
}