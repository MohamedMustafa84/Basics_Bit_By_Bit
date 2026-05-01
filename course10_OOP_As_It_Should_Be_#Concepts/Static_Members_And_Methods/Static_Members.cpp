#include <iostream>
using namespace std;

class clsA{
    
    public:
    int var;
    // Static member is a shared member for all objects of the class
    static int ObjectsCounter;
    clsA(){
        ObjectsCounter++;
    }

    void print(){
        cout << "\nvar : " << var;
        cout << "this class has " << ObjectsCounter << " Objects " << endl;
    }
};

int clsA::ObjectsCounter = 0; //you should define and initialize static members outside the class

int main(){
    clsA A1, A2, A3;

    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    A1.print();
    A2.print();
    A3.print();
    A1.ObjectsCounter = 100;
    
    cout <<"After changing ObjectsCounter using One Object: " << endl;
    A1.print();
    A2.print();
    A3.print();

    return 0;
}