#pragma once
#include <iostream>
#include "ClsDate.h"
using namespace std ;

class clsUtil{
    public :

    enum enCharType{
        SmallLetter=1,
        CapitalLetter=2,
        Digit=3,
        MixChars=4,
        SpecialCharacter=5
    };


    static void Srand(){
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        if (CharType == MixChars)
        {
            // Capital/Small/Digits only
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {

        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        default:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static void Swap(int &A, int &B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double &A, double &B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool &A, bool &B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char &A, char &B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string &A, string &B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate &A, clsDate &B)
    {
        clsDate::SwapDates(A, B);
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout <<"\t";
        }
        return t;
    }

    static string EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }


    
static string ConvertNumberToText(int Number){
    
    if(to_string(Number) ==""){

        cout << "Error the  Number is Empty Empty !";
    }

    if(Number>=1 && Number<=19){
        string arrTexts[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twolf", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arrTexts[Number - 1];
    }else if(Number >= 20 && Number <= 99)
        {
            string arrTexts[] = {"","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            return arrTexts[(Number/10)-1] + " " + ConvertNumberToText(Number%10);
        }
        else if (Number >= 100 && Number <= 999)
        {
            string arrTexts[] = {"OneHandred", "TwoHandred", "ThreeHandred", "FourHandred", "FiveHandred", "SixHandred", "SevenHandred", "EightHandred", "NineHandred"};
             return arrTexts[(Number / 100) - 1]+" "+ ConvertNumberToText(Number % 100);
        }
        else if (Number >= 1000 && Number <= 19000)
        {
            string arrTexts[] = {"OneThasone", "TwoThasone", "ThreeThasone", "FourThasone", "FiveThasone", "SixThasone", "SevenThasone", "EightThasone", "NineThasone", "TenThasone", "ElevenThasone", "TwolfThasone", "ThirteenThasone", "FourteenThasone", "FifteenThasone", "SixteenThasone", "SeventeenThasone", "EighteenThasone", "NineteenThasone"};
            return arrTexts[(Number / 1000) - 1] + " " + ConvertNumberToText(Number % 1000);
        }
        else if (Number >= 20000 && Number <= 99000)
        {
            string arrTexts[] = {"", "TwentyThasone", "ThirtyThasone", "FortyThasone", "FiftyThasone", "SixtyThasone", "SeventyThasone", "EightyThasone", "NinetyThasone"};
            return arrTexts[(Number / 10000) - 1] + " " + ConvertNumberToText(Number % 10000);
        }
        else if (Number >= 100000 && Number <= 999000)
        {
            string arrTexts[] = {"OneHandredThasone", "TwoHandredThasone", "ThreeHandredThasone", "FourHandredThasone", "FiveHandredThasone", "SixHandredThasone", "SevenHandredThasone", "EightHandredThasone", "NineHandredThasone"};
            return arrTexts[(Number / 100000) - 1] + " " + ConvertNumberToText(Number % 100000);
        }else if (Number >= 1000000 && Number <= 19000000)
        {
            string arrTexts[] = {"OneMillion", "TwoMillion", "ThreeMillion", "FourMillion", "FiveMillion", "SixMillion", "SevenMillion", "EightMillion", "NineMillion", "TenMillion", "ElevenMillion", "TwolfMillion", "ThirteenMillion", "FourteenMillion", "FifteenMillion", "SixteenMillion", "SeventeenMillion", "EighteenMillion", "NineteenMillion"};
            return arrTexts[(Number / 1000000) - 1] + " " + ConvertNumberToText(Number % 1000000);
        }
        else if (Number >= 20000000 && Number <= 99000000)
        {
            string arrTexts[] = {"", "TwentyMillion", "ThirtyMillion", "FortyMillion", "FiftyMillion", "SixtyMillion", "SeventyMillion", "EightyMillion", "NinetyMillion"};
            return arrTexts[(Number / 10000000) - 1] + " " + ConvertNumberToText(Number % 10000000);
        }
        else if (Number >= 100000000 && Number <= 999000000)
        {
            string arrTexts[] = {"OneHandredMillion", "TwoHandredMillion", "ThreeHandredMillion", "FourHandredMillion", "FiveHandredMillion", "SixHandredMillion", "SevenHandredMillion", "EightHandredMillion", "NineHandredMillion"};
            return arrTexts[(Number / 100000000) - 1] + " " + ConvertNumberToText(Number % 100000000);
        }

        return "Out OF Range";
    }
};