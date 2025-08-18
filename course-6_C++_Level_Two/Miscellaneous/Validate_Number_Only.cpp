#include <iostream>
#include <limits> 
using namespace std;


// Validate Number Only
int ReadNumber(){
    int Number;
    cout << "Please Enter A Number ? ";
    cin >> Number;
    while (cin.fail())
    {
        // user didnot input a number
        cin.clear(); //forgive me on that error
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input buffer

        cout << "Invalid Number , Enter A Valid One:" << endl;
        cin >> Number;
    }
    return Number;
}


int main(){

    cout << "Your Number is :" << ReadNumber();
    return 0;
}