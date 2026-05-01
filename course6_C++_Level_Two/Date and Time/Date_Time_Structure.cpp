#pragma Waring (disable:4996)  
#include <ctime> //this library is a C library
#include <iostream> 
using namespace std;

/*
     int  tn_sec ;//seconds of minutes from 0 to 59
    int  tn_min ;//minutes of hours from 0 to 59
    int  tn_hour ;//hours of day from 0 to 23
    int  tn_mday ;//day of month from 1 to 31
    int  tn_mon ;//months of year from 0 to 11
    int  tn_year ;//years since 1900
    int  tn_wday ;//days since Sunday from 0 to 6
    int  tn_yday ;//days since January 1 from 0 to 365
    int  tn_isdst ;//daylight saving time flag

    */

int main(){
    
    time_t TimeNow = time(0); //time Now is the current time in seconds since 1/1/1970

    tm *now = localtime(&TimeNow);

    cout << "year : " << now->tm_year + 1900 << endl;
    cout << "Month : " << now->tm_mon + 1 << endl;
    cout << "Day : " << now->tm_mday << endl;
    cout << "Hour : " << now->tm_hour << endl;
    cout << "Min : " << now->tm_min << endl;
    cout <<"Second : "<<now->tm_sec <<endl;

    cout << "Week Day (day since sunday ) : " << now->tm_wday << endl;
    cout << "year day (day since jan 1st ) : " << now->tm_yday << endl;
    cout <<" hours of daylight saving time"<< now->tm_isdst << endl;

    return 0;
}