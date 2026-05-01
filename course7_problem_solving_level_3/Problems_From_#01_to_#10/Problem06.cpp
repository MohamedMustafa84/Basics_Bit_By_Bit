#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNum(int matrix[5][5],int Rows, int Cols)
{
    short Number = 1;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            matrix[i][j] = Number;
            Number++;
        }
    }
}

void printMatrix(int arr[5][5], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}

int main(){

    // Problem
    //  write aprogram to fill a 5x5 matrix with Ordered  numbers

    int arr[5][5];

    FillMatrixWithOrderedNum(arr, 5, 5);

    cout << "\n the following is a 5x5 Ordered matrix:\n";
    printMatrix(arr, 5, 5);

    system("pause>0");

    return 0;
}