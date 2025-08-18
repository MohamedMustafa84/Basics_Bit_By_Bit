#include <iostream>
using namespace std;


// -----------------13------------------
void readNumbers(int &num1,int &num2){
    cout << "plz enter number 1 -->";
    cin >> num1;
    cout << "\nplz enter number 2 -->";
    cin >> num2;
    cout << endl;
}
int Maxof2Nums(int num1,int num2){
    if (num1>num2)
        return num1;
    else
        return num2;
}

void printresult(int maxNum){
    cout << " the Max Number is " << maxNum << endl;
}
// ------------------- 14------------------
void readThreeNum(int& num1, int& num2, int& num3){
    cout << "Plz Enter  the first number  -->";
    cin >> num1;
    cout << "\nPlz Enter the second number  -->";
    cin >> num2;
    cout << "\nPlz Enter the thred number -->";
    cin >> num3;
}
int maxofthreenumber(int num1, int num2, int num3){

    if(num1>num2){
        if(num1>num3){
            return num1;
        }else{
            return num3;
        }

    }else{
        if(num2>num3){
            return num2;
        }else{
            return num3;
        }
    }

}

void printMaxOfNumbers(int MaxNumber){
    cout << "\n the Max OF Your Three Number Is " << MaxNumber << endl;
}
void recalcForThreeTime(int num1 ,int num2 ,int num3 ){
    string retry;

    int Triesleft = 2;

       do{

        cout << " you have " << Triesleft + 1 << " trys do you wnat to retry ? (yes or no ) " << endl;
        cin >> retry;
        readThreeNum(num1, num2, num3);
       printMaxOfNumbers(maxofthreenumber(num1, num2, num3));
        Triesleft --;

        cout << " ######################################  \n" << endl;
    } while (Triesleft > 0 && retry == "yes");

    cout<< "---- your trys count is done ---------" << endl;
    cout <<"---- catch you on the flip side ------" << endl;

}

// ------------------- 15------------------
void ReadThe2Nums(int & num1 , int & num2){
    cout <<"please enter the first number -->" ;
    cin >> num1;
    cout << "please enter the second number -->";
    cin >> num2;
}

void SwapTwoNumbers(int &num1, int &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
void PrintSwapingResult(int num1,int num2){
    cout << "the value of first number after the swaping is " << num1 << endl;
    cout << "the value of second number after the swaping is " << num2 << endl;
}

// ------------------- 16------------------

void GetrectangleDaimantions(float& width, float& height){
    cout << "please enter the rectangle width in cm -->";
    cin >> width;
    cout << "\nplease enter the rectangle height in cm -->";
    cin >> height;
    cout << endl;
}

float CalcRectangleArea(float width,float  height){
    float RectangleArea;
    RectangleArea = width * height;
    return RectangleArea;
}
void PrintRectangleArea(float RectangleArea ){
    cout << "the Area Of Your Rectangle is " << RectangleArea<<" cm "<<endl;
}

    int
    main()
{
    // ------------------- 13------------------
    // int num1, num2;
    // readNumbers(num1,num2);
    // printresult(Maxof2Nums(num1, num2));
    // ------------------- 14------------------
    // اقرا ثلاثة ارقام  ثم قم بطباعة الرقم الاكبر منبينهم
    //     int num1, num2, num3;
    //     readThreeNum(num1, num2, num3);
    //    printMaxOfNumbers(maxofthreenumber(num1, num2, num3));
    //     recalcForThreeTime(num1, num2, num3);

    // ------------------- 15------------------
    // int num1,num2;
    // ReadThe2Nums(num1, num2);
    // SwapTwoNumbers(num1, num2);
    // PrintSwapingResult(num1, num2);


    // ------------------- 16------------------
    // حساب مساحة المستطيل
    // float width, height;
    // GetrectangleDaimantions(width, height);
    // PrintRectangleArea(CalcRectangleArea(width, height));

    return 0;
}