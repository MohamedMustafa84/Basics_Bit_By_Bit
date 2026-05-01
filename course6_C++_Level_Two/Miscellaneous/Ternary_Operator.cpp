#include <iostream>
using namespace std;

// Syntax
            // true           false
// condition ? expression1 : expression2;



// -------------- home work --------------
int ReadNumber(string Message)
{
    int Number;
    cout << Message << " ";
    cin >> Number;
    return Number;
}

 
bool isPositiveNumber(int Number){
    return (Number >0) ? true : false;
}

int main(){
    // example
    
    int mark = 60;
    string Result = "";

    if(mark>=50){
        Result = "PASS";
    }else{
        Result = "FAIL";
    }

    cout << Result << endl;
    
    // using short Hand If
    Result = (mark >= 50) ? "PASS" : "FAIL";
    cout << Result << endl;
    
    // Other Solution
    (mark >= 50) ? cout <<"PASS" : cout <<"FAIL";



    // --------------- Home Work ----------------
    // program to check if the number is Positive or Negative
    int Number= ReadNumber("Enter Your Number");
    cout << "the number is ";
    isPositiveNumber(Number) ? cout << "Positive" :cout<< "Negative";
    
    
    
    // program to check if the number is Zero , Positive or Negative(Nested Ternary Operator)

    string Result = (Number == 0) ? "Zero" : isPositiveNumber(Number) ? "Positive": "Negative";
    cout << "\nthe number is "<<Result <<endl;

    return 0;
}