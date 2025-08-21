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
            arr[i][j] = Random::RandomNumberInRange(1, 10);
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


int main()
{

    //  problem:
    // write aprogram to fill a 3x3 matrix with random  numbers form 1 to 10
    // then print the sum of all the elements in the matrix

  
    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3];

    FillMatrixWithRandomNumber(matrix1, 3, 3);

    cout << "\n Matrix1:\n";
    printMatrix(matrix1, 3, 3);

    cout << "the sum of all Matrix elements is " << SumOfMatrixElements(matrix1, 3, 3) << endl;

    system("pause>0");
}