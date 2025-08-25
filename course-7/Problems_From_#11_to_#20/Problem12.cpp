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



bool areTypicalMatrix(int matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(matrix1[i][j] != Matrix2[i][j])
                return false;
        }
    }
    return true;
}

int main()
{

    //  problem:
    // write a program to compare tow matrix and check if they typical or not

    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3], Matrix2[3][3];

    FillMatrixWithOrderedNum(matrix1, 3, 3);
    FillMatrixWithOrderedNum(Matrix2, 3, 4);

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);

    cout << "\n Matrix2:\n";
    printMatrix(Matrix2, 3, 3);

    cout << (areTypicalMatrix(matrix1, Matrix2, 3, 3) ? "Yes : the two matrix are typical" : "No : the two matrix are Not  typical") << endl;

    system("pause>0"); 
}