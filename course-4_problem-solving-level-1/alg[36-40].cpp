#include <iostream>
#include <cmath>
using namespace std;

// -------- generic fuctions -----------------

int readPositiveNumber(string massage){
    int number;
    cout << massage << endl;
    cin >> number;
    while(number<=0){
        cout << " the number most be greter than zero please retry -->";
        cin >> number;
        cout << endl;
    }
    
    return number;
}

int readNumber(string massage){
    int number;
    cout << massage << endl;
    cin >> number;
    return number;
}

// ------------------------ 36 -----------
enum enOperationType
{
    add = '+',
    multiply = 'x',
    divides = '/',
    substract = '-'
};
enOperationType ReadOperationType(){
    char type = '0';
    cout << "enter your Operation type " << endl;
    cin >> type;
    return (enOperationType)type;
}

float clclateOperation(int firstNumber, int secondNumber, enOperationType Operation){
    if (Operation == enOperationType::add)
    {
        return (float)(firstNumber + secondNumber);
    }
    else if (Operation == enOperationType::substract){
        return (float)(firstNumber - secondNumber);
    }
    else if (Operation == enOperationType::multiply)
    {
        return (float)(firstNumber * secondNumber);
    }
    else {
        
        return (float)(firstNumber / secondNumber);
    }
}

void printCalcuationResult( float result)
{
    cout << " the result for your result is " <<result << endl;
}

// ------------------------ 37 -----------

int sumNumbersUntil99()
{
    int number = readNumber("please enter number and i will sum it");
    int sum = 0, counter = 2;


    do{
            cout << "please enter number " + to_string(counter) << endl;
            cin >> number;
            if (number == -99)
            {
                break;
            }
                sum += number;
            
    } while (number != -99);
    return sum;
}

 void printSum( int sum){
     cout << " the sum of all your numbers is " << sum << endl;
 }

 // ------------------------ 39-----------
 float calculateRemander(int cashpiad){
     int totalbill = 500;
     int totalcashpaid = cashpiad;
     while (totalbill > totalcashpaid)
     {
         int remainder = totalbill - totalcashpaid;
         cout << "sorry  you have to paid anthor " <<remainder <<" dollars" << endl;
         cin >> cashpiad;
         totalcashpaid += cashpiad;
     }
     return (float)(totalcashpaid - totalbill);
 }
 
 void Print_Result(float remainder){
        if(remainder == 0){
            cout << " thank you so match enjoy  with your owsomn prodects" << endl;
        }else{
            cout << "this is your Remainder " << remainder << endl;
            cout << " thank you so match enjoy  with your owsomn prodects" << endl;
        }
    }
    // ------------------------ 40 -----------
    double  claculateTotalbillAndHisExtentions(int totalbill){
        double  services = 0.01, salse = 0.16;
        return (double)totalbill + services + salse;
    }

        void Result( double Result ){
            cout << " the totalbill after adding the services and salse is " << Result << endl;
        }
        // ------------------------ 38 -----------
        enum enPrime
        {
            prime,
            notPrime
        };
        enPrime isNumberPrime(int number){
            int M = number / 2;
            
            for (int i = 2; i <= M; i++){
                if(number% i == 0){
                    return enPrime::notPrime;
                }
            }
            return enPrime::prime;
        }

           void  printCheackResult(enPrime  numberType,int  number){
            if(numberType == enPrime::prime){

                cout << " you enter " << number << " and that is a prime number " << endl;
            }else{
                
                cout << " you enter " << number << " and that is Not a prime number " << endl;
            }
           }
        void printCheackResult(string result, int number  ){
            cout <<number << " is " << result << endl;
        }
        int main()
        {

            // ------------------------ 36 -----------
            // int firstNum = readPositiveNumber(" please enter the first number ");
            // int secondNum = readPositiveNumber(" please enter the second number ");
            // enOperationType Operation=  ReadOperationType();
            // float result = clclateOperation(firstNum, secondNum, Operation);

            // printCalcuationResult(result);

            // ------------------------ 37 -----------
            //  printSum(sumNumbersUntil99());
            // ------------------------ 38 -----------
            // int number = readPositiveNumber("please enter a number and i will check is it Prime number ");
            // printCheackResult(isNumberPrime(number), number);
            // ------------------------ 39 -----------
            //  int cashpiad = readPositiveNumber("cheack  please  ");
            //  Print_Result(calculateRemander(cashpiad));
            // ------------------------ 40 -----------
            // int totalbill = readPositiveNumber("plese enter your total bill");
            // Result(claculateTotalbillAndHisExtentions(totalbill));

            return 0;
        }