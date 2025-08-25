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

int SumOfMatrixElements(int matrix1[3][3], short Rows, short Cols)
{
    int sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            sum += matrix1[i][j];
        }
    }
    return sum;
}

bool areTwoMatrixEqual(int matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return SumOfMatrixElements(matrix1, Rows, Cols) == SumOfMatrixElements(Matrix2, Rows, Cols);
}

    int main()
{

    //  problem:
    // write a program to compare tow matrix and check if they are equal or not
    
    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3],Matrix2[3][3];

    FillMatrixWithOrderedNum(matrix1, 3, 3);
    FillMatrixWithOrderedNum(Matrix2, 3, 3);

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);

    cout << "\n Matrix2:\n";
    printMatrix(Matrix2, 3, 3);


    cout << (areTwoMatrixEqual(matrix1, Matrix2, 3, 3) ? "the two Matrix are Equal" : "the two Matrix are Not Equal" )<<endl;


    system("pause>0");
}