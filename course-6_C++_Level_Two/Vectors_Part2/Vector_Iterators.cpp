#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector <int>Nums={1,2,3,4,5};

    // declare iterator
    vector<int>::iterator itre;


    // using  Iterator with for loop
    for (itre = Nums.begin(); itre != Nums.end(); itre++)
    {
        cout << *itre << " ";   
    }
    cout << endl;

    return 0;
}