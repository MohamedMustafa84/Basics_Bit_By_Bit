#include <iostream>
using namespace std;

// printf formatting float and double

int main(){

    float PI = 3.14159265;

    // precision specification

    printf("Precision  specification of %.*f\n", 1, PI);
    printf("Precision  specification of %.*f\n",2, PI);
    printf("Precision  specification of %.*f\n",4, PI);
    printf("Precision  specification of %.*f\n", 3, PI);

    float x = 7.0, y = 9.0;
    printf("\n the float division is :%.3f / %.3f = %3.f\n\n", x, y, x / y);

    double d = 12.45;
    printf("the double  value is : %.3f\n", d);
    printf("the double  value is : %.4f\n", d);

    return 0;
}