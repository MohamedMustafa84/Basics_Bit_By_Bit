#include <iostream>
using namespace std;



int main(){
    
    // int ArrayName [Rows][Cols] 
    // Element Position = [Row-1] [col-1]

    int TwoDimensionalArray[3][4] = {
        (1, 2, 4, 4),
        (2, 5, 5, 6),
        (9, 10, 12, 30)
    };

    // Loop Throw The Array

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            cout << TwoDimensionalArray[i][j] << endl;
        }
    }

        return 0;
}