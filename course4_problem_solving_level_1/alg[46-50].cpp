#include <iostream>
using namespace std;

// ----------- generic functions -------------
float readPositiveNumber(string massage)
{
    float number;
    cout << massage <<" --> ";
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

// ----------- 46 -----------------
// void PrintEnglishLettersInCapital(){
//     for (int i = 65; i<=90; i++){
//         cout << char(i) << endl;
//     }
// }
// ----------- 47 -----------------
float culculateManthCountForLoan(float loanAmount,float  manthlypayment){
    return loanAmount / manthlypayment;
}

void Print_Result(float manthsCount){
    cout << "############### the Result ###############\n";
    cout << " you will complete this loan in " << manthsCount <<" Manths"<< endl;
}

// ----------- 48 -----------------
float calculateManthlyPayment(float loanAmount, float manthsCount){
    return loanAmount / manthsCount;
}

void PrintManthlypayment(float manthlyPayment ){
    cout << "############# THE Result ################## \n";
    cout << " you need to paid manthly " << manthlyPayment << " Dollars" << endl;
}
// ----------- 49 -----------------
string Read_PIN_Code(){
    string PIN_Code;
    cout << " please enter your PIN Code -->";
    cin >> PIN_Code;
    return PIN_Code;
}

bool  login(){
    string User_PIN;
    string PIN_Code = "8421";
    int triesLeft = 5;
    
    do
    {
        triesLeft--;
         User_PIN = Read_PIN_Code();

        if (User_PIN == PIN_Code)
        {
            return 1;
        }else{
            system("color 4f");
                cout << "wrong PIN  and you have "<<triesLeft<<" chance "<<endl;
            }
    } while (User_PIN != PIN_Code && triesLeft > 0);
    return 0;
   }

void PrintBlanceResult(bool login){
    float  balance = 1000.00;
    if(login ){
        system("color 2f");
        cout << " your Balance is " << balance << " Dollars" << endl;
    }else{
        system("color 4f");
        cout << "your card blocked call bank for help " << endl;
        ;
    }

}
        int main()
{

    // ----------- 46 -----------------
    // PrintEnglishLettersInCapital();
    // ----------- 47 -----------------
    // float loanAmount = readPositiveNumber(" please enter your loan Amount ");
    // float manthlypayment = readPositiveNumber(" please enter the money count you can paid monthly");
    // Print_Result(culculateManthCountForLoan(loanAmount, manthlypayment));
    // ----------- 48 -----------------
    // float manthsCount = readPositiveNumber(" please enter the manth count you want to complete this loan on it ");
    // PrintManthlypayment(calculateManthlyPayment(loanAmount, manthsCount));
    // ----------- 49-----------------
    // PrintBlanceResult(Check_PIN_Code(Read_PIN_Code()));

    // PrintBlanceResult(login());
     // ----------- 50-----------------
    // PrintBlanceResult(login());


    return 0;
}