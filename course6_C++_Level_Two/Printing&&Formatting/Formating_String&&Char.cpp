#include<iostream>
using namespace std;


int main(){
    
    // Note: to format the string whit printf function we need to declare  Array of char

    char Name[] = "Mohamed Mustafa";
    char schoolName[] = "Programming advices";

    printf("Dear %s How Are You ?\n", Name);
    printf("Welcome To %s School\n", schoolName);

    char Letter='s';

    printf("setting The Width of %s: %*s", 2, Letter);
    printf("setting The Width of %s: %*s", 4, Letter);
    printf("setting The Width of %s: %*s", 6, Letter);
    printf("setting The Width of %s: %*s", 8, Letter);

    return 0;
}