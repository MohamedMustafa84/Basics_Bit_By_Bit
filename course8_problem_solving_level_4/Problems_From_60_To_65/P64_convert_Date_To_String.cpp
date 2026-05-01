#include <iostream>
#include "../../DateLib.h"
#include "../../MyLib.h"
using namespace std;



string ConvertDateToString(Date::stDate Date, string delim ="/") {
    return to_string(Date.Day) + delim + to_string(Date.Month) + delim + to_string(Date.Year);
}

    int main()
{
    // problem
    // write a program to read A Date  and convert it to string
    Date::stDate Date = Date::ReadFullDate();
    cout << "\n You Enter : " << ConvertDateToString(Date)<<endl;
    cout << "\n You Enter : " << ConvertDateToString(Date,"-")<<endl;
    cout << "\n You Enter : " << ConvertDateToString(Date,"_")<<endl;

    return 0;
}