#include <iostream>
using namespace std;

// --- Visibility Mode -------

//Base Class

class clsA{
    int _A;
    protected :
        int _ProtectedNum = 10;
    public:
        string PublicString = "iam a public variable from the base class ";
};

// Public Mode 
// in the mode you Can Access baseClass public and protected members 

class clsB :public clsA{
    int _B=20;
    void PrintPublicString(){
        cout << clsA::PublicString<<endl;

    }
    void printProtectedNum(){
        cout << "the Base class Protected Number is ";
        cout << clsA::_ProtectedNum << endl;
    }
    // you connot access base class private members
};

// Private Mode 
//in this Mode  the public member and protected  from the the base Class became private Member in the derive class 
// and always you cannot access private member outside the class 

class clsC :public  clsA{
    int _C = 30;

    public :
    
    void Function1()
    {
        cout << "\nfrom the private Mode " << endl;
        cout << clsA::PublicString << endl;
    }
    void Function2()
    {
        cout << "the Base class Protected Number is ";
        cout << clsA::_ProtectedNum << endl;
    }
    
    public :
    void function4(){
        cout << "\nhi Iam function4 from the private mode  " << endl;
    }

    // you connot access base class private members
};

class clInheritClassC :public clsC{
    // you cannot access any member from the clsA
    public :
    void function5() {

        clsC::Function1();
        clsC::Function2();
        clsC::function4();
    }
};

// Protected Mode 
// in this mode the public members from the base class became a protected
// and   the protected members became a protected and the private always private

class clsD :protected clsA{
    int _D;
    protected:
        string protectedClsDString = "came from the clsD And iam A protected member ";
    public :
        string PublicClsDString = "came from the clsD And iam A Public  member ";
};

class clsInheritClassD:public clsD{
    public :
    void printAccessList(){
        cout << "\nPublic String from the clsA :";
        cout <<clsA::PublicString;
        cout << "\nthe Protected member from the clsA :";
        cout <<clsA::_ProtectedNum<<endl;

        cout << clsD::protectedClsDString << endl;
        cout << clsD::PublicString << endl;
        
    }
};

int main(){

    cout << "\nfrom this scop you can access Public member only \n";

    clsB B1;
    cout << "\nClass clsB Public Member  :";
    cout << B1.PublicString;

    clsC C1;
    cout << "\nClass clsB Public Members :";
    C1.Function1();
    C1.Function2();
    C1.function4();
    cout << "Public String " << C1.PublicString << endl;
    
    clsD D1;
    cout << "\nClass clsB Public Members :";
    cout << "public clsD string "<<D1.PublicClsDString<<endl;
 

    return 0; 
}