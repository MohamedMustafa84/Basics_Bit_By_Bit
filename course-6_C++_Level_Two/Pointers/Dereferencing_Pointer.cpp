#include <iostream>
using namespace std;

int main(){
   int  a=10;

   cout << "variable value" << a << endl;
   cout << "variable address " << &a << endl;

   int *p;
   p = &a;

   cout << "Pointer value is " << p << endl;

// to access a value using pointer we use *p  it like you say go to the address p in the Memory
//  and take with you the key  * Open the Box and grab the value in it
   cout << "the value that pointer pointing to is " << *p;
   
   // change variable value using Pointer
   
   *p = 20;
   cout << "the value that pointer pointing to is " << *p;
   cout << "a value " << a << endl;

   a = 30;
   cout << a << endl;
   cout <<*p << endl;

   cout << p << endl;

   return 0;
}