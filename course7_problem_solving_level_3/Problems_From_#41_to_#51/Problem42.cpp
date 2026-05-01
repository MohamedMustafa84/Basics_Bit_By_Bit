#include <iostream>
#include <string>
#include <vector>
#include "../MyLib.h"
using namespace std;



string Replace_Word_In_String(string Str, string StringToReplace, string StrReplaceTo){

    int position = Str.find(StringToReplace);

    while(position != std::string::npos){
        Str.replace(position, StringToReplace.length(), StrReplaceTo);
        position = Str.find(StringToReplace);
    }

    return Str;
}

    int main()
{

    // Problem
    // write a program to  replace word in string using C++ function 

    string Str = UserInputs::ReadString("please Enter Your String: ");
   
    
    cout <<"String after Replace :\n"<<Replace_Word_In_String(Str,"mohamed","ahmed") << endl;
    

    return 0;
}