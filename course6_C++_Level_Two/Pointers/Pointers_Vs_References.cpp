#include <iostream>
using namespace std;



int main(){

    // deferent between a pointer and reference

    int a = 10;
    int &x = a;

    // the reference  is just alias to the variable 
    // with reference we dont create a new location at Memory
    //  when you a signed the reference to specific variable you will be unable to change this variable during the run time 

    cout << &a << endl;
    cout << &x << endl;

    int c = 20;
    // &x = c;  error coz the x should a signed to a only

    // the pointer are just  a variable contain address 
    // with pointer we create a new slot in the memory 
    // with the pointer you can change the asigend variable during the run time easily

    int *p = &a;

    cout << p << endl;
    cout << *p << endl;

    int b = 20;
    p = &b;

    cout << p << endl;
    cout <<*p << endl;

    return 0;
}