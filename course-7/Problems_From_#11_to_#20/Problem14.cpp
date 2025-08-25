#include <iostream>
#include <iomanip>
#include <string>
#include "../MyLib.h"
using namespace std;

void FillMatrixWithOrderedNum(int matrix[3][3], int Rows, int Cols)
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

void CreateScallerMatrix(int IdentityMatrix[3][3], short Rows, short Cols,short ScallerNum)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == j)
            {
                IdentityMatrix[i][j] = ScallerNum;
            }
            else
            {

                IdentityMatrix[i][j] = 0;
            }
        }
    }
}

bool isScallerMatrix(int matrix[3][3], short Rows, short Cols)
{
    int ScallerNum = matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == j)
            {
                if (matrix[i][j] != ScallerNum)
                    return false;
            }
            else
            {
                if (matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{

    //  problem:
    // write a program to check if the matrix is Scaller or not

    int matrix1[3][3], ScallerMatrix[3][3];

    FillMatrixWithOrderedNum(matrix1, 3, 3);

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);
    
    short ScallerNum = 0;
    cout << (isScallerMatrix(matrix1, 3, 3) ? "\nYes : the matrix is Scaller Matrix" : "\nNo : the matrix is NOT Scaller Matrix") << endl;
    
    cout << "\n\nlets Create your own custom  Scaller Matrix";
    cout << "\nwhat is the Number you want to be in the diagonal in your Scaller matrix :";
    cin >> ScallerNum;
    
    CreateScallerMatrix(ScallerMatrix, 3,3, ScallerNum);
    
    
    cout << "\n\nYour Scaller Matrix:\n";
    printMatrix(ScallerMatrix, 3, 3);
    cout << (isScallerMatrix(ScallerMatrix, 3, 3) ? "\nYes : the matrix is Scaller Matrix" : "\nNo : the matrix is NOT Scaller Matrix") << endl;

    return 0;
}