#include <iostream>
#include <cmath>
using namespace std;

// string Name = "mohamed mustafa";

// void sayHello(){

//     string Name = " ali hamed ali ";

//     cout << " Hello " << Name << " your name comes from the local scope";
//     cout << " Hello " << ::Name << " your name comes from the global scope";
// }



// int main(){
//     sayHello();

//     return 0;

// }
// ---------------------------------------------------------------

// // void pritName()
// // {

// //     cout << "mohamed  mustafa";
// // }

// // void getUserName(string userName)
// // {

//     cout << "welcome " << userName << " nice to meet you  " << endl;
// // }

// // int swapNums(int &swapNum1,int &swapNum2){
// //     int tempNum = swapNum1;

// //     swapNum1 = swapNum2;
// //     swapNum2 = tempNum;

// //     return swapNum1, swapNum2;
// // }

// // struct stInfo{
// //     string fullName;
// //     short Age;
// //     string Country;
// //     string City;
// // };

// // void getUserInfo(stInfo &userInfo){
// //     cout<<"please Enter your full Name \n";
// //     getline(cin, userInfo.fullName);

// //     cout<<"please Enter your full Age \n";
// //     cin >> userInfo.Age;
// //     cout << "please Enter your full country \n";
// //     cin >> userInfo.Country;
// //     cout << "please Enter your full City \n";
// //     cin >> userInfo.City;
// // }

// // void printUserInfo(stInfo userInfo){

// //     cout << " Name: " << userInfo.fullName << endl;
// //     cout << " Age: " << userInfo.Age << endl;
// //     cout << " Country: " << userInfo.Country << endl;
// //     cout << " City: " << userInfo.City << endl;

// // }

// // ################### 15 ########################

// // int RectangleArea (int rectangleHeight, int rectangleWidth){

// //     return rectangleHeight * rectangleWidth;
// // }

// // ################### 16 ########################

// // double RectangleArea (double sideArea,double diagonal){

// //     return  (sideArea * sqrt(pow(diagonal, 2) - pow(sideArea, 2)));
// // }

// // ################### 18 ########################

// // float circleArea(float &R){
// //     const double PI = 3.14;

// //     return (PI * pow(R, 2));
// // }

// // ################### 19 ########################

// // int  circleArea(double daiamter){
// //   const double  Pi= 3.14;

// //   return (int)(Pi * (pow(daiamter, 2) / 4));
// // }

// //     //################### 20 ########################
// // float circleArea(float A){
// //         const float PI = 3.14f;

// //         return PI * (float)pow(A, 2) / 4;

// //

// //     //################### 21 ########################
// // int circleArea(int a,int b ,int c){
    
// //     const float  PI = 3.14;
// //     int P = (a + b + c) / 2;
// //     int Area = PI * pow((a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c))), 2);

// //     return Area;
// // }


// //     //################### 22 ########################

// //     float  circleArea(int &a,int &b){
//     // const float PI=3.14;
//     // float Area= PI*(pow(b,2)/4)*((2*a-b)/2*a+b);
//     // return Area;
// // }



// //################### 31 ########################

// // double power(double a)
// // {
    
// //     double powerOf2 = pow(a, 2);
// //     double powerOf3 = pow(a, 3);
// //     double powerOf4 = pow(a, 4);

// //     cout << a << " power 2 = " << powerOf2<<"\n";
// //     cout << a << " power 3 = " << powerOf3<<"\n";
// //     cout << a << " power 4 = " << powerOf4<<"\n";

// //         return 0;
// // } 



// //################### 32 ########################

// int powerOfNumber (int &number , int  &power)
// {
//     int result = pow(number, power);

//     return result ;
// }





//     // ***********************************************************************************************

//     int main()
//     {

//         cout << "\n problem number 32 solution \n\n";

//         int number,power;
//         cout << "please enter a number to powered \n";
//         cin >> number;

//         cout << "please enter  the power  \n";
//         cin >> power ;
        
//         cout << powerOfNumber(number,power);
//         cin >> power ;

//         // cout << "\n problem number 31 solution \n\n";

//         // double  number;
//         // cout << "please enter a number to powered \n";
//         // cin >> number;
        
//         // cout <<power(number);

//         // cout << "\n problem number 22 solution \n\n";

//         // int a, b;

//         // cout << "please Enter the  A of the circle in cm \n";
//         // cin >> a;

//         // cout << "please Enter the  b of the circle in cm\n ";
//         // cin >> b;

//         // cout << "\n problem number 21solution \n\n";

//         // int a, b, c;

//         // cout << "please Enter the  A of the circle in cm \n";
//         // cin >> a;

//         // cout << "please Enter the  b of the circle in cm\n ";
//         // cin >> b;
//         // cout << "please Enter the  c of the circle in cm \n";
//         // cin >> c;
//         // cout <<"the circle Area is "<<circleArea(a, b, c);
//         // cin >> c;

//         // cout << "\n problem number 20solution \n\n";

//         // float A;

//         // cout << "please Enter the  A of the circle in cm ";
//         // cin >> A;

//         // cout << "the Area of your circle is " << circleArea(A) << endl;
//         // cin >> A;

//         // cout << "\n problem number19 solution \n\n";

//         // double daiameter;

//         // cout << "please Enter the circle daiamter in cm ";
//         // cin >> daiameter;

//         // cout << "the Area of your circle is " << circleArea(daiameter) << endl;
//         // cin >> daiameter;

//         // cout << "\n problem number 18 solution \n\n";

//         // float r;

//         // cout <<"please Enter the R of the Circle\n";
//         // cin >> r;
//         // cout << "your circle area is "<<circleArea(r)<<endl;
//         // cin >> r;

//         // // cout << "\n problem number 16 solution \n\n";
//         // cout << "the is realy weard";

//         // cout << "RectangleArea = " <<RectangleArea(2, 8);

//         // cout << "\n problem number 15 solution \n\n";
//         //     cout << RectangleArea(2, 5)<<endl;

//         // cout << "\n problem number 1 solution \n\n";
//         // pritName();

//         // cout << "\n problem number 2 solution \n\n";
//         // string userName;
//         // cout << "please enter your name \n";
//         // getline(cin, userName);
//         // getUserName(userName);

//         // cout << "\n problem number 14 solution \n\n";

//         // int swapNum1, swapNum2;
//         // cout << "please enter the first number you want me to swap \n";
//         // cin >> swapNum1;
//         // cout << "\nplease enter the second number you want me to swap \n";
//         // cin >> swapNum2;

//         // cout << " the value of the number 2 before swaping is " << swapNum2 << endl;
//         // cout << " the value of the number 1 before swaping is " << swapNum1 << endl;

//         // swapNums(swapNum1, swapNum2);

//         // cout << " the value of the number 1 after swaping is " << swapNum1 << endl;
//         // cout << " the value of the number 2 after swaping is " << swapNum2 << endl;

//         return 0;
//     }