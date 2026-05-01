#include <iostream>
#include <iomanip>
#include <string>
#include "../MyLib.h"
using namespace std;

void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = Random::RandomNumberInRange(1, 5);
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

short countNumberRepeatin(int arr[3][3], int Rows, int Cols ,short Number)
{
    short repeatCount = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (arr[i][j]== Number){
                repeatCount++;
            }
        }
    }
    return repeatCount;
}

bool isSparseMatrix(int arr[3][3], short  Rows, short  Cols){
    short MatrixSize = Rows * Cols;

    return countNumberRepeatin(arr, Rows, Cols, 0) >= MatrixSize / 2;
}

    int main()
{

    //  problem:
    // write a program to check if the matrix is sparse or not 
    // the matrix is sparse if the number of zero elements > 50% of the total number of elements


    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3];

    int sparseMatrix[3][3] = {
        {1, 0, 0},
        {0, 0, 2},
        {2, 2, 0}
    };

    FillMatrixWithRandomNumbers(matrix1, 3, 3);

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);

    cout << (isSparseMatrix(matrix1, 3, 3)?"Yes: it is Sparse ":"No: it is not Sparse") << endl;
    
    cout << "\n  sparseMatrix:\n";
    printMatrix(sparseMatrix, 3, 3);
    cout << (isSparseMatrix(sparseMatrix, 3, 3) ? "Yes: it is Sparse " : "No: it is not Sparse") << endl;

    return 0;
}