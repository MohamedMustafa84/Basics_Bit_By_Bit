#include <iostream>
using namespace std;

int main(){
    
// common mistake with pointers

int X =0,*P;

// wrong !
// P is an address but x is not

// p = X;

// correct !
// P is an address and so is &X
P = &X;


// wrong !
// &X is an address
// *P is the value stored  in &X
// *P = &X;


// correct !
// *P  is the value and so X

*P = X;

return 0;
}