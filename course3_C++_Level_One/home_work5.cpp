                #include  <iostream>
using namespace std;




// ################# 46 ########################

// void readGrades (float greads[3]){
    //     cout << "please enter grade one \n";
    //     cin >> greads[0];

//     cout << "please enter grade two \n";
//     cin >> greads[1];

//     cout << "please enter grade three \n";
//     cin >> greads[2];
// }

// float getAvarage(float greads[3]){
//         return (greads[0] + greads[1] + greads[2]) / 3;
// }

// ################# 47 ########################

//  struct stPersonInfo {
//      string firstName;
//      string lastName;
//      short Age;
//      string phone;
//  };


//  void readUserInfo (stPersonInfo &arrPresonInfo ){

//      cout << " please enter your first Name -> \n";
//      cin >> arrPresonInfo.firstName;
//      cout << " please inter your last  name \n";
//      cin >> arrPresonInfo.lastName;
//      cout << " please inter your Age \n";
//      cin >> arrPresonInfo.Age;
//      cout << " please inter your first phone \n";
//      cin >> arrPresonInfo.phone;

   
//  }
//  void getUsersInfo(stPersonInfo arrPresonInfo[2]){
//      readUserInfo( arrPresonInfo[0]);
//      readUserInfo( arrPresonInfo[1]);
//  }

//      void printUserInfo(stPersonInfo arrPresonInfo)
//  {

//      cout << " ************************************************** \n";
//      cout << " First Name : " << arrPresonInfo.firstName <<"\n";
//      cout << " last  Name : " << arrPresonInfo.lastName <<"\n";
//      cout << " Age : " << arrPresonInfo.Age <<"\n";
//      cout << " phone  : " << arrPresonInfo.phone <<endl;

//      cout << " ************************************************** \n";
//  }

//  void printUsersInfo(stPersonInfo arrPresonInfo[2])
//  {
//      printUserInfo( arrPresonInfo[0]);
//      printUserInfo( arrPresonInfo[1]);
//  }


// struct stUserinfo{
//     string fullName;
//     short Age;
//     bool hasDriverLinces;
// };

// void getUserinfo(stUserinfo &userinfo)
// {
//     cout << "please enter your full name  - >";
//     cin.ignore(1, '\n');
//     getline(cin, userinfo.fullName);
//     cout << "\n please enter your Age  - >";
//     cin >> userinfo.Age;

//     cout << "\n do you have a driver linces   ( true or false ) - >";
//     cin >> userinfo.hasDriverLinces;
// }

// void isHaired(stUserinfo userInfo){
//     short legalAge = 21;

//     if (userInfo.Age >= legalAge && userInfo.hasDriverLinces == true)
//     {

//         cout << " congratulations " << userInfo.fullName << " you are haired ";
//         cin >> userInfo.Age;
//     }else
//     {

//         cout << "sorry " << userInfo.fullName <<" you dont haired coz you dont have A diver linces or your Age is less the 21 ";
//         cin >> userInfo.Age;
//     }
// }
// struct stStudantInfo
// {
//     string fullName;
//     short mark;
// };


// void getStrudantInfo(stStudantInfo &studant){
//     cout << "please enter your full name --> ";
//     cin.ignore(1, '\n');
//     getline(cin, studant.fullName);
//     cout << "\n please enter your mark --> ";
//     cin >> studant.mark;
// }
// void studantResult (stStudantInfo studant ){
//     short successedMark = 50;
//     if(studant.mark >= successedMark){
        
//         cout << "congratuations " << studant.fullName << "you pass this exaim"<<"\n";
//         cin >> studant.mark;
//     }else {
        
//         cout << " you feail to pass this exaim good luck next time"<<endl;
//         cin >> studant.mark;
//      }
//  }


// struct stUserInfo{
//     string fullName;
//     short Age;
// };

// void getUserInfo(stUserInfo &user){

//     cout <<" please enter your full Name  -->\n";
//     getline(cin, user.fullName);

//     cout << "\n please enter your Age -->";
//     cin >> user.Age;
// }

// void validateUserAge(stUserInfo user ){
//     short legalAge = 18;


//     if (user.Age >= legalAge){

//         cout << "\n"
//              << user.fullName << " that is cool man go ahead to build your futher   \n";
//         cin >>user.Age;
//     }else {
//         cout << "\n"<< user.fullName << "  يازول انتا  لسى شافع لكن برضو ابعد من افلام  السيك سيكو والانمي  وماتسالني لي شنو لانك اسي ما حاتفهم شي\n";
//         cin >>user.Age;
//     }

// }

void readStudantMarks(int arrStudantMart[3])
{

    cout << "plese enter your first Mark --> ";
    cin >> arrStudantMart[0];

    cout << "plese enter your secound Mark --> ";
    cin >> arrStudantMart[1];
    cout << "plese enter your three Mark --> ";
    cin >> arrStudantMart[2];
}

int  culcMarkAvarage(int arrStudantMart[3])
{
    int markCount = 3;
    int avarage = (arrStudantMart[0] + arrStudantMart[1] + arrStudantMart[2])/ markCount;
    return avarage;
}

void checkAvarage() {

    int  avarage = culcMarkAvarage(int arrStudantMart[3]);

    if (avarage >= 50)
    {
        cout << " PASS \n";
        cin >> avarage;
     }else{
         cout << "fail\n";
     }

     
}

// string get_ATM_PIN()
// {
//     string PIN;
//     cout << "please enter your  PIN -->";
//     cin >> PIN;
//     return PIN;
// }

// void checkPIN(){
//     string currectPIN = "1234";
//     string balance = "90k";
//     string userPIN = get_ATM_PIN();
//     if(userPIN == currectPIN){

//         cout << "your balance = " << balance << endl;
//         cin >> balance;
//     }else{
//         cout <<"wrong PIN please retry again \n";
//         checkPIN();
//     }
// }




    int main()
{
    
    
    // // -------- 4-------------
    // stUserinfo userInfo;
    // getUserinfo(userInfo);
    // isHaired(userInfo);
    // cin >> userInfo.Age;

    // checkPIN();

    // -------- 8 -------------
    // stStudantInfo studantInfo;
    // getStrudantInfo(studantInfo);
    // studantResult(studantInfo);

    // -------- 11 -------------
    int  studantMarks[3];
    readStudantMarks(studantMarks);
    checkAvarage();

    // -------- 24 -------------
    // stUserInfo userInfo;
    // getUserInfo(userInfo);
    // validateUserAge(userInfo);

    //          // ################# 47 ########################

    //          stPersonInfo arrUseraInfo[2];

    //          getUsersInfo(arrUseraInfo);
    //          printUsersInfo(arrUseraInfo);
    //          cin >> arrUseraInfo[0].firstName;

    // float arrGreads[3];
    // readGrades(arrGreads);

    // cout << " the Avarage of your Greades is " << getAvarage(arrGreads)<< endl;

    // cin >> arrGreads[4];

    return 0;
 }