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

// ----- solution1 ------

string trimLeft(string Str){
    short startPosition = 0;
    for(short i=0; i<Str.length(); i++){
        if(Str[i]!=' '){
            startPosition = i;
            break;
        }
    }

    return Str.substr(startPosition, Str.length());
}

string trimRight(string Str)
{
    short endPosition = 0;
    for (short i = Str.length(); i > 0; i--)
    {
        if (Str[i] != ' ')
        {
            endPosition = i;
            break;
        }
    }

    return Str.substr(0,endPosition);
}

string trimAll(string Str)
{
    Str= trimLeft(Str);
    Str =trimRight(Str);

    return Str;
}

// ------- solution2 ----

string trim_Left(string Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ')
        {
            return Str.substr(i, Str.length());
            
        }
    }
    return "";
}

string trim_Right(string Str)
{
    for (short i = Str.length(); i > 0; i--)
    {
        if (Str[i] != ' ')
        {
            return Str.substr(0, i+1);
        }
    }
    return "";
}

string trim_All(string Str)
{
    

    return (trim_Right(trim_Left(Str)));
}

    int
    main()
{

    // Problem
    // write a program to  read a string then trim left ,trim right , trim all


    
    string Str = ReadString();

    // ------- solution1 ----
    
    cout << "Trim Left :" << trimLeft(Str)<<endl;
    cout << "Trim right :" << trimRight(Str)<<endl;
    cout << "Trim All:" << trimAll(Str)<<endl;
    
    
    // ------- solution2 ----
    cout << "Trim Left :" << trim_Left(Str) << endl;
    cout << "Trim right :" << trim_Right(Str) << endl;
    cout << "Trim All:" << trim_All(Str) << endl;

    return 0;
}