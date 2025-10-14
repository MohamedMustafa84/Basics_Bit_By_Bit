#include <iostream>
#include "../../DateLib.h"
#include "../../MyLib.h"
#include <vector>
using namespace std;


Date::stDate ConvertStringToDate(string StringDate){

    Date::stDate stDate;

    vector <string> vDate = String::splitString(StringDate, "/");

    stDate.Day = stoi(vDate[0]);
    stDate.Month = stoi(vDate[1]);
    stDate.Year = stoi(vDate[2]);

    return stDate;
}

int main()
{
    // problem
    // write a program to read String and convert it to Date
    Date::stDate Date;

    string StringDate = UserInputs::ReadString("Please Enter A Date As Following dd/mm/yyyy : ");

    Date = ConvertStringToDate(StringDate);
    cout << "\n Day : " << Date.Day;
    cout << "\n Month : " << Date.Month;
    cout << "\n Year : " << Date.Year;

    cout << "\n You Enter : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return 0;
}