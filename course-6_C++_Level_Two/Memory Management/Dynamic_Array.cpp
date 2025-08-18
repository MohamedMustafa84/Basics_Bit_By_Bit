#include <iostream>
using namespace std;

int main(){

    // Dynamic Array :new and delete

    int studentsLength=0;
    cout << "Enter The Total Number of the Students :";
    cin >> studentsLength;

    int *ptr;

    // memory allocation of num number of integer
    ptr = new int[studentsLength];

    cout << "Enter Grades of students ." << endl;
    for (int i=0; i<studentsLength; i++){

        cout << "\n Student " << i + 1 <<" : ";
        cin >> *(ptr + i);
    }

    cout << "Displaying grade of students ." << endl;
    for (int i = 0; i < studentsLength; i++){
        cout << "student " << i + 1 << " :";
        cout << *(ptr + i) << endl;
    }

    // ptr memory is released
    delete[] ptr;
    //  Note : every new has delete

    return 0;
 }