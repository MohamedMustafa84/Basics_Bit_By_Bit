// #include <iostream>
// using namespace std;

// // ---------------------- generic Functions ----------------
// int readPositiveNumber(string message)
// {
//     int number;
//     cout << message << " --> ";
//     cin >> number;
//     cout << endl;
//     while (number <= 0)
//     {
//         cout << " the number most be greater than zero please retry -->";
//         cin >> number;
//         cout << endl;
//     }

//     return number;
// }

// // ----------------------- 5------------------
// int arrSplitDigit[100];

// arrSplitDigit SplitDigit(int Number)
// {
//     int arrSplitDigit[100];
//     int index = 0;
//     int remainder = 0;
//     while (Number > 0)
//     {
//         remainder = Number % 10;
//         Number = Number / 10;
//         arrSplitDigit[index] = remainder;
//         index++;
//     }
//     return arrSplitDigit;
// }

// int PrintReversedNumber(int number)
// {
//     int arrsplitDigit[100];
//     arrsplitDigit = SplitDigit(number);

//     for (int i = 0; i <= arrSplitDigit.length; i++)
//     {
//         cout << arrSplitDigit[i] << endl;
//     }
//     return 0;
// }
// // ----------------------- 6 ------------------

// int SumOFNumberDigits(int Digit){
//     int arrDigitContent[100];
//     arrDigitContent = SplitDigit(Digit);
//     int sum = 0;
//     for (int i = 0; i <= arrDigitContent.lenght; i++){
//         sum += arrDigitContent[i];
//     }
//     return sum;
// }

//     void PrintResult(siring message ,int sum){
//         cout << message << sum << endl;
        
//     }
//     {
//     }
//     // ----------------------- 7 ------------------
//     void PrintReversedDigit(Digit){
//         int arrNumber[100];
//         arrNumber = SplitDigit(Digit);
//         for (int i = 0; i <= arrNumber.length; i++){
//             cout << arrnNumber[i];
//         }
//         cout << endl;
//     }
//     // ----------------------- 8 ------------------
    // int RepeatinCount(int num, int searchItem)
    // {
    //     int arrNumber[100];
    //     arrNumber = SplitDigit(Digit);
    //     int FrequencyCount = 0;
    //     for (int i = 0; i <= arrNumber.length; i++){
        //         if(arrNumber[i]==searchItem )
        //             FrequencyCount++;
        //     }
        //     return FrequencyCount;
        // }
        //     // ----------------------- 9------------------
        void PrintFrequencyCount(int Num){
            int remainder = 0;
            while(remainder>0){
                remainder = Num % 10;
                Num = Num / 10;
                
            }
        }
// int main (){

//     // ----------------------- 5 ------------------
//     int Digit = readPositiveNumber("please enter digit and i will reverse it ");
//     int arrSplitDigit[100];

//     // PrintReversedNumber(Digit);
//     // ----------------------- 6 ------------------
//     Digit = readPositiveNumber("enter anumber and  and i will give you the sum of all numbersin it ");
    
//     PrintResult("the sum of your number content is ",SumOFNumberDigits(Digit));
//     // ----------------------- 7 ------------------
//     Digit = readPositiveNumber("enter number and i will reverse it ");
    // PrintResult (" the reversed Digit is ", ReversedDigit(Digit));
//     // ----------------------- 8 ------------------
    // int num = readPositiveNumber(" Enter Number ");
    // int shearchItem = readPositiveNumber(" Enter number and i will give you  the repeation count for it ");
    // PrintResult("the count of repeation for your number is ", FrequencyCount(num, shearchItem));
//     // ----------------------- 9 ------------------
    // int Num =readPositveNumber(" enter number and i will give you the frequencyCount for each Digit ");
    // PrintFrequencyCount(Num);

    //     return 0;

    // }