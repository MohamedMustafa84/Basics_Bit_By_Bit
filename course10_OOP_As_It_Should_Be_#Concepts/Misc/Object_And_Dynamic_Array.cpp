#include <iostream>
using namespace std;

class clsA
{
public:
    // dummy Constructor 
    clsA(){}

    // parameterize Constructor 
    clsA(int Value)
    {
        x = Value;
    }
    int x;

    void print()
    {
        cout << "the value of x is : " << x << endl;
    }
};

int main()
{

    short NumberOfObjects=10;
    
    // allcating dynamic array of size number of the object using new keyword
    clsA *arrA = new clsA[NumberOfObjects];

// calling instructor for each index in the array 
    for (short i = 0; i <= NumberOfObjects; i++)
    {
        arrA[i] = clsA(i);
    }

    // print  the array Content

    for (int i = 0; i <= 10; i++)
    {
        arrA[i].print();
    }

    return 0;
}