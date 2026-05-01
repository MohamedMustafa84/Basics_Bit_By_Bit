#include <iostream>
using namespace std;

void PrintFibonacciSeriesUsingRecursion(short Number,short prev1,short prev2){
    short fibNumber = 0;
    if(Number>0){
        fibNumber = prev1 + prev2;
        prev2 = prev1;
        prev1 = fibNumber;
        cout << fibNumber << " ";
        PrintFibonacciSeriesUsingRecursion(Number - 1, prev1, prev2);
    }

}


int main()
{

    // Problem
    // Write a program to print Fibonacci series of 10 using Recursion .

    // 1  1  2  3  5  8  13  21  34  53

    cout << "Fibonacci Using Recursion:";

    PrintFibonacciSeriesUsingRecursion(10, 0, 1);

    return 0;
}