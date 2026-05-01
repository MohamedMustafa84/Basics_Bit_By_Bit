#include <iostream>
using namespace std;
#include <map>


void PrintStudentGrade(map <string,int>StudentsGrade, string studentName){
    cout << "finding "<<studentName <<" in the map ..\n ";
    if (StudentsGrade.find(studentName) != StudentsGrade.end())
    {
        cout << studentName << " Grade : " << StudentsGrade[studentName] << endl;
    }
    else
    {
        cout << "Grade Not Found For " << studentName << endl;
    }
}

int main(){
    // declare a map with string key and int value
    map<string, int> StudentsGrade;

    StudentsGrade["Mohamed"] = 90;
    StudentsGrade["ali"] = 80;
    StudentsGrade["osman"] = 70;
    StudentsGrade["jamal"] = 95;

    cout <<"printing all map values : \n";
    // iterating over hte map

    for (const auto& pair :StudentsGrade){

        cout << "Student : " << pair.first << " ,Grade :" << pair.second << endl;   
    }

    cout << "\n\n=========================================\n";
    string studentOne = "Mohamed";
    string studentTwo = "Omer";

    PrintStudentGrade(StudentsGrade, studentOne);
    PrintStudentGrade(StudentsGrade, studentTwo);
    return 0; 
}