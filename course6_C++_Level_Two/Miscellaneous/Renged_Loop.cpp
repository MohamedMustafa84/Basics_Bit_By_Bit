#include <iostream>
using namespace std;

// syntax

// for(RangeDeclaration :RangeExpression){
    // code
// }




int main(){
    // Examples

    int Array[] = {10, 20, 30, 40, 50};
    for(int Number:Array){
        cout << Number << "\n";
    }
// ---------------------------
    for (int Number : {10, 20, 30, 40, 50})
    {
        cout << Number << "\n";
    }

    return 0;
}