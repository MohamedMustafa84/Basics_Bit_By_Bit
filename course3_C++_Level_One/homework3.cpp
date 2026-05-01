#include <iostream>
using namespace std;



void  readArrayData(int arr[100],int &length){
    cout << "How Many Number Do You Want TO Enter from 1 to 100 numbers => ";
    cin >> length;

    for (int i = 0; i <= length - 1;i++){

        cout << " please enter number " << i + 1 << " => ";
        cin >> arr[i];
    }
}


void printArryData(int arr[100],  int length){

    for (int i = 0; i <= length - 1; i++){
        cout << "Number [" << i + 1 << "] => " << arr[i]<<endl;
    }
}

int calcArraySum(int arr[100],int length){
    int sum=0;
    for (int i = 0; i <= length - 1; i++){
        sum += arr[i];
    }
    return sum;
}
















int main(){

    int arr[100], length = 0;

    readArrayData(arr, length);
    printArryData(arr, length);

    float sum = calcArraySum(arr, length);

    cout << " the sum of all array numbers  =" << sum<<endl;

    cout << "the avarage of the numbers = " << sum / length <<endl;
}