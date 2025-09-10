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

short RowSum(int arr[3][3], int RowNumber, int Cols)
{
    short Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumber][j];
    }

    return Sum;
}
void FillArray(int Matrix[3][3], int RowNumber, int Cols, int ArrayOfSum[3])
{
    for (short i = 0; i < RowNumber; i++){
       ArrayOfSum[i]= RowSum(Matrix, i, Cols);
    }
}

void PrintRowsSum(int RowSum[3],short arrLength){
    for (short i = 0; i < arrLength; i++){
        cout << "Row " << i + 1 << " Sum = " << RowSum[i] << "\n";
    }
}

int main(){
    
//    Problem
// Write  a program to fill a 3x3 matrix with random numbers 
// then sum each row in separate array and print the results

srand(static_cast<unsigned int>(time(0)));

int Matrix[3][3];

int ArrayOfSum[3];

FillMatrixWithRandomNumber(Matrix, 3, 3);

cout << "\nThe following is a 3x3 random matrix:\n";
printMatrix(Matrix, 3, 3);

FillArray(Matrix, 3, 3, ArrayOfSum);
cout << "\n the following are the sum of each row in the matrix:\n";
PrintRowsSum(ArrayOfSum, 3);

return 0;
}