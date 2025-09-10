#include <iostream>
using namespace std;

void PrintFibonacciSeries(short SeriesNum){
    short FebNumber = 0;
    short prev1 = 0, prev2 = 1;
    cout << "The Fibonacci series from 1 to " << SeriesNum << " is : ";
    cout << "1  ";
    for (short i = 2; i <= SeriesNum; i++){
        FebNumber = prev1 + prev2;
        cout << FebNumber << "  ";
        prev1 = prev2;
        prev2 = FebNumber;
    }
    cout << endl;
}

int main(){
    
    // Problem
    // Write a program to print Fibonacci series of 10 .

    // 1  1  2  3  5  8  13  21  34  53


    PrintFibonacciSeries(10);

    return 0;
}