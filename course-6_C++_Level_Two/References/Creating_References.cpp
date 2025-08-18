#include <iostream>
using namespace std;

int main(){

    int A = 10;
    // creating reference to A (Alias)
    int &x = A;

    cout << "A Location at Memory is " << &A << endl;
    cout << "x Location at Memory is " << &x << endl;

    // and the value of both is equivplanet
    cout << "value of A :" << A << endl;
    cout << "value of x:" <<x<< endl;

    // and if i changed any of variable value it will change in anther variable too
    x = 20;

    cout << "value of A :" << A << endl;
    cout << "value of x:" << x << endl;

    return 0;
}