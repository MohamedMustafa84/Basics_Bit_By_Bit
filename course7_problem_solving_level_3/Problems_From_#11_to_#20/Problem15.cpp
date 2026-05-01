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
    int main()
{

    //  problem:
    // write a program to count the repeatin of the number in the Matrix

    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3];

    FillMatrixWithRandomNumbers(matrix1, 3, 3);

    short Number;

    cout << "Please Enter a Number to search about it in the matrix : ";
    cin >> Number;

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);

    cout << "\nYour Number repeated " << countNumberRepeatin(matrix1, 3, 3,Number) << endl;
    

    return 0;
}