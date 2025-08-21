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

short ColumnSum(int arr[3][3], int Rows, int ColumnNumber)
{
    short Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColumnNumber];
    }

    return Sum;
}
void FillSumArray(int Matrix[3][3], int Rows, int ColumnNumber, int ArrayOfSum[3])
{
    for (short j = 0; j < ColumnNumber; j++){
       ArrayOfSum[j]= ColumnSum(Matrix, Rows, j);
    }
}

void PrintColumnsSum(int columnSum[3],short arrLength){
    for (short i = 0; i < arrLength; i++){
        cout << "Column " << i + 1 << " Sum = " << columnSum[i] << "\n";
    }
}

int main(){
    
//    Problem
// Write  a program to fill a 3x3 matrix with random numbers 
// then sum each column in separate array and print the results

srand(static_cast<unsigned int>(time(0)));

int Matrix[3][3];

int ArrayOfSum[3];

FillMatrixWithRandomNumber(Matrix, 3, 3);

cout << "\nThe following is a 3x3 random matrix:\n";
printMatrix(Matrix, 3, 3);

FillSumArray(Matrix, 3, 3, ArrayOfSum);
cout << "\nthe following are the sum of each column in the matrix:\n";
PrintColumnsSum(ArrayOfSum, 3);

return 0;
}