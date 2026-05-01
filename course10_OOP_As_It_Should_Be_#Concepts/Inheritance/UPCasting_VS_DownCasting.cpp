#include <iostream>
using namespace std;

// upcasting and downcasting 

class clsPerson{
    public :
        string FullName = "Mohamed mustafa ";
};

class clsEmployee :public clsPerson{
    public :

        string Title= "Web Developer";
};


int main(){

    clsEmployee Employee1;
    cout << "full Name :" << Employee1.FullName << endl;
    
    // Upcasting
    // from the Base class you can create A pointer to point to any Derive class  
    clsPerson * Person1=&Employee1;

    cout << "Full Name " << Person1->FullName << endl;

    // Down casting
    // you can not make the derive class point to the base class 
    // you can not do Dawn casting because the Class Employee has members not exist in the class person 



    // clsPerson Person1;

    // clsEmployee *Employee = &Person1;

    return 0;

}