#include <iostream>
using namespace std;

// static variable


    void
    MyFunction()
{
    static int Number = 1;
    cout << "MY Number Value is " << Number << endl;
    Number++;
}


int main(){
    MyFunction();
    MyFunction();
    MyFunction();
    MyFunction();
    return 0;
}