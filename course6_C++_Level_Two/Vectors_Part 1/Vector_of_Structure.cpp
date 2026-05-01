#include <iostream>
#include <vector>
using namespace std;

struct stEmployee
{
    string FirstName = "";
    string LastName= "";
    float salary = 0.00;
};

void readEmployeesData(vector<stEmployee> &vEmployees)
{
    char AddEmployee= 'Y';
    stEmployee TempEmployee;

    while(AddEmployee == 'y'||AddEmployee == 'y'){
        cout << "Enter the FirstName ? ";
        cin >> TempEmployee.FirstName;
        cout << "\nEnter the Last Name ? ";
        cin >> TempEmployee.LastName;
        cout << "\nEnter the salary ? ";
        cin >> TempEmployee.salary;

        // add Employee to vector

        vEmployees.push_back(TempEmployee);

        cout << "\n\n you Want To Add More Employee : (Y/N) ? ";
        cin >> AddEmployee;
    }
}

void PrintEmployeeData(vector<stEmployee> &vEmployees){
    cout << "Employees Data : \n";
    cout << "---------------------------------------------\n";
    for(stEmployee &Employee:vEmployees){ //Reminder for your to add & to Make The Program Faster
        cout << "First Name : " << Employee.FirstName;
        cout << "\nLast Name : " << Employee.LastName;
        cout << "\nSalary : " << Employee.salary;
        cout << "---------------------------------------------" << endl;
    }
} 

int main(){

    vector<stEmployee> vEmployees;
    
    readEmployeesData(vEmployees);
    PrintEmployeeData(vEmployees);

    return 0;
}
