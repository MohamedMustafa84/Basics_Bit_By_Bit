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

// -------------------------12--------------

// void invertNumber(int Number){
//     while (Number>0){
//         for (int i = 1; i <= Number; i++)
//         {
//             cout << Number;
//         }
//         cout << endl;
//         Number--;
//     }
        
// }

// ---------------
void invertNumber(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j= 1;  j<= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
    cout << endl;
}

// -------------------------13-------------

// void PrintNumberPattern(int Number)
// {
    //     int NumberPattern = 1;
    //     while (Number > 0)
    //     {
        //         for (int i = 0; i < NumberPattern; i++)
        //         {
            //             cout << NumberPattern;
            //         }
            //         cout << endl;
            //         NumberPattern++;
            //         Number--;
            //     }
            // }
            // -----------------
    void PrintNumberPattern(int Number)
        {
            int NumberPattern = 1;
            for (int i = 1; i <=Number; i++)
            {
                for (int j = 1; j <=i; j++)
                {
                    cout << i;
                }
                cout << endl;
                NumberPattern++;
            }
        }
    // -------------------------14--------------
    // void PrintInvertedLetterPattern(int Number)
    // {
    //     int EnglishLetterCount = 26;
    //     if (Number < EnglishLetterCount)
    //     {
    //         int LetterPattern = Number + 64;
    //         while (Number > 0)
    //         {
    //             for (int i = 1; i <= Number; i++)
    //             {
    //                 cout << char(LetterPattern) << " ";
    //             }
    //             cout << endl;
    //             LetterPattern--;
    //             Number--;
    //         }
    //     }
    //     else
    //     {
    //         cout << " you entred unvalid Number English has only " << EnglishLetterCount << " Letter" << endl;
    //         Number = readPositiveNumber("please retry ");
    //         PrintInvertedLetterPattern(Number);
    //     }
    // }
    int validateLetterNumber(int Number){

        int EnglishLettersCount = 26;
        while(Number > EnglishLettersCount){
            cout << " you entred unvalid Number English has only " << EnglishLettersCount << " Letters" << endl;
            Number = readPositiveNumber("please retry ");
        }
        return  Number;
    }
    void PrintInvertedLetterPattern(int Number)
    {
        
        for (int i = 65 + Number - 1; i >= 65; i--)

        {
            for (int j = 1; j <= Number - ((65 + Number - 1)-i); j++)
            {
                cout << char(i) << " ";
            }
            cout << endl;
        } 
        
        
    }
    
    // -------------------------15--------------
    void PrintLettersPattern(int Number){
        for (int i = 65; i <= 65 + Number - 1; i++){
            for (int j = 1; j <= Number - ((65 + Number - 1)-i); j++){
                cout << char(i) << " ";
            }
            cout <<"\n";
        }
        cout << endl;
    }

        int
        main()
    {
        // -------------------------12--------------
        // int Number = readPositiveNumber("Enter number and i will give you the number inverted ");
        // invertNumber(Number);
        // -------------------------13--------------
        // int Number = readPositiveNumber("Enter number and i will give you the number Pattern ");
        PrintNumberPattern(Number);
        // -------------------------14--------------
        // int Number = readPositiveNumber("Enter number and i will give you the inverted letter pattern ");
        // PrintInvertedLetterPattern(validateLetterNumber( Number));
        // -------------------------15--------------
        PrintLettersPattern(validateLetterNumber(readPositiveNumber("Enter number and i will give you  the letters pattern from it ")));
    }