#include <iostream>
#include "../../DateLib.h"
#include "../../MyLib.h"
using namespace std;

string Replace_Word_In_String(string Str, string StringToReplace, string StrReplaceTo)
{

    int position = Str.find(StringToReplace);

    while (position != std::string::npos)
    {
        Str.replace(position, StringToReplace.length(), StrReplaceTo);
        position = Str.find(StringToReplace);
    }

    return Str;
}

string Format_Date(Date::stDate stDate , string DateFormat = "dd/mm/yyyy"){

    string formattedDate = "";

    formattedDate = Replace_Word_In_String(DateFormat, "dd",to_string(stDate.Day) );
    formattedDate = Replace_Word_In_String(formattedDate, "mm", to_string(stDate.Month));
    formattedDate = Replace_Word_In_String(formattedDate, "yyyy", to_string(stDate.Year));

    return formattedDate;
}

int main(){

    // problem 
    // write a function to formate the date  by taking two parameter Date  and Date formate

    Date::stDate stDate = Date::ReadFullDate();

    cout << Format_Date(stDate, "dd-mm-yyyy")<<endl;
    cout << Format_Date(stDate)<<endl;
    cout << Format_Date(stDate,"yyyy/mm/dd")<<endl;
    cout << Format_Date(stDate,"mm,yyyy,dd")<<endl;
    cout << Format_Date(stDate,"dd_yyyy_mm")<<endl;
    cout << Format_Date(stDate,"dd$mm$yyyy")<<endl;
    cout << Format_Date(stDate,"yyyy-dd-mm")<<endl;

    return 0;
}