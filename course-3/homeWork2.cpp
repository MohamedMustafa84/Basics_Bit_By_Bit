#include <iostream>
using namespace std;



void printOddNums()
{
    for (int i = 1; i < 500; i =i+2)
    {
        cout << i<<endl;
    }
}

void printEvenNums()
{
    for (int i = 0; i < 500; i = i + 2)
    {
        cout << i << endl;
    }
}



// =================================  home works =============================================================

// --------------------------- 26 -------

// int getValidNumber(int &number){
    
//     cout << " Enter a number and i will count form it to 1  -->";
//         cin >> number;
    
//      while (number <= 0){
//          cout << "\n invalid number : the number most be greter than ZERO plz Retry -->";
//          cin >> number;
//      }
//     return number;
// }

// void printUserNums(int number)
// {

//     int validNum = getValidNumber(number);
//     for (int i = validNum; i >=1 ; i--)
//     {
//         cout << i << endl;
//     }
// }
// ------------------------------------------------------------------------------

// void printUserNums(int number)
// {

//     for (int i = number; i >=1; i--)
//     {
//         cout << i << endl;
//     }
// }
// ------------------------------------------------------------------------------------------

int getValidNumber(int &number)
{

    // cout << " Enter a number and i will sum all the odd numbers from ZERO to your Number  -->";
    // cin >> number;

    while (number <= 0)
    {
        cout << "\n invalid number : the number most be greter than ZERO plz Retry -->";
        cin >> number;
    }
    return number;
}

int  sumOddNums(int number)
{
    int sum = 0;
    int i = 0;
    while ( i <=number )
    {
         sum += i;
         i += 2;
    }
    return sum;
};


int sumEvenNums(int number)
{
    int sum = 0;
    for (int i = 1; i <= number; i = i + 2)
    {
        sum = sum + i;
    }
    return sum;
};

int 


multiplysNums(int number)
{
    int multiply = 1;
    for (int i = 1; i<= number; i++)
    {
        multiply = multiply * i;
    }
    return multiply;
};



void getUserNumAndPower(int &num,int &power){

    cout << "plz enter the number to power it -->";
    cin >> num;
    cout << "\n and now enter the power --> ";
    cin >> power;
}

int calcPower(int num, int power){

    int pow =1;
    for (int i = 1; i <= power; i++){
        pow = pow* num;
    }
    return pow;
}

// -------------------------------------

// void Retry(int number)
// {
//     string  coutinue;
//     int nextNum;
//     cout << " plz enter true to coutinue and false to close  the program -->  ";
//     cin >> coutinue;
//     while (coutinue =="true"|| coutinue== "True" ){
//         cout << "\nEnter your Next number -->";
//         cin >> nextNum;

//         getValidNumber(nextNum);
//         cout << "the sum of the Even nums  form zero to " << nextNum << " = " << sumEvenNums(nextNum);
//     }
// }

int  getValidUserNumber(int &number){

    short trys = 5;
    cout << " plz  enter a number greter than Zero to multyply it and you have [ "<<trys <<" ]" <<"chances  --> ";
    cin >> number;
    trys--;
    while(number <= 0){

        if(trys== 0){

            cout << " your trys it is done  ";
            break;
        }
        cout << " the number most be gretar than ZERO and you have [ " << trys << " ]to retry -->";
        cin >> number;

        trys--;
    }
    return number;
}









    void getUserPassword(string &password){
        cout << "Enter your Password --> ";
        cin >> password;
    
    }

    void  validateUserPasswords(string &password){
        int  balance = 20000;
        string currectPassword = "mohamed8421";
        short trys = 4;
        while (password != currectPassword ){
            if (trys==0){
                cout << " your chance is done and the count will be delet ";
                break;
            }
            cout << "you Entered uncurrect password and you have " << trys << " chances ";
            cin >> password;
            trys--;
        }
        if (password== currectPassword){

            cout << "your balance is -->" << balance;
        }
    }

    
    


















    int
    main()
{
    // printOddNums();
    // printEvenNums();




    // ===========================================/home work 
    
    // --------------------26
    // int number;
    // printUserNums(number);
    //--------------27
    // int number;
    // getUserNumber(number);
    // printUserNums(number);

    // //     //--------------28
    //     int number;
    //     getValidNumber(number);
    //     cout << "the sum of the Odd nums = " << sumOddNums(number);
    
    //--------------29
        // int number;
        // cout << " Enter a number and i will sum all the EVEN numbers from ZERO to your Number  -->";
        // cin >> number;

        // getValidNumber(number);
        //    cout << "the sum of the Even nums  form zero to " <<number <<" = " << sumEvenNums(number);
        //    cout << "\n\n ##################################### \n" << endl;

        //    Retry(number);

              //--------------30
            //   int number;
            //   cout << "the multyply result is  = " << multiplysNums(getValidUserNumber(number));

              //--------------32
    //   int num;
    //       pow;
    //   getUserNumAndPower(num, pow);
    //    cout << num <<" ** " <<pow <<" = "<< calcPower(num,pow);

    //------------------------50
    string userPassword;
    getUserPassword(userPassword);
    validateUserPasswords(userPassword);
}