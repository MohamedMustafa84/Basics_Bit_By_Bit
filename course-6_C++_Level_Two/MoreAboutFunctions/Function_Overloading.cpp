#include <iostream>
using namespace std;

// Function Overloading:
// It means having a function that performs more than one thing based on changing factors,
// such as the number or types of parameters.
//
// In real life, the concept of Function Overloading resembles the idea of "situational confidence" in humans,
// where a person’s confidence rises and falls based on certain factors.
// For example, in certain situations and with certain people, their behaviors and situational confidence vary.
// This is also known as "multiple faces" (different facets of personality).

// Example:

int MySum(int a, int b)
{
    return (a + b);
}

double MySum(double a, double b, double c)
{
    return (a + b + c);
}

short MySum(short a, short b, short c, short e)
{
    return (a + b + c - e);
}

int main()
{
    cout << "sum of Two Numbers " << MySum(10, 20) << endl;
    cout << "sum of three (double) Numbers " << MySum(2, 39, 30) << endl;
    cout << "sum of 4 (short) Numbers " << MySum(2, 36, 30, 40) << endl;

    return 0;
}
