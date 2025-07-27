#include <iostream>
#include <string>
using namespace std;





// int swapnums(int number1,int number2){

//     int temp;
//     temp = number1;
//     number1 = number2;
//     number2 = temp;

//     cout << "the value of the number 1 after swaping is " << number1<<endl;
//     cout << "the value of the number 2 after swaping is " << number2<<endl;

//     return 0;
// }



// int sum(){

//     int num1 = 10,num2=30;

//     return num1 + num2;
// }





// prameters


// int mulitpliecnums(int &num1,int &num2){

//     int number1 = num1, number2 = num2;

//     return number1 * number2;
// }

// int num1=10,num2 = 30;


// ----------------------------------------------------

// int main(){

//     sum();

//     int num1=5, num2 =60;

//     swapnums(num1, num2);

//     cout << " the value of the  gloabal  variable num1  before  the  oprations is  " << ::num1 << endl;
//     cout << " the value of the  gloabal  variable num2 before  the  oprations  is  " << ::num2 << endl;

//     cout << "please enter the number 1";
//     cin >> ::num1;
//     cout << "please enter the number 2";
//     cin >> ::num2;

//     mulitpliecnums(::num1, ::num2);

//     cout << " the vailue of the  local variable num1 is  " << num1 << endl;
//     cout << " the vailue of the  local variable num2 is  " << num2 << endl;
//     cout << "\n #################################################### \n" << num2 << endl;
//     cout << " the vailue of the  gloabal  variable num2  after the  oprations became is  " << ::num1 << endl;
//     cout << " the vailue of the  gloabal  variable num2 after the  oprations became  is  " << ::num2 << endl;
//     cout << " the  result that comming form the function is  " << mulitpliecnums(::num1, ::num2)<< endl;

//     cout << "hello world";

//     return 0;
// }

// -----------------------------------------------------------------------------

// enum enColor
//  {
//     red,
//     green,
//     yellow,
//     black
// };



// enum enOwnerGender
// {
//     male=1,
//     female=2
// };

// enum enMaritalstatus
// {
//     single,
//     married
// };

// struct stOwnercontcatinfo
// {
//     string email;
//     string phonenumber;
// };

// struct stOwnerAddress{
//     string city;
//     string country;

// };

// struct stOwner {
//     string fullname;
//     short age;
//     stOwnerAddress address;
//     stOwnercontcatinfo contactinfo;
//     enOwnerGender gender;
//     enMaritalstatus isMarried;
// };
 
// struct stCar {
//     string modele;
//     unsigned short year;
//     enColor color;
//     double price;
//     stOwner owner;
// };


// int main(){

//     stCar car1;

//     cout << " please enter your car modele\n";
//     getline(cin, car1.modele);

    
//     cout << " please enter your car year\n";
//     cin >> car1.year;
    
    
//     // cout << " please enter your car color\n";
//     // cin >> car1.color =enColor::green ;

//     cout << " please enter your car price\n";
//     cin >> car1.price;

    
//     cout << " please enter the  owner full name\n";
//     getline(cin, car1.owner.fullname);

//     cout << " please enter the owner age\n";
//     cin >> car1.owner.age;


//     // cout << " please enter the owner gender \n";
//     // cin >> car1.owner.gender = enOwnerGender::female = 1;

//     //     cout << " are you married ?\n";
//     // cin >> car1.owner.gender= enMaritalstatus::married;

//     cout << " please enter the owner email \n";
//     cin >> car1.owner.contactinfo.email;

//     cout << " please enter the owner phone number  \n";
//     cin >> car1.owner.contactinfo.phonenumber;

//     cout << " please enter the owner city   \n";
//     cin >> car1.owner.address.city;

//     cout << " please enter the owner country   \n";
//     cin >> car1.owner.address.country;

//     cout << "\n\n\n\n *************************************************************************** \n\n";
//     // cout << "Car modle :" << getline(cin, car1.modele)<<endl;
//     cout << " Car Year : " << car1.year<<endl;
//     // cout << " Car Color : " << car1.color = enColor::green <<endl;
//     cout << " Car Price : " << car1.price<<endl;

//     cout << "################## Owner information #################\n\n";

//     // cout << " Name : " << getline(cin, car1.owner.fullname)<<endl;
//     cout << " Age : " << car1.owner.age<<endl;
//     // cout << " gender  1 for male 2 for female  : " <<car1.owner.gender = enOwnerGender::female = 1<<endl;
//     // cout << " Maritalstatus : " << car1.owner.gender = enMaritalstatus::married<<endl;
//     cout << "Email :" << car1.owner.contactinfo.email<<endl;
//     cout << "Phone :" << car1.owner.contactinfo.phonenumber<<endl;
//     cout << "City  :" << car1.owner.address.city<<endl;
//     cout << "Country  :" << car1.owner.address.country<<endl;

//     cout << "\n\n\n\n *************************************************************************** \n\n";



//     return 0;
// };


