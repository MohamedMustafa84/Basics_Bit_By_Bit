#include <iostream>
#include <vector>
using namespace std;


int main(){
    
    vector <int> vNumber;
    // add element
    vNumber.push_back(10);
    vNumber.push_back(20);
    vNumber.push_back(30);
    vNumber.push_back(40);
    vNumber.push_back(50);

    cout <<"vector size is "<< vNumber.size();
    
    // Remove last Element  in the vector
    
    vNumber.pop_back();
    vNumber.pop_back();
    vNumber.pop_back();
    vNumber.pop_back();
    vNumber.pop_back();
    cout << "\nvector size is " << vNumber.size() << endl;

    vNumber.push_back(20);
    vNumber.push_back(30);
    vNumber.push_back(40);
    vNumber.push_back(50);

    // clear the Vector

    vNumber.clear();

    // Note : if the vector is Empty and you write (pop_back) it will throw an error
    
    if(!vNumber.empty()){
        vNumber.pop_back();

    }

    if (vNumber.size()>0)
    {
        vNumber.pop_back();
    }

        return 0; 
}