#include <iostream>
using namespace std;

struct stEmployee{
    string Name = "";
    double Salary = 0.0;
};

int main(){

    stEmployee Employee1;
    stEmployee *ptr; // declare pointer of struct

    Employee1.Name = "Mohamed Mustafa";
    Employee1.Salary = 1000.00;

    cout << "Employee Name : " << Employee1.Name << endl;
    cout << "Salary : " << Employee1.Salary << endl;

    ptr = &Employee1;

    cout << "Using Pointer\n";
    cout << ptr->Name << endl;
    cout << ptr->Salary << endl;

    cout <<"\n the addresses of the struct \n\n";
    cout << "\n\n"<< ptr << endl;
    cout<<&Employee1<< endl;
    cout << &Employee1.Name << endl;

    cout << "The Addresses OF struc by pointer \n\n";
    cout << &ptr->Name << endl;
    cout << &ptr->Salary << endl;

    return 0;
}