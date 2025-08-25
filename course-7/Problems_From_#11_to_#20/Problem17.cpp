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

bool isNumberExistInMatrix(int arr[3][3], short  Rows, short  Cols, short Number)
{
    for (short  i = 0; i < Rows; i++)
    {
        for (short  j = 0; j < Cols; j++)
        {
            if (arr[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}


int main()
{

    //  problem:
    // write a program to check if a given number exists in matrix or not



    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3];

    short Number;
    cout << "Please Enter a Number to search about it in the matrix : ";
    cin >> Number;


    FillMatrixWithRandomNumbers(matrix1, 3, 3);

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);

    cout << (isNumberExistInMatrix(matrix1, 3, 3,Number) ? "\nYes: the Number is Exist " : "\nNo: the Number is not Exist") << endl;

    return 0;
}