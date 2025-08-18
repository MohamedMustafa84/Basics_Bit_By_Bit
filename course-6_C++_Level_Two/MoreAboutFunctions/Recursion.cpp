#include <iostream> 
using namespace std;


// Recursion
// is a function colling her self based of specific condition 
// you should use it carefully coz to take a big size and if use dont use it properly it  make infinite loop

void PrintNumberInRange(int from,int to){
    if (from<=to)
    {
        cout << from << endl;
        PrintNumberInRange(from + 1, to);
    }
    
}

int main(){
    PrintNumberInRange(1, 4);

    return 0;
}