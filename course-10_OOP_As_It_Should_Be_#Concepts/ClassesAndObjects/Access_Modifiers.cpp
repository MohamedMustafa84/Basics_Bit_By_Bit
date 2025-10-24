#include <iostream>
using namespace std;

class clsPerson
{

    private:

    // this private and will not be accessed from outside the class
    // for internal use only
    int Variable1=5;
    int function1(){
        return 50;
    }

    protected :
    // Only accessable inside this class and all classes inherits this class 
    int variable2=20;
    int function2(){
        return 70;
    }


    public:
    // accessable  for Everyone ouside/and inside and classes inherits

    string firstName = "";
    string LastName = "";
    string fullName()
    {
        firstName + " " + LastName;
    }
    float function3(){
        return function1() + function2() + function3();
    }
};

int main()
{ 

    clsPerson person1;

    person1.firstName = "Mohamed";
    person1.LastName = "Mustafa";
    cout << person1.fullName()<<endl;
    cout << person1.function3();

    return 0;
}