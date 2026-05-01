#include <iostream>;
using namespace std; 

// the friend class is a class can access any Member from the specific class even the private and the protected members


class  clsA{
    int _Var1;
    public :
        int Var2;

    clsA(){
        _Var1 = 10;
        Var2 = 20;
    }

    // Friend Class
    friend class clsB;
};

class clsB {
    public :
// send the class as a parameter
    void display(clsA A1){

        cout << "the Value of the Private member is " << A1._Var1 << endl;
        cout << "the Value of the Public member is " << A1.Var2 << endl;
    }
};

int main(){

    clsA A1;
    clsB B1;
    B1.display(A1);

    return 0;
}