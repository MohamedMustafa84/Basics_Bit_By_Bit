#include <iostream>
using namespace std;

int main(){

    int *ptr;

    float f1 = 10.5;
    string S1 = "";

    // ptr = &f1;  error coz the pointer type is int and the f1 is float

    // when you dont know the variable type or when you want to change pointer to point on deferent type while run time  we create  pointer point to void

    void *Ptr;

    float F2 = 10.1;

    Ptr = &F2;

    int a = 10;

    Ptr = &a;
    cout <<"the address "<< ptr << endl;

    // when you need to grab the pointer value you need to make a casting 
    // *(static_cast<Type*>(pointerName))
    
    cout << *(static_cast<float *>(Ptr)) << endl;
    

    Ptr = &S1;

    cout <<"the address "<< ptr << endl;

    cout <<"the value "<< *(static_cast<string*>(Ptr)) << endl;


    return 0;
}