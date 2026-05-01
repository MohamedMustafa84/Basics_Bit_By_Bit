#include <iostream>
#include <iomanip>
#include <string>
#include "../MyLib.h"
using namespace std;





void FillMatrixWithRandomNumber(short arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = Random::RandomNumberInRange(1, 10);
        }
    }
}

void printMatrix(short arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}


// solution 1

void PrintMatrixMiddleRow(short arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {

        if(i== Rows/2){
            for (short j = 0; j < Cols; j++)
            {
                cout << setw(3) << arr[i][j] << "    ";
            }
        } 
    }
}

void PrintMatrixMiddleCol(short arr[3][3], short Rows, short Cols)
{
    for (short j = 0; j < Cols; j++)
    {
        
        if (j == Cols/ 2)
        {
            for (short i = 0; i < Rows; i++)
            {
                cout << setw(3) << arr[i][j] << "    ";
            }
        }
    }
}
// solution 2

void PrintMiddleRowOfMatrix(short arr[3][3], short Rows, short Cols)
{
    short middleRow = Rows / 2;
    for (short j = 0; j < Cols; j++)
    {

        printf("  %0*d  ", 2, arr[middleRow][j]);
    }
}

void PrintMiddleColOfMatrix(short arr[3][3], short Rows, short Cols)
{
    short middleCol = Cols / 2;
    for (short i = 0; i < Rows; i++)
    {

        printf("  %0*d  ", 2, arr[i][middleCol]);
    }
}

int main()
    {

        //  problem:
        // write aprogram to fill a 3x3 matrix with random  numbers
        // then print the middle row and the middle col

        srand(static_cast<unsigned short>(time(0)));

        short Matrix1[3][3];

        FillMatrixWithRandomNumber(Matrix1, 3, 3);

        cout << "\n  matrix1:\n";
        printMatrix(Matrix1, 3, 3);


        // solution 1
        
        // cout << "Middle Row of matrix1 is :";
        // PrintMatrixMiddleRow(Matrix1, 3, 3);
        
        // cout << "\nMiddle Column of matrix1 is :";
        // PrintMatrixMiddleCol(Matrix1, 3, 3);
        
        
        // solution 2

        cout << "Middle Row of matrix1 is :";
        PrintMiddleRowOfMatrix(Matrix1, 3, 3);

        cout << "\nMiddle Column of matrix1 is :";
        PrintMiddleColOfMatrix(Matrix1, 3, 3);

        system("pause>0");
    }