#include <iostream>
#include <vector>
using namespace std;


// Note: vector use Stack Data Strucsher (last in first out)



// ----- home work -----------

 void ReadUserInputs(vector <int> &vUserInputNumber){
     char ReadMore = 'Y';
     int AddedNumber = 0;

     while(ReadMore=='Y'||ReadMore=='y'){
         cout << "please Enter A number  " << endl;
         cin >> AddedNumber;
         vUserInputNumber.push_back(AddedNumber);
         cout << "do you want to add more elements : (Y /N) ?";
         cin >> ReadMore;
     }
 }

 void PrintUserInputs(vector<int> &vUserInputNumber){
     cout << "Vector elements :" << endl;
     for (int &number : vUserInputNumber) // you should use ByRef with vector even to print to make the program faster
     {
         cout << number << endl;
     }
 }

 int main()
 {

     vector<int> vNumbers;
     // push_back(element) add element  to vector
     vNumbers.push_back(10);
     vNumbers.push_back(100);
     vNumbers.push_back(40);
     vNumbers.push_back(30);

     cout << "Vector Numbers :" << endl;

     for (int &number : vNumbers)
     {
         cout << number << endl;
     }

     // Home Work:
     // Write a Program to ask the user to enter as many numbers as s/he want,
     //  each time a number entred add it to vector and ask the user if s/he wants to add more number until s/he says No then Print all vector elements on the screen

     vector<int> vUserInputNumber;
     ReadUserInputs(vUserInputNumber);
     PrintUserInputs(vUserInputNumber);

     return 0;
 }