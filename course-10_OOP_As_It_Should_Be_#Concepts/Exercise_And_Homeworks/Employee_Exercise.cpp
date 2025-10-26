#include <iostream>
using namespace std;

class clsEmployee
{

    static int _ID;
    string _FirstName = "";
    string _LastName = "";
    string _Email = "";
    string _Phone = "";
    string _Title = "";
    string _Salary="";
    string _Department = "";

public:
    clsEmployee(string FirstName, string LastName, string Email, string Phone ,string Salary,string Title ,string department)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
        _Salary = Salary;
        _Title = Title;
        _Department = department;
        
        _ID++;
    }

    int ID()
    {
        return _ID;
    }

    void SetFirstName(string firstName)
    {
        _FirstName = firstName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string GetLastName()
    {
        return _LastName;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    string GetEmail()
    {
        return _Email;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string GetPhone()
    {
        return _Phone;
    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string GetTitle()
    {
        return _Title;
    }

    void SetSalary(string Salary)
    {
        _Salary = Salary;
    }

    string GetSalary()
    {
        return _Salary;
    }

    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string GetDepartment()
    {
        return _Department;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\n______________________________________________\n";
        cout << "ID          : " << _ID;
        cout << "\nFirstName : " << _FirstName;
        cout << "\nLastName  : " << _LastName;
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << _Email;
        cout << "\nPhone     : " << _Phone;
        cout << "\nSalary    : " << _Salary;
        cout << "\nDepartment: " << _Department;
        cout << "\nTitle     : " << _Title;
        cout << "\n______________________________________________" << endl;
    }

    void SendEmail(string Subject, string MessageBody)
    {
        cout << "the following message send successfully to email :" << _Email;
        cout << "\nSubject : " << Subject;
        cout << "\nBody : " << MessageBody << endl;
    }

    void SendSMS(string Message)
    {
        cout << "\nthe following SMS sent successfully to phone : " << _Phone << endl;

        cout << Message << endl;
    }
};

int clsEmployee::_ID = 0;

int main()
{

    clsEmployee Employee1("Mohamed", "Mustafa", "realemail@email.com", "249987465767","5000$","Senior Developer","IT Department");

    Employee1.Print();

    Employee1.SendEmail("Hi", "How Are You ?");
    Employee1.SendSMS("did you sow my email message ");

    return 0;
}