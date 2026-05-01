#include <iostream>
using namespace std;

// Home Work
void fillMultiplicationArray(int MultResult[10][10]){
    for (int i = 0; i<10; i++){
        for (int j = 0; j < 10; j++){
            MultResult[i][j] = (i + 1) * (j + 1);
        }
    }
}

void PrintMultiplicationTable(int MultResult[10][10]){

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%0*d ", 2, MultResult[i + 1][j + 1]);
        }
        cout << "\n";
    }
}

    int main()
{

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
            cout << TwoDimensionalArray[i][j] << " ";
        }
        cout << endl;
    }
    // Home Work
    // Write a Program to Store The Multiplication Table Result 10x10 And Print it On The Screen
    int MultResult[10][10];
    fillMultiplicationArray(MultResult);
    PrintMultiplicationTable(MultResult);

    return 0;
}