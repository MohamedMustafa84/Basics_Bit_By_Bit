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

bool isNumberExistInMatrix(int arr[3][3], short Rows, short Cols, short Number)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (arr[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

void findIntersectedNumbers(int matrix1[3][3], int MatrixTwo[3][3], short Rows,short Cols,vector <short> &vIntersectedNumbers){
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (isNumberExistInMatrix(matrix1, Rows, Cols, matrix1[i][j]) && isNumberExistInMatrix(MatrixTwo, Rows, Cols, matrix1[i][j]))
            {
               
                vIntersectedNumbers.push_back(matrix1[i][j]);


            }
             
        }
    }
}

void PrintIntersectedNumbers(vector<short> &vIntersectedNumbers){

    cout << "the Intersected numbers in the two Matrixes are : ";

    for (short &IntersectedNum : vIntersectedNumbers)
    {

        cout << IntersectedNum << "  ";
    }
    cout << endl;
}

    int main()
{

    //  problem:
    // write a program to  Print the Intersected numbers in two given Matrixes of size 3x3.

    srand(static_cast<unsigned int>(time(0)));

    int matrix1[3][3], MatrixTwo[3][3];
     vector <short> vIntersectedNumbers;


    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    FillMatrixWithRandomNumbers(MatrixTwo, 3, 3);

    cout << "\n Matrix One:\n";
    printMatrix(matrix1, 3, 3);

    cout << "\n Matrix Two :\n";
    printMatrix(MatrixTwo, 3, 3);

    findIntersectedNumbers(matrix1, MatrixTwo, 3, 3, vIntersectedNumbers);
    
    PrintIntersectedNumbers(vIntersectedNumbers);

    return 0;
}