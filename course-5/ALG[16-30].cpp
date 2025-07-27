#include <iostream>
#include <string>
# include <cstdlib>
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

// ------------------------------------- 16------------------------



void PrintWorldFromAAA_To_ZZZ(){
    string word = "";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++){
            for (int k = 65; k <= 90;k++){
                word= word+ char(i);
                word= word+ char(j);
                word= word+ char(k);
                cout << word << endl;
                word = "";
            }
        }
    }
}
// -------------------------------------- 17 ---------------
string readPassword(){
    string password;
    cout << "please enter a 3 Letter password (all capital)>>";
    cin >> password;
    return password;
}
bool guessPassword(string password){

    string currentWord = "";
    int trial = 1;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
               currentWord= currentWord + char(i);
                currentWord = currentWord + char(j);
                currentWord = currentWord + char(k);
                cout<<"Trial["<<trial<<"] : "<< currentWord << endl;
                if(currentWord == password){
                    cout << "Password is " << currentWord << "\n";
                    cout <<" Found After "<<trial<<" trial(s)" <<endl;
                    return true;
                }
                currentWord = "";
                trial++;
            }
        }
    }
    return false;
}
// -------------------------------------- 18 ---------------
string readText(){
    string text;
    cout << " please enter tex and to encrypted it  --> ";
    getline(cin, text);
    return text;
}

string TextEncrytion(string text, short encrytionKey){
    for (int i =0; i < text.length(); i++){
        text[i] = char((int)text[i] + encrytionKey);
    }
    return text ;
}

string DecryptText(string Text, short EncryptionKey)
{
    // Loop through each character of the text.
    // Note: Using "<= Text.length()" will process one extra character (the null terminator).
    for (int i = 0; i <Text.length(); i++)
    {
        // Convert the current character to its ASCII integer value,
        // subtract the encryption key, cast back to char, and assign it back.
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text; // Return the decrypted text.
}
// -------------------------------------- 19 ---------------
int RandomNumber(int from ,int to){

    return rand() % (to - from + 1) + from;
}

// -------------------------------------- 20 ---------------
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
    return char(RandomNumber(97,122));
    case enCharType::CapitalLetter:
    return char(RandomNumber(65,90));
    case enCharType::SpecialCharacter:
    return char(RandomNumber(33,47));
    case enCharType::Digit:
    return  char(RandomNumber(48,57));
    }
    return 0;
}
// -------------------------------------- 21 ---------------
string generateWord(short wordLength){
    string Word = "";
    for (int i = 0; i < wordLength; i++)
    {
        Word += randomCharacter(enCharType::CapitalLetter);
    }
    return Word;
}
string generateKey(){
    string Key = "";
    Key = generateWord(4) + "-" + generateWord(4) + "-" + generateWord(4) + "-" + generateWord(4);
    return Key;
}
void PrintRandomKeys(int keysCount){
    for (int i = 1; i <= keysCount; i++){
        cout << "key [" << i << "] :";
        cout << generateKey() << endl;
    }
}
// -------------------------------------- 22 ---------------
void readArrayElements(int UserArray[100] ,int length){
    cout << "please enter your array elements:\n";
    for (int i = 0; i < length;i++){
        cout << "Element [" << i + 1 << "]: ";
        cin >> UserArray[i];
        cout << "\n";
    }
}
int RepeatedCount(int UserArray[100], int length,int searchNumber){
    int repeatCount = 0;
    for (int i = 0; i < length;i++){
        if (UserArray[i] == searchNumber)
        {
            repeatCount++;
        }
    }
    return repeatCount;
}
void PrintArray(int UserArray[100] , int arrayLength){
    for (int i = 0; i < arrayLength; i++)
    {
        cout << UserArray[i] << " ";
    }
    cout << endl;
} 

void PrintRepetatioCountResult ( int UserArray[100] , int arrayLength, int searchNumber)
{
    PrintArray(UserArray, arrayLength);
    cout << searchNumber << " is repeated " << RepeatedCount(UserArray, arrayLength, searchNumber) << " Time(s)" << endl;
}
// -------------------------------------- 23 ---------------
void FillArrayRandomly( int Array[100], int length){
    for (int i = 0; i < length; i++)
    {
        Array[i] = RandomNumber(0, 100);
    }
}
// -------------------------------------- 24---------------
int  MaxArrayNumber(int OriginalArray[100],int ArrayLength){
    int MaxNumber = 0;
    for (int i = 0; i < ArrayLength; i++){
        if(OriginalArray[i]>MaxNumber){
            MaxNumber = OriginalArray[i];
        }
    }
    return MaxNumber;
}
// -------------------------------------- 25 ---------------
int MinNumberInArray(int OriginalArray[100], int ArrayLength)
{
    int MinNumber = OriginalArray[0];
    for (int i = 0; i < ArrayLength; i++)
    {
        if (OriginalArray[i] < MinNumber)
        {
            MinNumber = OriginalArray[i];
        }
    }
    return MinNumber;
}

// -------------------------------------- 26 ---------------
int SumArray(int OriginalArray[100], int ArrayLength)
{
    int sum = 0;
    int MinNumber = OriginalArray[0];
    for (int i = 0; i < ArrayLength; i++)
    {
        sum += OriginalArray[i];
    }
    return sum;
}
// -------------------------------------- 27 ---------------
float calculateArrayElements(int OriginalArray[100],int ArrayLength){
    return (float)SumArray(OriginalArray, ArrayLength) / ArrayLength;
}
// -------------------------------------- 28 ---------------
void CopyArray(int OriginalArray[100],int destinationArray[100], int ArrayLength){
    for (int i = 0; i < ArrayLength; i++){
        destinationArray[i] = OriginalArray[i];
    }
}
// -------------------------------------- 29 ---------------
void CopyPrimeNumberOnly(int OriginalArray[100], int PrimeNumbers[50], int ArrayLength,int& Array2Length)
{
    int index = 0;
    for (int i = 0; i < ArrayLength; i++){
        if (isNumberPrime(OriginalArray[i])==enPrimeNotprime::prime){
            PrimeNumbers[index] = OriginalArray[i];
            index++;
        }
    }
    Array2Length = --index +5;
}
// -------------------------------------- 30 ---------------
void sumTwoArrays(int ArrayOne[100], int ArrayTwo[100], int ArrSum[100],int ArraysLength){
    for (int i = 0; i < ArraysLength;i++){
        ArrSum[i] = ArrayOne[i] + ArrayTwo[i];
    }
}
int main()
{
    // -------------------------------------- 16 ---------------
    // PrintWorldFromAAA_To_ZZZ();
    // -------------------------------------- 17 ---------------
    // guessPassword(readPassword());
    // -------------------------------------- 18 ---------------
    // text Encryption
    // string text = readText();
    //  const short  encrytionKey = readPositiveNumber(" Enter Encrytion key");
    //  string TexAfterEncryption = TextEncrytion(text, encrytionKey);
    //  cout << " Text Before Encryption : " << text << endl;
    //  cout << " Text after Encrytion :" <<TexAfterEncryption << endl;
    //  cout << " Text after Decrypt : "  << DecryptText(TexAfterEncryption, encrytionKey);
    // -------------------------------------- 19 ---------------
    // print random number in  spacifec range
    srand((unsigned)time(NULL));
    // cout << RandomNumber(1, 20) << endl;
    // cout << RandomNumber(1, 20) << endl;
    // cout << RandomNumber(1, 20) << endl;
    // -------------------------------------- 20 ---------------
    // cout << randomCharacter(enCharType::CapitalLetter) << endl;
    // cout << randomCharacter(enCharType::smallLetter) << endl;
    // cout << randomCharacter(enCharType::SpecialCharacter) << endl;
    // cout << randomCharacter(enCharType::Digit) << endl;
    // -------------------------------------- 21 ---------------
    // generate  random key
    
    // PrintRandomKeys(readPositiveNumber("how many keys do you need"));
    // -------------------------------------- 22---------------
    // int UserArray[100];
    // int arrayLength = readPositiveNumber("Please enter the Array Length");
    // readArrayElements(UserArray, arrayLength);
    // int searchNumber = readPositiveNumber("Enter the number you need to search about it ");
    // PrintRepeatCountResult(UserArray, arrayLength, searchNumber);
    // -------------------------------------- 23---------------
    // int OriginalArray[100];
    // int ArrayLength = readPositiveNumber("How many element do you need");
    // FillArrayRandomly(OriginalArray, ArrayLength);
    //  PrintArray(OriginalArray, ArrayLength);
   
    // -------------------------------------- 25---------------
    // int OriginalArray[100];
    // int ArrayLength = readPositiveNumber("How many element do you need");
    // FillArrayRandomly(OriginalArray, ArrayLength);
    // PrintArray(OriginalArray, ArrayLength);
    // cout << " the min Number is : " << MinNumberInArray(OriginalArray, ArrayLength) << endl;
    // -------------------------------------- 26---------------
    // sum Array Elements
    // int OriginalArray[100];
    // int ArrayLength = readPositiveNumber("How many element do you need");
    // FillArrayRandomly(OriginalArray, ArrayLength);
    // PrintArray(OriginalArray, ArrayLength);
    
    // cout << "the sum of all Array elements is :";
    // cout << SumArray(OriginalArray, ArrayLength) << endl;
    // -------------------------------------- 27---------------
    // Calculate the Avarage
    // int OriginalArray[100];
    // int ArrayLength = readPositiveNumber("How many element do you need");
    // FillArrayRandomly(OriginalArray, ArrayLength);
    // PrintArray(OriginalArray, ArrayLength);
    // cout << " the Avarage of the Array elements is :";
    // cout << calculateArrayElements(OriginalArray, ArrayLength) << endl;
    // -------------------------------------- 28---------------
    // copy Array
    // int OriginalArray[100];
    // int destinationArray[100];
    // int ArrayLength = readPositiveNumber("How many element do you need");
    // FillArrayRandomly(OriginalArray, ArrayLength);
    // CopyArray(OriginalArray,destinationArray, ArrayLength);
    // cout << "Original Array : ";
    // PrintArray(OriginalArray, ArrayLength);
    // cout << "\n Array elemnets after copy : ";
    // PrintArray(destinationArray, ArrayLength);
    // cout << endl;
    // -------------------------------------- 29---------------
    // int OriginalArray[100];
    // int PrimeNumbers[50];
    // int Array2length = 0;
    // int ArrayLength = readPositiveNumber("Enter how many random number do you need also i will give you the all prime number from it ");
    // FillArrayRandomly(OriginalArray, ArrayLength);
    // CopyPrimeNumberOnly(OriginalArray, PrimeNumbers, ArrayLength, Array2length);
    // cout << "Original Array : ";
    // PrintArray(OriginalArray, ArrayLength);
    // cout << "\n  the prime Numbers form your array are  : ";
    // PrintArray(PrimeNumbers, Array2length);
    // cout << endl;
    // -------------------------------------- 30---------------
    // int ArrayOne[100];
    // int ArrayTwo[100];
    // int ArrSum[100];
    // int ArraysLength = readPositiveNumber("Enter how many random number do you need and i will generate two Array Randomly and sum them ");
    // FillArrayRandomly(ArrayOne,ArraysLength);
    // FillArrayRandomly(ArrayTwo,ArraysLength);
    // sumTwoArrays(ArrayOne, ArrayTwo, ArrSum, ArraysLength);
    // cout << "Array One Elements  : \n";
    // PrintArray(ArrayOne,ArraysLength);
    // cout << "\nArray Two Elements  : \n";
    // PrintArray(ArrayTwo,ArraysLength);
    // cout << "\n Sum Of Array One And Array Two Elements  : \n";
    // PrintArray(ArrSum, ArraysLength);
    // cout << endl;

    return 0;
}