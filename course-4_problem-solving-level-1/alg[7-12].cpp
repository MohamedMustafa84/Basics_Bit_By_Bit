#include <iostream>
using namespace std;



// ---------------------- 7 ----------------------------
int getTheNum(){
    int num;

    cout <<" plz enter a number and i will calc the half of it --> ";
    cin >> num;
    return num;
}

int calc_Num_half(int num){
    return num / 2;
}

void printreuslt(int half){

    cout << "\n the half of your number is  " << to_string(half) << endl;
}



// ------------------ 8 ------------------------

enum enmark
{
    passMark = 50
};
short getuserMark(){
    short mark;
    cout << " plz enter your mark withot any fakeing -->";
    cin >> mark;
    return mark;
}
void  chackTheMark(short mark){


    if ((enmark)mark >= enmark::passMark)
        cout << "you are pass this examenation " << endl;
    else
        cout << " you fail to pass this exam " << endl;
}
// ------------------ 9 ------------------------
void read_numbers(int arrNumbers[3]){
    for (int i = 0; i < 3; i++){
        cout << "plz enter  number "<<i+1 <<" --> ";
        cin >> arrNumbers[i];
        cout << endl;
    }

}

int calc_sum(int arrNumbers[3])
{
    int sum=0;
    for (int i = 0; i < 3; i++)
    {
        sum += arrNumbers[i];
    }
    return sum;
}

void result(int sum)
{
    cout << "the sum of all the number = " << sum << endl;
}

// ------------------ 10------------------------
int calcAvg(int sum){
    return sum / 3;
}
// ------------------ 11------------------------
enum enPassFail
{
    pass,
    fail
};
enPassFail checkAvarage(int avg){
    if(avg>=50)
        return enPassFail::pass;
    else
        return enPassFail::fail;
}

void avg_of_three_num(int avg){
    cout << " the avarage of your numbers is " << avg<<endl;
    if (checkAvarage(avg) ==enPassFail::pass)
    cout <<" you are passed";
    else
    cout <<" you are fail";
}

// --------------------------------- 12 ---------------------
struct stInfo{
    string firstName;
    string lastName;
    string lang;
};

stInfo getuserName(){
    stInfo user;
    cout<< "plz enter your first name -->";
    cin >> user.firstName;
    cout << "\nplz enter your last name -->";
    cin >> user.lastName;
    cout << "\nplz enter your lang  -->";
    cin >> user.lang;
    cout << endl;
    return user;
}
string getfullName(stInfo  user){

    if (user.lang == "english")
    return user.lastName + " " + user.firstName;
    else 
    return user.firstName + " " + user.lastName;
}
void printFullName(string fullName){
    cout << " your full name is " << fullName;
}

    int
    main()
{

        

    // ------------------ 7 ------------------------
    // اطلب من المستخدم ادخال  رقم ثم قم بطباعة نصفه   لا تنسى ان تحول الرقم الى نص

    // printreuslt(calc_Num_half(getTheNum()));

    // ------------------ 8 ------------------------
    // اقرا العلامة واذا كانت اكبر من او تساوي خمسين اطبع  ناجح واذا اقل من خمسين اطبع راسب

    // chackTheMark(getuserMark());
    // ------------------ 9 ------------------------
    // اكتب برنامج يقرا ثلاثة ارقام ثم يقوم بجمعهمم
    // int arrNumbers[3];
    // read_numbers(arrNumbers);
    // result(calc_sum(arrNumbers));

    // ------------------ 10 -11 ------------------------
    // احسب متوسط ثلاثة ارقام
    // int sum = calc_sum(arrNumbers);
    // avg_of_three_num(calcAvg(sum));
    // ------------------ 12 ------------------------
    // printFullName(getfullName(getuserName()));

    return 0;
}