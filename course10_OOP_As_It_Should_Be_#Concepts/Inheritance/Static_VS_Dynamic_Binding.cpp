#include <iostream>
using namespace std;

class clsPerson
{
public:
    
    virtual void print()
    {
        cout << "Hi Iam A Person " << endl;
    }
};

class clsEmployee : public clsPerson
{

public:
    void print()
    {
        cout << "Hi Iam An Employee " << endl;
    }
};

class clsStudent : public clsPerson
{

public:
    void print()
    {
        cout << "Hi Iam A Student  " << endl;
    }
};

int main()
{

// Static/Early Binding VS Dynamic/Late Binding 


    clsEmployee Employee1;
    clsStudent Student1;
    // Static/Early Binding
    // the Compiler Already Know the Address of the Print Function (Employee print Function and Student Print Function)


    Employee1.print();
    Student1.print();



    // Dynamic/Late Binding 
    // The Compiler Will Know The Addresses Of The Print Functions In The Run Time By The Pointer
    
    clsPerson *Person1 = &Employee1;
    clsPerson *Person2 = &Student1;

    Person1->print();
    Person2->print();

    return 0;
}