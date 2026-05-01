#include <iostream>
using namespace std;

struct stPersonInfo
{
    string firstName;
    string lastName;
    short Age;
    string phone;
};

void readUserInfo(stPersonInfo &PresonInfo)
{

        cout << " please enter your first Name -> \n";
        cin >>PresonInfo.firstName;
        cout << " please inter your last  name \n";
        cin >> PresonInfo.lastName;
        cout << " please inter your Age \n";
        cin >>PresonInfo.Age;
        cout << " please inter your first phone \n";
        cin >> PresonInfo.phone;
    
    
}
void read_Users_info(stPersonInfo arrPresonInfo[100],int usersLength){
    for (int i = 0; i <= usersLength - 1; i++){
        readUserInfo(arrPresonInfo[i]);
    }
    
}  
    void printUserInfo(stPersonInfo arrPresonInfo)
{
    cout << " ************************************************** \n";
    cout << " First Name : " << arrPresonInfo.firstName << "\n";
    cout << " last  Name : " << arrPresonInfo.lastName << "\n";
    cout << " Age : " << arrPresonInfo.Age << "\n";
    cout << " phone  : " << arrPresonInfo.phone << endl;

    cout << " ************************************************** \n";
     
}
void print_users_info(stPersonInfo arrPresonInfo[100], int usersLength){
    for (int i = 0; i <= usersLength - 1; i++){
        printUserInfo(arrPresonInfo[i]);
    
    }
}

//     int main()
// {

//     // ################# 47 ########################
//     int usersLength ;
//     cout <<" How many preson do you have ? =>";
//     cin >> usersLength;

//     stPersonInfo arrUsers_Info[100];

//     read_Users_info(arrUsers_Info, usersLength);
//     print_users_info(arrUsers_Info, usersLength);

    // float arrGreads[3];
    // readGrades(arrGreads);

    // cout << " the Avarage of your Greades is " << getAvarage(arrGreads)<< endl;

    // cin >> arrGreads[4];

//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------

 enum enfaivorColor
 {
     red,
     green,
     blue
 };

 struct StInfo
 {
     string fullName;
    short Age;
    string country;
    string city;
    string phone;
     enfaivorColor color;
 };


// // void  getUserInfo(StInfo &userInfo ){

// //     cout << "please enter Your full name \n";
// //     cin.ignore(1, '\n');
// //     cin >> userInfo.fullName;
    
// //     cout << "please  enter Your age \n";
// //     cin >> userInfo.Age;
// //     cout << "please  enter Your City \n";
// //     cin >> userInfo.city;
// //     cout << "please  enter Your country \n";
// //     cin >> userInfo.country;
// //     cout << "please  enter Your phone \n";
// //     cin >> userInfo.phone;
    
// // }



// // void printUserInfo(StInfo userInfo){

// //     cout << "***********************************************************\n\n";
    
// //     cout << "Name : " << userInfo.fullName << endl;
// //     cout << "Age : " << userInfo.Age<< endl;
// //     cout << "City  : " << userInfo.city<< endl;
// //     cout << "Country  : " << userInfo.country<< endl;
// //     cout << "Phone : " << userInfo.phone << endl;
    // cout << " Color : " << userInfo.color = enfaivorColor::blue;
// //     // cout << " Color : " << static_cast<int>(userInfo.color) << endl;
// //     cout << "***********************************************************\n\n";


// // }

// void getGrade(double grades[3])
// {

//     cout << "please enter Grade 1?\n";
//     cin >> grades[0];

//     cout << "please enter Grade 2?\n";
//     cin >> grades[1];

//     cout << "please enter Grade 3?\n";
//     cin >> grades[2];
    
// }

// double gradeAvarage(double grades[3])
// {

//     return (grades[0] + grades[1] + grades[2]) / 3.0;
// }

//     int main()
// {

//     double grades[3] = {0, 0, 0};
//     getGrade(grades);

//     cout << " the avarage of gredes is " << gradeAvarage( grades);

//     //  StInfo presonOne;
//     // getUserInfo(presonOne);
//     // printUserInfo(presonOne);

//     // StInfo presonTwo;
//     // getUserInfo(presonTwo);
//     // printUserInfo(presonTwo);

//     // int number[5] = {1, 2, 3, 4, 5};

//     // cout << number[1]<<endl;
//     // number[6] = 20;
//     // cout << number[6]<<endl;

//     // *****************************************************************************************************

//     return 0;
// }
