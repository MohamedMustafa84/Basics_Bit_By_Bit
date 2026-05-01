#include <iostream>
using namespace std;
// Dynamic Memory Allocation :new and delete


int main(){
    
    // declare an int pointer
    int *ptrX;
    
    // declare a float  pointer
    float *ptrY;

    // Dynamically Allocation Memory
    // we Declare a variable in the run time besed of specific needs
    ptrX = new int;
    ptrY = new float;

    // assigning  value to the memory
    *ptrX = 55;
    *ptrY = 12.33f;

    cout << *ptrX << endl;
    cout << *ptrY<< endl;

    // deallocate the memory
    // delete memory make the program faster 
    delete ptrX;
    delete ptrY;

    return 0;

}