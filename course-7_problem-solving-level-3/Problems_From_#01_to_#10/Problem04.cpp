#include <iostream>
#include <iomanip>
#include <string>
#include "../MyLib.h"
using namespace std;

void FillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = Random::RandomNumberInRange(1, 100);
        }
    }
}

void printMatrix(int arr[3][3], int Rows, int Cols)
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

short ColSum(int arr[3][3], short Rows, short ColumnNumber)
{
    short Sum = 0;
    for (short j = 0; j < Rows; j++)
    {
        Sum += arr[j][ColumnNumber];
    }

    return Sum;
}

void PrintSumOfCols(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << ColSum(arr, Rows, i) << endl;
    }
}

int main()
{
    // Problem
    // Write a program to fill a 3x3 matrix with random numbers, then Print each col sum

    srand(static_cast<unsigned int>(time(NULL)));

    int Matrix[3][3];

    FillMatrixWithRandomNumber(Matrix, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    printMatrix(Matrix, 3, 3);

    cout << "\n the following are the sum of each col in the matrix:\n";
    PrintSumOfCols(Matrix, 3, 3);

    return 0;
}
