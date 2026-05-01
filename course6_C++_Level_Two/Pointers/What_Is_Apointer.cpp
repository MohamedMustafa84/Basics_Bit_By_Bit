#include <iostream>
using namespace std;

int main(){
    cout << "Pointers:" << endl;
    cout << "using the Pointers give you full access to Memory" << endl;
    cout << "Only C and C++ allow to you to use the pointers " << endl;

    int a = 10;
    int b = 20;

    cout << "a value is " << a << endl;
    cout <<" a address in Memory is "<< &a <<endl;

    // the pointer is just a variable contain the address of the thing (variable, Array,Pointer, function,...) in the Memory

    // syntax
    // PointerType *pPointerName= &(the thing that pointer point to )
    // it Recommend to start Pointer name with p
    int *pMyFirstPointer = &a;

    // pointer only contain the Address
    // pMyFirstPointer =10; it will throw an error

    // pointer benefits : with Pinter  give you shortcuts to access any thing in Memory from any where and make the program faster

    cout << "Pointer value :" << pMyFirstPointer << endl;
    
    // you can easily change the pointer direction int hte run time
    
    pMyFirstPointer = &b;
    cout << " b Pointer value :" << pMyFirstPointer << endl;

    return 0;
}