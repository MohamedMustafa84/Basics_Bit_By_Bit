#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);



    cout << "first element in the vector : " << vNumbers.front() << endl;
    cout << "Last element in the vector : " << vNumbers.back() << endl;
    cout << "Number of elements present in  the vector : " << vNumbers.size() << endl;
    cout << "the over all size of the vector : " << vNumbers.capacity() << endl;


    // Note :

    // size 1 ,capacity 1
    // size 2 ,capacity 2
    // size 3 ,capacity 4
    // size 4 ,capacity 4
    // size 5,capacity 8
    // size 6,capacity 8
    // size 7,capacity 8
    // size 8,capacity 8
    // size 9 ,capacity 16 
    // size 10 ,capacity 16


    

    return 0;
}