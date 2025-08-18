#pragma warning(disable : 4996) // to remove the warning message 

#include <ctime> //this  laibrary is a C  laibrary
#include <iostream>
 using namespace std;


 int main(){

    time_t TimeNow = time(0);//time Now is the current time in seconds since 1/1/1970
    char *dt = ctime(&TimeNow); //convert the time to string

    cout << "local date and time is :" << dt << "\n";

    tm *gmtn = gmtime(&TimeNow); //convert the time to UTC

    // gmtn is a pointer to a tm structure that contains the UTC time
    cout << "UTC date and time is :" << asctime(gmtn) << "\n"; // convert the UTC time to string

    cout << "UTC date and time is :" << dt << "\n"; //print the UTC time as string

    return 0;
 }
