#include <iostream>
using namespace std;


void swapNumbers(int &a,int&b){
    int temp=a;
    a = b;
    b = temp;
}

// we use * to change the value
void swapUsingPointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a, b;

    cout <<"Before swap "<<endl;
    cout <<a<<endl;
    cout <<b<<endl;
    
    swapNumbers(a, b);
    cout <<"After swap "<<endl;
    cout << a << endl;
    cout << b << endl;

// swap using Pointer

    // we send the address 
    swapUsingPointer(&a, &b);

    cout << "After swap using Pointer " << endl;
    cout << a << endl;                             
    cout << b << endl;

    // the deferent between byRef and pointer 
    // by ref just an alias to the variable 
    // pointer allow you to change the value during run time 

    return 0;
}