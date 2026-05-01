#include <iostream>
using namespace std;

int main(){
    
    int arr[4]={10,20,30,40};
    int *ptr;

    ptr = arr; //arr is the address of the first element at the Array

    // ptr is equivalent to &arr[0]
    //ptr +1 is equivalent to &arr[1]
    // and so on

    cout << "Addresses are :\n";
    cout << ptr << endl;
    cout << ptr +1 << endl;
    cout << ptr+2 << endl;
    cout << ptr+3 << endl;

    cout << "\nValue are :\n";
    cout << *ptr << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;
    cout << *(ptr + 3) << endl;

    return 0;
}