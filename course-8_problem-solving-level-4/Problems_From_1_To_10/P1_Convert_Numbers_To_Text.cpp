#include <iostream>
#include "../../MyLib.h"
using namespace std;


string ConvertNumberToText(int Number){
    
    if(to_string(Number) ==""){
        Number = UserInputs::ReadPositiveNumber("The Input Cannot Be Empty Please Enter A Number :");
        ConvertNumberToText(Number);
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


int main(){
    
    // Problem 1 Convert Number to Word 
// Write a program to read a number and print the text of that number

char Answer = 'Y';
do{
        int number = UserInputs::ReadPositiveNumber("Please Enter A Number ?");

        cout <<"The Text Of The Number is : "<< ConvertNumberToText(number);
        cout << "\nDo You Want To Convert Anther Number ? ";
        cin >> Answer;
    } while (toupper(Answer) == 'Y');
   
    


    return 0;
}