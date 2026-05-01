#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "../MyLib.h"
using namespace std;

void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols)
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

short maxNumberInMatrix(int Matrix[3][3], int Rows, int Cols)
{
    short maxNumber =Matrix[0][0] ;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] > maxNumber)
            {
                maxNumber = Matrix[i][j];
            }
        }
    }
    return maxNumber;
}

short minNumberInMatrix(int Matrix[3][3], int Rows, int Cols){
    short minNumber=Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if(Matrix[i][j] <minNumber){
                minNumber = Matrix[i][j];
            }
        }
    }
    return minNumber;
}

    int main()
{

    //  problem:
    // write a program to  Print the Min And Max numbers in the Matrixes.

    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3];


    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    printMatrix(matrix1, 3, 3);

    cout << "the min number is the matrix is " << minNumberInMatrix(matrix1, 3, 3) << endl;
    cout << "the min number is the matrix is " << maxNumberInMatrix(matrix1, 3, 3) << endl;


    return 0;
}