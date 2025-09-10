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

void CreateIdentityMatrix(int IdentityMatrix[3][3], short Rows, short Cols){
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i==j)
            {
                IdentityMatrix[i][j] = 1;
            }else{
                
                IdentityMatrix[i][j] = 0;
            }
        }
    }
}

bool isIdentityMatrix(int matrix[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if(i==j ){
                if (matrix[i][j] != 1)
                    return false;
            }else{
                if(matrix[i][j]!=0){
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
    // write a program to check if the matrix is identity or not


    int matrix1[3][3],IdentityMatrix[3][3];

    FillMatrixWithOrderedNum(matrix1, 3, 3);

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);

    CreateIdentityMatrix(IdentityMatrix, 3, 3);

   

    cout<< (isIdentityMatrix(matrix1, 3, 3) ? "\nYes : the matrix is Identity" : "\nNo : the matrix is NOT Identity") << endl;
    
    cout << "\n Identity Matrix1:\n";
    printMatrix(IdentityMatrix, 3, 3);
    cout << (isIdentityMatrix(IdentityMatrix, 3, 3) ? "\nYes : the matrix is Identity" : "\nNo : the matrix is NOT Identity") << endl;

    return 0;
}