#include  <iostream>
using namespace std ;

// friend Function is a function can access any Member from the class 

 class clsA{
    int _Var1;
    protected:
        int _Var2;

    public :
        int Var3;
        clsA()
        {
            _Var1 = 10;
            _Var2 = 20;
            Var3 = 30;
        }
        // friend function 
        friend int MySum(clsA A);
        friend int MySub(clsA A);
};

int MySum(clsA A1){
    return A1._Var1 + A1._Var2 + A1.Var3;
}

// friend function can be inside a class

int MySub(clsA A1)
{
    return A1.Var3 - A1._Var2 - A1._Var1;
}

int main() 
{
    clsA A1;

    cout <<"the sum of the Private , protected and public members inside clsA is "<< MySum(A1)<<endl;
    cout <<"the sub  of the Private , protected and public members inside clsA is "<< MySub(A1)<<endl;

    return 0; 


}