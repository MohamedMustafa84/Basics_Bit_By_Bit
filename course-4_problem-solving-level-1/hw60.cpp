#include <iostream>
using namespace std;

void getUserNumbers(int numbers[5], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {

        cout << "\n enter  number " << i + 1 << " -->";
        cin >> numbers[i];
    }
}

int sumTheUserNumbers(int numbers[5], int arrLength)
{
    int sum = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (numbers[i] > 50 )
        {
            continue;
        }
        else
        {
            sum += numbers[i];
        }
    }
    return sum;
}

int  getTheNumber(){
    int number;
    cout <<"plz enter the number and i will find the index of it -->";
    cin >> number;
    return number;
}

void getIndexOfNumber(int number,int arrNumbers[10]){
    
    for (int i = 0; i < 10;i++){
        // cout << arrNumbers[i] << endl;
        if(number == arrNumbers[i]){

            cout << " the index of your number is " << i << endl;
            cin >> number;
            break;
            
        }else{
            cout << " sorry your number is not exiest in this array \n";
            break;
      
        }
    }
        
}




int main()
{
    // int UserNumbers[5];
    // int length = 5;

    // getUserNumbers(UserNumbers, length);
    // cout << " the sum fo all numbers is " << sumTheUserNumbers(UserNumbers, length);
    // cout << "\n Note : the sum not include the numbers that be greter than 50 " << endl;

    int arrUserNums[10] = {10, 20, 30, 50, 90, 70, 100, 200, 898, 78};
    getIndexOfNumber(getTheNumber(),arrUserNums);
    
    return 0;
}