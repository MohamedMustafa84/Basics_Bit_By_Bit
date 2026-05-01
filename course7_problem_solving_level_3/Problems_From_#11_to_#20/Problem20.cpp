#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "../MyLib.h"
using namespace std;

void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols)
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


bool isPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols/2; j++)
        {
            if(Matrix[i][j]!=Matrix[i][Cols-1-j]){
                return false;
            }
            
        }
    }
    return true;
}


    int main()
{

    //  problem:
    // write a program to check it the matrix is palindrome or not 


    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3];
    int MatrixTwo[3][3] = {{1, 2, 1}, {2, 3, 2}, {3, 4, 3}};


    FillMatrixWithRandomNumbers(matrix1, 3, 3);

    cout << "\n Matrix1  One:\n";
    printMatrix(matrix1, 3, 3);

    cout <<( isPalindromeMatrix(matrix1, 3, 3) ? "\n Yes : the Matrix is Palindrome " : "No : The matrix is Not Palindrome" )<< endl;

    cout << "\n Matrix Two :\n";
    printMatrix(MatrixTwo, 3, 3);
    cout <<( isPalindromeMatrix(MatrixTwo, 3, 3) ? "\n Yes : the Matrix is Palindrome " : "No : The matrix is Not Palindrome")<< endl;


    return 0;
}