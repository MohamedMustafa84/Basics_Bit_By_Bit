#include <iostream>
using namespace std;
#include <cmath>

// -- -- -- -- -- --
float readNumber()
{
    float Number;
    cout << "please Enter a number --> ";
    cin >> Number;
    return Number;
}
// ---------
// ----------------- 46 --------------
int My_abs(int Number){
    if(Number>=0)
        return Number;
    else
        return Number * -1;
    
}
// ----------------- 47 --------------

float GetFractionPart(float Number){
    return Number - (int)Number;
}


int My_Round(float Number){
    int intPart=(Number);

    float fractionPart = GetFractionPart(Number);

    if (fractionPart >= 0.5)
    {
        if(Number>0){
            
            return ++intPart;
        }
        return --intPart;
    }
    else{
        
        return intPart;
    }
    
    
}
// ----------------- 48 --------------
int My_floor(float Number){
    if(Number>0)
        return (int)Number;
    else
        return (int)--Number;
}

// ----------------- 49 -------------
int My_ceil(float Number)
{
    if (Number > 0)
    return (int)++Number;
    else
    return (int)Number;
}
// ----------------- 50 --------------


float My_sqrt(float Number)
{
    return pow(Number,0.5);
}

int main(){
// ----------------- 46 --------------
//  ads Number
// int Number = readNumber();
// cout<< "My abs Result : " << My_abs(Number) << "\n";
// cout << "C++ abs Result : " << abs(Number) << endl;
// ----------------- 47 --------------
// float  Number = readNumber();
// cout << "My Round Result : " << My_Round(Number) << "\n";
// cout << "C++ Round Result : " << round(Number) << endl;
// ----------------- 48 --------------
// float Number = readNumber();
// cout << "My Round Result : " << My_floor(Number) << "\n";
// cout << "C++ Round Result : " << floor(Number) << endl;

// ----------------- 49 --------------
// float Number = readNumber();
// cout << "My sqrt Result : " << My_sqrt(Number) << "\n";
// cout << "C++ sqrt Result : " << sqrt(Number) << endl;

return 0;
}

