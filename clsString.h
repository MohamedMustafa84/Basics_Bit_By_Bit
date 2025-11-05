#pragma once

#include <iostream>
using namespace std;

class clsString{
    string _Value;
    public :

    clsString(){
        this->_Value = "";
    }

    clsString(string Value){
        _Value = Value;
    }

    void SetValue(string Value){
        _Value = Value;
    }
    string GetValue(){
        return _Value;
    }


//to use the function without the Object we make it static 
// this is general method
    static short CountWords(string S)
    {
        short WordCount = 0;
        string delim = " ";
        short postion = 0;
        string sWord;
        while ((postion = S.find(delim)) != string::npos)
        {
            sWord = S.substr(0, postion);
            if (sWord != "")
            {
                WordCount++;
            }
            S.erase(0, postion + delim.length());
        }
        if (S != "")
        {
            WordCount++;
        }
        return WordCount;
    }
// for the object
    short CountWords(){
        return CountWords(_Value);
    }
};