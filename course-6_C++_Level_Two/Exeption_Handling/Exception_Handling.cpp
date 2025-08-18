#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vNumbers = {1, 2, 3, 4};
    
    
    //use  try catch  carefully coz it make the program slower 

    try
    {
        //any thing can make exception in run time
        cout << vNumbers.at(10);
    }catch(...){
        // code you need to execute it when the exception ==true

        cout << "\nOut Of Bound" << endl;
    }


    return 0;
}