#include <iostream>
using namespace std;

// Right click then find all reference

// Right click then peek


void functionOne(){
    cout << "iam function one" << endl;
}

void functionTwo()
{
    cout << "iam function two" << endl;
    functionOne();
}

void functionThree()
{
    cout << "iam function Three" << endl;
    functionOne();
}

int main(){
    functionOne();

    return 0;
}