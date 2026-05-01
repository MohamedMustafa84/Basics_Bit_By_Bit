#include <iostream>
#include <vector>
using namespace std;


int main(){
    // std::vector<T> vector_name

    vector<int> vNumbers = {10, 20, 30, 40};

    cout << "Number Vector = ";

    // Note : send the variable by Ref to make the program faster and to use less storage

    for(int &Number:vNumbers){
        cout << Number << " ";
    }

    cout << endl;

    return 0;
}