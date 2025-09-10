#include <iostream>
#include <iomanip>
#include <string>
#include "../MyLib.h"
using namespace std;


//  ------solution 1--------
void FillMatrixWithRandomNum( int matrix [3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j<3; j++){
            matrix[i][j] = Random::RandomNumber();
        }
     }
 }

 void printMatrix(int matrix[3][3])
 {
     cout << "Matrix Content:" << endl;
     for (int i = 0; i < 3; i++)
     {
         cout << "\nRow " << i +1 << " content is :";
         
         for (int j = 0; j < 3; j++)
         {
             cout << matrix[i][j] << " ";
            }
        }
    }
    
    
    
    //  ------solution 2--------

    void FillMatrixWithRandomNumber(int arr [3][3],int Rows,int Cols){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
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
                cout <<setw(3)<<arr[i][j]<<"    ";
            }
            cout << "\n";
        }
    }
int main()
{

//  problem:
// write aprogram to fill a 3x3 matrix with random  numbers

// -------- solution 1------------
// int matrix[3][3];

// FillMatrixWithRandomNum(matrix);

// printMatrix(matrix);

// -------- solution 2------------

// seed the random number generator in C++ ,called Only Once
srand(static_cast<unsigned int>(time(0)));

int arr[3][3];

FillMatrixWithRandomNumber(arr, 3, 3);

cout<<"\n the following is a 3x3 random matrix:\n";
printMatrix(arr, 3, 3);

system("pause>0");


}