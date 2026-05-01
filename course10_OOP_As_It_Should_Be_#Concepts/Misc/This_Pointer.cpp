#include <iostream>
using namespace std; 

class clsEmployee{
    public :
    int ID=21333;
    string Name="Mohamed mustafa ";
    float salary=23049;

    clsEmployee(int ID, string Name, float salary){
        // We use this Keyword To Make A difference between the class members and none class members
        this->ID = ID;
        this->Name=Name;
        this->salary = salary;
    }

     void print()
    {
        // we use th is keyword to Access Any class member ( except the friend Classes And Friend Functions Coz The Are Not A class Members) put the compiler write it automatically
        // now we can write it not 
        cout << "full Name : " << this->Name << endl;
        cout << "ID        : " << this->ID << endl;
        cout << "Salary    : " << this->salary << endl;
    }

    static void func1(clsEmployee Employee){
        Employee.print();
    }

    void func2(){
        // we send the value of this object as a parameter
        func1(*this);
    }
};

int main(){
    clsEmployee Employee1(12212,"Ahmed ",233.23);
    Employee1.func2( );

    return 0;
}