#include <iostream>
using namespace std;

union unMyUnion{
    short shortValue;
    int IntValue;
    float FloatValue;
    char CharValue;
};

int main(){

    // all the Union member store in the same location in the memory

    // the size of the union in the memory is the size of the biggest member in this 
    // case the size of the floating point value

    unMyUnion MyUnion;

    MyUnion.IntValue = 309098;
    cout << "Integer value : " << MyUnion.IntValue << endl;
    
    MyUnion.CharValue= 'Y';
    cout << "character value : " << MyUnion.CharValue << endl;

    MyUnion.shortValue = 32;
    cout << "short integer value : " << MyUnion.shortValue << endl;

    MyUnion.FloatValue = 32.02f;
    cout << "Floating point value : " << MyUnion.FloatValue << endl;
    return 0;
}
