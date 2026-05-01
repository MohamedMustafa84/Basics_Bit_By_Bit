#include <iostream>
using namespace std;

// ---------------------- Generic functions -------------------------
int readPositiveNumber(string massage)
{
    int number;
    cout << massage << " --> ";
    cin >> number;
    cout << endl;
    while (number <= 0)
    {
        cout << " the number most be grater than zero please retry -->";
        cin >> number;
        cout << endl;
    }

    return number;
}


//  ----- 10-----/



int reverseNumber( int mainNumber){
    int Remainder = 0,Number=0;
    while(mainNumber>0){
        Remainder = mainNumber % 10;
        mainNumber =mainNumber/10;
        Number = Number * 10 + Remainder;
    }
    return Number;
}
void printDigit(int Number){
    cout << "the reverse is :" << endl;
    int remainder = 0;
    while(Number>0){
        remainder = Number % 10;
        Number =Number/ 10;
        cout << remainder << endl;
    }
}
// ----------------- 11 ---------------------------

int  ReversedNumber(int number)
{
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
    }
    return remainder;
}
bool isPalindrome(int Number)
{
    return ReversedNumber(Number) == Number;
}
void printResult (bool isPalindrome){
    if (isPalindrome == true){
        cout << "the Number You Intered Is Palindrome " << endl;
    }else{
        
        cout << "the Number  Is NOT! Palindrome " << endl;
    }
}

    int
    main()
{
    // ----------------- 10 ---------------------------
    // printDigit(reverseNumber(readPositiveNumber(" please enter anumber and i will reverse it ")));
    // ----------------- 11 ---------------------------

    isPalindrome(readPositiveNumber(" please enter a Number and i will check if it palindrome or not  "));
}