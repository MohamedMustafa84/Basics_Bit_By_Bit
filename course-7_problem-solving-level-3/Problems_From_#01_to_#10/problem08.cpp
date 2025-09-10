#include <iostream>
#include <iomanip>
#include <string>
#include "../MyLib.h"
using namespace std;



void FillMatrixWithRandomNumber(int matrix[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            matrix[i][j] = Random::RandomNumberInRange(1, 10);
        }
    }
}

void printMatrix(int matrix[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << matrix[i][j] << "    ";
        }
        cout << "\n";
    }
}
void multipliesTwoMatrix(int matrixOne[3][3],int  matrixTwo[3][3], int matrixMul[3][3], short rows, short cols){
    for (short i = 0; i < rows; i++){
        for (short j = 0; j < cols; j++){
            matrixMul[i][j] = matrixOne[i][j] * matrixTwo[i][j];
        }
    }
}
int main()
{

    //  problem:
    // write a program to fill  tow  3x3 matrix with random  numbers
    // and print them ,then multiply them into a 3x3 matrix and print it 

    srand(static_cast<unsigned int>(time(0)));

    int matrixOne[3][3], matrixTwo[3][3],matrixMul[3][3];

    FillMatrixWithRandomNumber(matrixOne, 3, 3);
    FillMatrixWithRandomNumber(matrixTwo, 3, 3);

    cout << "\nMatrix 1:\n";
    printMatrix(matrixOne, 3, 3);

    cout << "\nMatrix 2:\n";
    printMatrix(matrixTwo, 3, 3);
    
    multipliesTwoMatrix(matrixOne, matrixTwo, matrixMul, 3, 3);
    cout << "\nResults:\n";
    printMatrix(matrixMul, 3, 3);


    system("pause>0");
}