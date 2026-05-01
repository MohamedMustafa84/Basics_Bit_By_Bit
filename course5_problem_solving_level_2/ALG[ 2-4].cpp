#include <iostream>
using namespace std;


// ---------------------- generic Functions ----------------
int readPositiveNumber(string message)
{
    int number;
    cout << message << " --> ";
    cin >> number;
    cout << endl;
    while (number <= 0)
    {
        cout << " the number most be greater than zero please retry -->";
        cin >> number;
        cout << endl;
    }

    return number;
}

// ----------------------- 2 ------------------
enum enPrimeNotprime
{
    prime,
    notPrime
};
enPrimeNotprime isNumberPrime(int number)
{
    int M = number / 2;

    for (int i = 2; i <= M; i++)
    {
        if (number % i == 0)
        {
            return enPrimeNotprime::notPrime;
        }
    }
    return enPrimeNotprime::prime;
}
void PrintPrimeNnumberFrom1ToN(int number){
    cout << " the prime number form 1 to " << number << " are :" << endl;
    for (int i = 1; i <=number; i++){
        if( isNumberPrime(i)== enPrimeNotprime::prime){
            
            cout << i << endl;
        }
    }
}

// ----------------------- 3 ------------------
// int sumOfDivesionNum(int Number){
//     int sumOfDivesion = 0;
//     for (int i = 1; i < Number; i++){
//         if(Number%i ==0){
//             sumOfDivesion += i;
//         }
//     }
//     return sumOfDivesion;
// }



bool isNumberPerfect(int Number){
    int sumOfDivesion = 0;
    for (int i = 1; i < Number; i++){
        if(Number%i ==0){
            sumOfDivesion += i;
        }
    }

    return sumOfDivesion ==Number;

}
    

void Print_Result(bool isPerfect, int Number){
    if(isPerfect)
        cout << Number << " is A Perfect Number " << endl;
        else
        cout << Number << " is NOT! A Perfect Number " << endl;
    }
    // ----------------------- 4 ------------------

    void PrintPerfectNumberFrom1ToN(int number){
        cout << "The Perfect Number from 1 to " << number << " are :" << endl;
        for (int i = 1; i <= number; i++){

            if (isNumberPerfect( i )){
                cout << i << endl;
            }
        }

    }
int main(){
    
    
    // int number = readPositiveNumber("please enter number and i will give you all prime number from 1 to your number");
    // PrintPrimeNnumberFrom1ToN(number);


    // ----------------------- 3 ------------------
    
    
    // int Number = readPositiveNumber("Enter A Number and i will check  is is perfect number or not");
    
    // Print_Result(isNumberPerfect(Number),Number);
    // ----------------------- 4 ------------------
   
    
    // int N = readPositiveNumber("Enter a number and i will give you all perfect numbers from 1 to your number");
    // PrintPerfectNumberFrom1ToN(N);
    // cin >> N;
   

    return 0;
}