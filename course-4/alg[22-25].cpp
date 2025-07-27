#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14159265389793238f;
void GetTheRange(int& From,int&  To){
    cout << "enter the Range start -->";
    cin >> From;
    cout << "enter the Range end -->";
    cin >> To;
}

    void ReadNumber(int from,int to  ,int& number )
{
    cout <<"Enter a Number between " <<from<<" - " <<to <<" -->";
    cin >> number;
}
bool checkNumInRange(int From, int To, int Number){
 if(Number>=From && Number<=To)
     return true;
 else
     return false;
}
void PrintResult(bool isNumInRange){
    if(isNumInRange == true)
        cout << "your number in the range " << endl;
        else
        cout << "your number is not in this range " << endl;
    }
    
    // ----------------------- 25-----------------
    void EnterNumInRangeOnly(int from,int to ,int Number){
        do
        {
            cout << "your Number is not in the range ";
            ReadNumber(from, to, Number);
            cout << endl;
        }
        while (!checkNumInRange(from, to, Number));
        cout << "good  number  " << endl;
    }
    void readA_B( float & a,float & b ){
        cout << "please enter A in cm -->";
        cin >> a;
         cout << "\nplease enter b in cm -->";
         cin >> b;
         cout << endl;
     }

     float claculateCircleAreaITriangle(float a,float  b){
         
         return PI * ((float)pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
     }
     void print_Result(float Area){
         cout << " your circle Area is " << Area << " cm " << endl;
        }
        // ----------------------- 23-----------------
        void readA_B_C(float &a, float &b, float &c)
        {
            cout << "please enter A in cm -->";
            cin >> a;
            cout << "\nplease enter b in cm -->";
            cin >> b;
            cout << "\nplease enter c in cm -->";
            cin >> c;
            cout << endl;
        }
        float claculateCircleAreaAroundTriangle(float a, float b,float  c){
            float P = (a + b + c) / 2;
            float k =(a * b * c) / 4 * sqrt(P*(P - a) *( P*(P - b) )* (P*(P - c)));
            return PI * (float)pow(k, 2);
        }



        int main()
        {
            // ----------------------- 22-----------------

            // احسب مساحة دائرة موجودة داخل مثلث متساوي الساقين
            // float a, b;
            // readA_B(a, b);
            // print_Result(claculateCircleAreaITriangle(a, b));

            // ----------------------- 23-----------------
            //  احسب مساحة داائرة موجود بداخلها مثلث غي متساوي الساقين
            // float A, B, C;
            // readA_B_C(A, B, C);
            // print_Result(claculateCircleAreaAroundTriangle(A, B, C));

            // ----------------------- 24 -----------------
            //  int From, To, number;
            //  GetTheRange(From, To);
            //  ReadNumber( From, To,number);
            //  PrintResult(checkNumInRange(From, To, number));
             //  // ----------------------- 25-----------------
             //  // اجبر  المستخدم انو يدخل رقم موجود داخل النطاق الذي حدتته
            //   EnterNumInRangeOnly(From, To, number);

           
             // return 0;
        }