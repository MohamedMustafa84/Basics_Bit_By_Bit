#include <iostream> 
using namespace std;


// Recursion

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