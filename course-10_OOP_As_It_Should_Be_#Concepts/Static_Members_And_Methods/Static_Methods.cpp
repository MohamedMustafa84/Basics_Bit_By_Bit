#include <iostream>
using namespace std;

class clsA{
    
    public:
    // Static member is a shared member for all objects of the class
    // Static method can be called without creating an object of the class

    static int function1(){
        return 10;
    }

     int function2()
    {
        return 20;
    }
};


int main(){

    
    cout << "function1 (static) called without object: " << clsA::function1() << endl;
    
    clsA A1;

    cout << "function2 (non-static) called with object A1: " <<
    A1.function2();

    cout <<"\nAnd again function2 (non-static) called with object A1: " <<
    A1.function2();


    return 0;
}