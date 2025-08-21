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

void sumMatrixRows(int arr[3][3], int Rows, int Cols, int sumRow[3])
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            sumRow[i] += arr[i][j];
        }
    }
}

void printRowSum(int sumRow[3] ,short arrLength){
    for (int i = 0; i < arrLength; i++){
        cout << "Row " << i + 1 << " Sum = " << sumRow[i] << "\n";
    }
}
// ------------ solution 2 -----------------

short  RowSum(int arr[3][3], int RowNumber, int Cols)
{
    short Sum = 0;
    for (short  j = 0; j < Cols; j++)
    {
        Sum+= arr[RowNumber][j];
    }
    
    return Sum;
}

void PrintEachRowsSum(int arr[3][3], int Rows, int Cols){
    for (short i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " <<RowSum(arr,i,Cols) << "\n";
        
    }
}


int main()
{
    //  problem:
    // write a program to fill a 3x3 matrix with random numbers
    // then print each row sum

    srand(static_cast<unsigned int>(time(0))); 

    // ------------ solution 1 -----------------
    // int arr[3][3];
    
    // int RowsSum[3];
    // short arrLength=3;

    // FillMatrixWithRandomNumber(arr, 3, 3);

    // cout << "\nThe following is a 3x3 random matrix:\n";
    // printMatrix(arr, 3, 3);
    
    // sumMatrixRows(arr, 3, 3, RowsSum);
    // cout<< "\n the following are the sum of each row in the matrix:\n ";
    // printRowSum(RowsSum,arrLength);
    
    
    
    // ------------ solution 2 -----------------
    int Arr[3][3];
    FillMatrixWithRandomNumber(Arr, 3, 3);
    
    cout << "\nThe following is a 3x3 random matrix:\n";
    printMatrix(Arr, 3, 3);
    
    cout<< "\n the following are the sum of each row in the matrix:\n ";
    PrintEachRowsSum(Arr, 3, 3);

    system("pause>0");

}