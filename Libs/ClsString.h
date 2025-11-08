#pragma once 

#include <iostream>
#include <vector>
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

    static short Length(string Str){
        return Str.length();
    }

    short Length(){
        return _Value.length();
    }

    static string UpperFirstLetterOfEachWord(string Str)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < Str.length(); i++)
        {
            if (Str[i] != ' ' && isFirstLetter == true)
            {
                Str[i] = toupper(Str[i]);
            }

            isFirstLetter = (Str[i] == ' ') ? true : false;
        }
        return Str;
    }

    void  UpperFirstLetterOfEachWord(){
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string  UpperAllString(string Str)
    {
        for (int i = 0; i < Str.length(); i++)
        {
            Str[i] = toupper(Str[i]);
        }
        return Str;
    }

    void UpperAllString(){
        _Value = UpperAllString(_Value);
    }

    static  string  LowerAllString(string Str)
    {
        for (int i = 0; i < Str.length(); i++)
        {
            Str[i] = tolower(Str[i]);
        }
        return Str;
    }

    void LowerAllString(){
        _Value = LowerAllString(_Value);
    }

    static char invertLetterCase(char Character)
    {

        return isupper(Character) ? tolower(Character) : toupper(Character);
    }

    static string invertAllStringCase(string str)
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            str[i] = invertLetterCase(str[i]);
        }
        return str;
    }

    void invertAllStringCase(){
        _Value = invertAllStringCase(_Value);
    }

    enum enWhatToCount
    {
        CapitalLetters = 1,
        SmallLetters = 2,
        All = 3
    };

    static  short countLetters(string Str, enWhatToCount countType)
    {
        if (countType == enWhatToCount::All)
        {
            return (short)Str.length();
        }

        short counter = 0;
        for (size_t i = 0; i < Str.length(); i++)
        {
            if (countType == enWhatToCount::CapitalLetters && isupper(Str[i]))
                counter++;

            if (countType == enWhatToCount::SmallLetters && islower(Str[i]))
                counter++;
        }
        return counter;
    }

    static bool isVowel(char Char)
    {
        Char = tolower(Char);
        return (Char == 'a' || Char == 'e' || Char == 'i' || Char == 'o' || Char == 'u');
    }

    static short CountVowels(string Str)
    {
        short vowelCount = 0;
        for (short i = 0; i < Str.length(); i++)
        {
            if (isVowel(Str[i]))
            {
                vowelCount++;
            }
        }
        return vowelCount;
    }

    short CountVowels(){
        return CountVowels(_Value);
    }

    static vector<string> split(string Str, string delim)
    {
        vector<string> vString;

        int position = 0;
        string Word = "";

        while ((position = Str.find(delim)) != string::npos)
        {
            Word = Str.substr(0, position);

            if (Word != "")
            {
                vString.push_back(Word);
            }
            Str.erase(0, position + delim.length());
        }
        if (Str != "")
        {
            vString.push_back(Str);
        }

        return vString;
    }

    vector<string> split( string delim){
        return split(_Value, delim);
    }

    static string TrimLeft(string Str)
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

    string TrimLeft(){
        return TrimLeft(_Value);
    }

    static string TrimRight(string Str)
    {
        for (short i = Str.length(); i > 0; i--)
        {
            if (Str[i] != ' ')
            {
                return Str.substr(0, i + 1);
            }
        }
        return "";
    }

    string TrimRight(){
        return TrimRight(_Value);
    }

    static string Trim(string Str)
    {

        return (TrimRight(TrimLeft(Str)));
    }

    string Trim(){
        return Trim(_Value);
    }

    static string JoinString(vector<string> &vectorItems, string separator)
    {
        string JoinedString = "";
        for (string &word : vectorItems)
        {
            JoinedString += (word + separator);
        }

        return JoinedString.substr(0, JoinedString.length() - separator.length());
    }

    static string JoinString(string arrItems[], short length, string separator)
    {
        string JoinedString = "";
        for (short i = 0; i < length; i++)
        {
            JoinedString += (arrItems[i] + separator);
        }

        return JoinedString.substr(0, JoinedString.length() - separator.length());
    }

    static string ReplaceWord(string Str, string StrToReplace, string StrReplaceTo)
    {

        int position = Str.find(StrToReplace);

        while (position != std::string::npos)
        {
            Str.replace(position, StrToReplace.length(), StrReplaceTo);
            position = Str.find(StrToReplace);
        }

        return Str;
    }



    string ReplaceWord( string StrToReplace, string StrReplaceTo){
        return ReplaceWord(_Value, StrToReplace, StrReplaceTo);
    }
};