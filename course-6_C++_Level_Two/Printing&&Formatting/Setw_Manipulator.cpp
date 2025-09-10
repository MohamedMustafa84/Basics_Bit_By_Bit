#include <iostream>
#include <iomanip> //this Library Stored the setw

using namespace std;


int main(){
    cout << "|------------|-------------------------------|----------|\n";
    cout << "|    Code    |             Name              |    Mark  |\n";
    cout << setw(9) << "c23|" << setw(32) << "Introduction To Programming 1 | " << setw(9) << "95|\n";
    cout << setw(9) << "c23|" << setw(32) << "Computer Hardware | " << setw(9) << "90|\n";
    cout << "|------------|-------------------------------|----------|\n";


    return 0;
}