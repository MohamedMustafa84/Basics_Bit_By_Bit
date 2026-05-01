#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> Num = {1, 2, 3, 4};
    cout << "using .at(index)" << endl;
    cout <<"Elements at index 0 : "<< Num.at(0)<<endl;
    cout <<"Elements at index 1 : "<< Num.at(1)<<endl;
    cout <<"Elements at index 2 : "<< Num.at(2)<<endl;
    cout <<"Elements at index 3 : "<< Num.at(3)<<endl;
    //if the vector has 4 elements and you Write vectorName.at(5) it will throw an exception
    
    cout << "using [index]" << endl;
    cout << "Elements at index 0 : " << Num[0] << endl;
    cout << "Elements at index 1 : " << Num[1] << endl;
    cout << "Elements at index 2 : " << Num[2] << endl;
    cout << "Elements at index 3 : " << Num[3] << endl;
    //if the vector has 4 elements and you Write vectorName[5] it will give you Warning

    return 0;
}