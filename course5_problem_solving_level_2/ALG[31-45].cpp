#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

// --------------- generic Functions--------------------
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
// ------------
int readNumber(){
    int Number;
    cout << "please Enter a number --> ";
    cin >> Number;
    return Number;
}

// -----

void addNumberTOArray(int Number, int ArrayOfNumbers[100], int &ArrayLength)
{
    ArrayLength++;
    ArrayOfNumbers[ArrayLength - 1] = Number;
}

// -------------
void PrintArray(int UserArray[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << UserArray[i] << " ";
    }
    cout << endl;
}
// ---------------
void swapNumbers(int &Number1 ,int &Number2 ){
    int temp = Number1;
    Number1 = Number2;
    Number2 = temp;
}

// ----------
int RandomNumber(int from, int to)
{

    return rand() % (to - from + 1) + from;
}
// ----
// void FillArrayRandomly(int Array[100], int length)
// {
//     for (int i = 0; i < length; i++)
//     {
//         Array[i] = RandomNumber(0, 100);
//     }
// }
// -- -- --
void FillArrayRandomly(int Array[100], int length)
      {
          for (int i = 0; i < length; i++)
          {
              Array[i] = RandomNumber(-100, 100);
          }
      }

      // -- -- -- -- -- -- -- -

      int validateNumberInRange(int from, int to, int number)
{
    while (number < from || number > to)
    {
        cout << " the number most be between ["<< from << " - " << to << "] please retry -->";
        cin >> number;
        cout << endl;
    }
    return number;
}
// -- -- -- -- -- -- -- -
bool isOddNumber(int Number){
    return Number % 2 != 0;
}

// ---------
bool isNumberPrime(int number)
{
    int M = round(number / 2);

    for (int counter= 2; counter <= M; counter++)
    {
        if (number % counter == 0)
        {
            return false;
        }
    }
    return true;
}
// -----------------
bool isArrayIncludeNumber(int Number,int Array[100],int ArrayLength){
    for (int i = 0; i < ArrayLength; i++){
        if(Array[i]== Number)
            return true;
    }
    return false;
}

enum enCharType
{
    smallLetter,
    CapitalLetter,
    SpecialCharacter,
    Digit
};
char randomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::smallLetter:
        return char(RandomNumber(97, 122));
    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));
    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));
    case enCharType::Digit:
        return char(RandomNumber(48, 57));
    }
    return 0;
}
string generateWord(short wordLength)
{
    string Word = "";
    for (int i = 0; i < wordLength; i++)
    {
        Word += randomCharacter(enCharType::CapitalLetter);
    }
    return Word;
}
string generateKey()
{
    string Key = "";
    Key = generateWord(4) + "-" + generateWord(4) + "-" + generateWord(4) + "-" + generateWord(4);
    return Key;
}


// -------------------------- 31 -----------------------------------

void FillArrayFromOneToN_Numbers(int arrayOfNumbers[100], int arraysLength){

    for (int i = 0; i <= arraysLength;i++){
        arrayOfNumbers[i] = i + 1;
    }
}

void ShuffleArray(int arrayOfNumbers[100], int arrayLength){
    for (int i = 0; i <= arrayLength; i++)
    {
        int index1 = RandomNumber(1, arrayLength) - 1;
        int index2 = RandomNumber(1, arrayLength) - 1;
        swapNumbers(arrayOfNumbers[index1], arrayOfNumbers[index2]);
    }
}
// -------------------------- 32 -----------------------------------
void CopyReversedArray(int arr1[100], int  arr2[100],int arraysLength){
    for (int i = 0; i < arraysLength; i++){
        arr2[i] = arr1[arraysLength-1-i];
        
    }
}
// -------------------------- 33 -----------------------------------
void fillArrayWithKeys(string arrRandomKeys[100], int keysCount){
    for (int i = 0; i < keysCount; i++){
        arrRandomKeys[i] =generateKey();
    }
}
void printRandomKeys(string arrRandomKeys[100], int keysCount){
    cout << " Array Elements :\n";
    for (int i = 0; i < keysCount; i++)
    {
        cout<<"Array["<<i<<"] : " << arrRandomKeys[i] << "\n";
    }
    cout << endl;
}
// -------------------------- 34 -----------------------------------


    short findNumberPositionInArray(int arr[100],int arrLength,int searchItem){
        
        for (int i = 0; i < arrLength; i++)
        {
            if (searchItem == arr[i])
            {

                return i;
            }
        }
        return -1;
    }
    // -------------------------- 35 -----------------------------------
    bool isNumberInArray(int arr[100], int arrLength, int searchItem)
    {

        return findNumberPositionInArray(arr, arrLength, searchItem) != -1;
    }
   void  PrintIncludingResult(bool isArrayIncludeNumber){
        if(isArrayIncludeNumber==true){
            cout << "Yes The Number Is Found :-) " << endl;
        }else{
            cout << "No The Number Is Not Found :-(" << endl;
        }
    }

    // -------------------------- 36 -----------------------------------
    // enum enReTry
    // {
    //     yes = 1,
    //     No = 2
    // };

    // void addNumberTOArray(int ArrayOfNumbers[100], int ArrayLength)
    // {
    //     ArrayOfNumbers[ArrayLength] = readPositiveNumber("please enter a number ");
    // }
    
    // enReTry Retry(){
    //     short retry = 0;
    //     cout << "Do You Want To do over the Previous Operation ? \n";
    //     cout << "enter [1] to retry or enter [2] to end the Operation\n";
    //     cin >> retry;
    //     retry = validateNumberInRange(1, 2, retry);
    //     return (enReTry)retry;
    // }
    // -------36
    enum enReTry
    {
        yes = 1,
        No = 2
    };

   
    
    void inputUserNumberToArray(int ArrayOfNumbers[100], int &ArrayLength){
        
        bool addMore= true;
        
        do{
            addNumberTOArray(readNumber(), ArrayOfNumbers, ArrayLength);
            cout << "Do You Want To Add More Number [0]:No, [1]:Yes ? \n";
            cin >> addMore;
        } while (addMore);
        
    }
    // -------------------------- 37 -----------------------------------
    void copyArray(int arr1[100], int arrCopy[100],  int arr1Lenght,int &arrCopyLength){
        for (int i = 0; i < arr1Lenght; i++){
            addNumberTOArray(arr1[i], arrCopy, arrCopyLength);
            
        }
    }
    // -------------------------- 38 -----------------------------------
    void copyOddNumbers(int sourceArray[100],int oddNumbers[100], int sourceArrayLength, int &oddNumbersLength){
        for (int i = 0; i < sourceArrayLength; i++){
            if (isOddNumber(sourceArray[i]))
            addNumberTOArray(sourceArray[i], oddNumbers, oddNumbersLength);
            
        }
    }
    // -------------------------- 39 -----------------------------------
    void copyPrimeNumbers(int sourceArray[100], int primeNumbers[100], int sourceArrayLength,int &primeNumbersLength){
        for (int i = 0; i < sourceArrayLength; i++)
        {
            if (isNumberPrime(sourceArray[i]))
                addNumberTOArray(sourceArray[i], primeNumbers, primeNumbersLength);
        }
    }

    // -------------------------- 40 -----------------------------------
    // void addsourceArrayElements(int sourceArray[10]){
    //     sourceArray[0] = 10;
    //     sourceArray[1] = 10;
    //     sourceArray[2] = 10;
    //     sourceArray[3] = 20;
    //     sourceArray[4] = 20;
    //     sourceArray[5] = 20;
    //     sourceArray[6] = 30;
    //     sourceArray[7] = 30;
    //     sourceArray[8] = 30;
    //     sourceArray[9] = 40;
    // } 
    
    // void getDistinctNumbers(int sourceArray[10], int distinctArrNumbers[10],int sourceArrayLength, int &distinctLength){
    //     for (int i = 0; i < sourceArrayLength; i++){
    //         if (isArrayIncludeNumber(sourceArray[i], distinctArrNumbers, distinctLength) == false )
    //             addNumberTOArray(sourceArray[i], distinctArrNumbers, distinctLength);
    //     }
    // }
    // ------------------ anther Solution
    void getDistinctNumbers(int sourceArray[10], int distinctArrNumbers[10], int sourceArrayLength, int &distinctLength)
    {
        for (int i = 0; i < sourceArrayLength; i++)
        {
            if (findNumberPositionInArray(distinctArrNumbers, distinctLength, sourceArray[i]) == -1)
            addNumberTOArray(sourceArray[i], distinctArrNumbers, distinctLength);
        }
    }
    // -------------------------- 41 -----------------------------------
    void addsourceArrayElements(int sourceArray[6])
    {
        sourceArray[0] = 1;
        sourceArray[1] = 2;
        sourceArray[2] = 3;
        sourceArray[3] = 3;
        sourceArray[4] = 2;
        sourceArray[5] = 1;
        
    }
     bool isPalindromeArray(int sourceArray[100],int ArrayLength){
         for (int i = 0; i < ArrayLength; i++){
            if(sourceArray[i] != sourceArray[ArrayLength-1 -i]){
                return false;
            }
         }
        return true;
     }


    void checkPalindromeArray(int sourceArray[100],int ArrayLength)
     {
         if (isPalindromeArray(sourceArray, ArrayLength))
             cout << "This Array Is Palindrome " << endl;
        else
            cout << "This Array is Not A Palindrome Array" << endl;
     }

     // -------------------------- 42 -----------------------------------
     short countOddNumbers(int sourceArray[100],int sourceArrayLength){
         short oddNumbers = 0;
         for (int i = 0; i < sourceArrayLength; i++){
             if(sourceArray[i]%2 != 0)
             oddNumbers++;
            }
            return oddNumbers;
        }
        // -------------------------- 43 -----------------------------------
        short countEvenNumbers(int sourceArray[100], int sourceArrayLength)
        {
            short EvenNumbers = 0;
            for (int i = 0; i < sourceArrayLength; i++)
            {
                if (sourceArray[i] % 2 == 0)
                EvenNumbers++;
            }
            return EvenNumbers;
        }
    // -------------------------- 44 -----------------------------------
    short countPositiveNumbers(int sourceArray[100],int sourceArrayLength){
        short positiveNumbers = 0;
        for (int i = 0; i < sourceArrayLength; i++){
            if(sourceArray[i]>=0)
            positiveNumbers++;
        }
        return positiveNumbers;
    }
    // -------------------------- 45 -----------------------------------
    short countNegativeNumbers(int sourceArray[100], int sourceArrayLength)
    {
        short NegativeNumbers = 0;
        for (int i = 0; i < sourceArrayLength; i++)
        {
            if (sourceArray[i] < 0)
                NegativeNumbers++;
        }
        return NegativeNumbers;
    }

        int main()
        {
            srand((unsigned)time(NULL));
            // -------------------------- 31 -----------------------------------
            // fill array with ordered numbers from 1 to N and print it and after that shuffle this array and print it

            // int arrayOfNumbers[100];

            // cout << "fill array with ordered numbers from 1 to N and print it and after that shuffle this array and print it \n";
            // int arraysLength = readPositiveNumber("Enter How Many Number You Need ");

            // FillArrayFromOneToN_Numbers(arrayOfNumbers, arraysLength);
            // cout << "Array Elements Before Shuffle :\n";
            // PrintArray(arrayOfNumbers, arraysLength);

            // ShuffleArray(arrayOfNumbers, arraysLength);
            // cout << "\nArray Elements After Shuffle :\n";
            // PrintArray(arrayOfNumbers, arraysLength);
            // cout << endl;
            // -------------------------- 32 -----------------------------------
            // fill array with max size 100 with random numbers form 1 to 100 ,copy it anther array in reverse order and print it
            // int arr1[100];
            // int arr2[100];

            // int arraysLength = readPositiveNumber("Enter How Many Number You Need ");

            // FillArrayRandomly(arr1, arraysLength);
            // CopyReversedArray(arr1, arr2, arraysLength);

            // cout << "Array One Elements :\n";
            // PrintArray(arr1, arraysLength);
            // cout << "\nArray Two Elements After copying array in reversed order :\n";
            // PrintArray(arr2, arraysLength);
            // cout << endl;
            // -------------------------- 33 -----------------------------------
            // read how many key to generate and fill them in array then print the in the screen
            // string  arrRandomKeys[100];
            // int keysCount = readPositiveNumber("How Many Key do you need");

            // fillArrayWithKeys(arrRandomKeys, keysCount);
            // printRandomKeys(arrRandomKeys, keysCount);
            // -------------------------- 34 -----------------------------------
            // fill array with max size 100 with random numbers from 1 to 100 , read number and return its index in array if found otherwise retrun -1
            // int  arr[100];
            // int arrLength = readPositiveNumber("How Many number do you need");

            // FillArrayRandomly(arr, arrLength);
            // cout << "Array Elements : \n";
            // PrintArray(arr, arrLength);

            // int searchItem = readPositiveNumber("please enter a number to search for");

            // short NumberPosition = findNumberPositionInArray(arr, arrLength,searchItem);
            // if (NumberPosition== -1){
            //     cout << "################# THE RESULT ######################\n";
            //     cout << "The Number Your looking for : " << searchItem << "\n";
            //     cout << "the Number is not found :-(" << endl;
            // }else{
            //     cout << "################# THE RESULT ######################\n";
            //     cout << "The Number Your looking for : " << searchItem << "\n";
            //     cout << "the number found at position : " << NumberPosition << "\n";
            //     cout << "the number found at order : " << NumberPosition +1 << endl;
            // }
            // -------------------------- 35 -----------------------------------
            // fill array with max size 100 with random numbers from 1 to 100 ,read number and print its found or not found
            // int arr[100];
            // int arrLength = readPositiveNumber("How Many number do you need");

            // FillArrayRandomly(arr, arrLength);
            // cout << "Array Elements : \n";
            // PrintArray(arr, arrLength);

            // int searchItem = readPositiveNumber("please enter a number to search for");

            // cout << "the number you are looking for is: " << searchItem << "\n";
            // PrintIncludingResult(isNumberInArray(arr, arrLength, searchItem));
            // -------------------------- 36 -----------------------------------
            // dynamically read numbers and save them in an array Max size of Aarray is 100  allcate simi-dynamic array length
            // int ArrayOfNumbers[100];
            // int ArrayLength = 0;

            // inputUserNumberToArray(ArrayOfNumbers,ArrayLength);

            // cout << "############_THE_RESULT_##############\n";
            // cout << "Array Length :" << ArrayLength << "\n";
            // cout << "Array Elements :\n";
            // PrintArray(ArrayOfNumbers, ArrayLength);
            // -------------------------- 37 -----------------------------------
            // copy Array Element using add Array elements
            // int arr1[100];
            // int arrCopy[100];
            // int arrCopyLength = 0;

            // int Arr1Length = readPositiveNumber("how many number you need");
            // FillArrayRandomly(arr1, Arr1Length);
            // copyArray(arr1, arrCopy, Arr1Length,arrCopyLength);
            // cout << "########## THE RESULT ###########\n";
            // cout << "Array 1 elements  :\n";
            // PrintArray(arr1, Arr1Length);
            // cout << "Array array 2 after copy :\n";
            // PrintArray(arrCopy, Arr1Length);
            // -------------------------- 38 -----------------------------------
            // copy odd Number from the Array
            // int sourceArray[100];
            // int oddNumbers[100];
            // int sourceArrayLength = readPositiveNumber("How many Number do you need");
            // int oddNumbersLength = 0;

            // FillArrayRandomly(sourceArray, sourceArrayLength);
            // copyOddNumbers(sourceArray, oddNumbers, sourceArrayLength, oddNumbersLength);

            // cout << "########## THE RESULT ###########\n";
            // cout << "source Array elements  :\n";
            // PrintArray(sourceArray, sourceArrayLength);
            // cout << "All the Odd Numbers in the source Array :\n";
            // PrintArray(oddNumbers, oddNumbersLength);
            // -------------------------- 39 -----------------------------------
            // copy only the prime Numbers
            // int sourceArray[100];
            // int primeNumbers[100];
            // int sourceArrayLength = readPositiveNumber("How many Number do you need");
            // int primeNumbersLength = 0;

            // FillArrayRandomly(sourceArray, sourceArrayLength);
            // copyPrimeNumbers(sourceArray, primeNumbers, sourceArrayLength, primeNumbersLength);

            // cout << "########## THE RESULT ###########\n";
            // cout << "source Array elements  :\n";
            // PrintArray(sourceArray, sourceArrayLength);
            // cout << "All the Prime Numbers in the source Array :\n";
            // PrintArray(primeNumbers, primeNumbersLength);
            // -------------------------- 40 -----------------------------------
            // ---------- copy distinct Numbers
            // int sourceArray[10];
            // int distinctArrNumbers[10];
            // int sourceArrayLength = 10;
            // int distinctLength = 0;

            // // addsourceArrayElements(sourceArray);
            // // getDistinctNumbers(sourceArray, distinctArrNumbers, sourceArrayLength, distinctLength);
            // // ------ anther solution -----
            // addsourceArrayElements(sourceArray);
            // getDistinctNumbers(sourceArray, distinctArrNumbers, sourceArrayLength, distinctLength);

            // cout << "########## THE RESULT ###########\n";
            // cout << "source Array elements  :\n";
            // PrintArray(sourceArray, sourceArrayLength);
            // cout << "All The Distinct Numbers in the source :\n";
            // PrintArray(distinctArrNumbers, distinctLength);
            // -------------------------- 41 -----------------------------------
            // check if Array Palindrome or Not
            // int sourceArray[6];
            // int sourceArrayLength = 6;
            // addsourceArrayElements(sourceArray);
            // cout << "########## THE RESULT ###########\n";
            // cout << "source Array elements  :\n";
            // PrintArray(sourceArray, sourceArrayLength);
            // checkPalindromeArray(sourceArray, sourceArrayLength);
            // -------------------------- 42 -----------------------------------
            // count Array Odd Numbers
            //  int sourceArray[100];
            //  int sourceArrayLength = readPositiveNumber("How many Number do you need");

            //  FillArrayRandomly(sourceArray, sourceArrayLength);

            //  cout << "########## THE RESULT ###########\n";
            //  cout << "source Array elements  :\n";
            //  PrintArray(sourceArray, sourceArrayLength);
            //  cout << "the odd numbers in the Array is  : " << countOddNumbers(sourceArray, sourceArrayLength) << endl;
            // -------------------------- 43 -----------------------------------
            //  count Array even  Numbers
            //   int sourceArray[100];
            //   int sourceArrayLength = readPositiveNumber("How many Number do you need");

            //   FillArrayRandomly(sourceArray, sourceArrayLength);

            //   cout << "########## THE RESULT ###########\n";
            //   cout << "source Array elements  :\n";
            //   PrintArray(sourceArray, sourceArrayLength);
            //   cout << "the Even numbers in the Array is  : " << countEvenNumbers(sourceArray, sourceArrayLength) << endl;

            // -------------------------- 44 -----------------------------------
            //   fill array with max size 100 with random numbers from -100 to 100, the print the count of positive numbers
            // //  positive numbers count
            
            // int sourceArray[100];
            // int sourceArrayLength = readPositiveNumber("How many Number do you need");

            // FillArrayRandomly(sourceArray, sourceArrayLength);

            // //   cout << "########## THE RESULT ###########\n";
            // cout << "source Array elements  :\n";
            // PrintArray(sourceArray, sourceArrayLength);
            // cout << "the count of the  positive number in your array : " << countPositiveNumbers(sourceArray, sourceArrayLength);

            // -------------------------- 45-----------------------------------
            //  Negative numbers count

            // int sourceArray[100];
            // int sourceArrayLength = readPositiveNumber("How many Number do you need");

            // FillArrayRandomly(sourceArray, sourceArrayLength);

            // //   cout << "########## THE RESULT ###########\n";
            // cout << "source Array elements  :\n";
            // PrintArray(sourceArray, sourceArrayLength);
            // cout << "the count of the  Negative number in your array : " << countNegativeNumbers(sourceArray, sourceArrayLength);

            return 0;
        }