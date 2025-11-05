#include <iostream>
#include <vector>
using namespace std;


class clsA{
    public:
    clsA(int Value){
        x = Value;
    }
    int x;

    void print(){
        cout << "the value of x is : " << x << endl;
    }
};

int main(){

    vector<clsA> V1;
    // insert the object at the end of the vector
    for (short i = 1; i <= 10; i++){
        V1.push_back(clsA(i));
    }

    // print  Object Content

    for (int Object = 0; Object <= 10; Object++)
    {
        V1[Object].print();
    }

        return 0;
}