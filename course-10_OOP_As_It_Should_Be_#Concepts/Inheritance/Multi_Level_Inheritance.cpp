#include <iostream>
using namespace std;

// this is the Super class Or Base Class
class clsPerson
{

    static int _ID;
    string _FirstName = "";
    string _LastName = "";
    string _Email = "";
    string _Phone = "";

public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
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

    string FirstName()
    {
        return _FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string LastName()
    {
        return _LastName;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    string Email()
    {
        return _Email;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string Phone()
    {
        return _Phone;
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
        cout << "the following SMS sent successfully to phone : " << _Phone << endl;

        cout << Message << endl;
    }
};

int clsPerson::_ID = 0;

// this is the Derive Class OR SubClass
class clsEmployee : public clsPerson
{
    string _Title = "";
    string _Salary = "";
    string _Department = "";

public:
    clsEmployee(string FirstName, string LastName, string Email, string Phone, string Title, string Salary, string Department)
        : clsPerson(FirstName, LastName, Email, Phone) // Send the parameters to the Super Class
    {
        _Title = Title;
        _Salary = Salary;
        _Department = Department;
    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string Title()
    {
        return _Title;
    }

    void SetSalary(string Salary)
    {
        _Salary = Salary;
    }

    string Salary()
    {
        return _Salary;
    }

    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string Department()
    {
        return _Department;
    }

    // Function  Overriding
    //

    void Print()
    {
        cout << "\n______________________________________________\n";
        cout << "ID             : " << ID();
        cout << "\nFirstName    : " << FirstName();
        cout << "\nLastName     : " << LastName();
        cout << "\nFull Name    : " << FullName();
        cout << "\nEmail        : " << Email();
        cout << "\nPhone        : " << Phone();
        cout << "\nTitle        : " << Title();
        cout << "\nSalary       : " << Salary();
        cout << "\nDeDepartment : " << Department();
        cout << "\n______________________________________________" << endl;
    }
};

class clsDeveloper : public clsEmployee
{
    string _MainProgrammingLanguage = "";

public:
    clsDeveloper(string FirstName, string LastName, string Email, string Phone, string Title, string Salary, string Department, string MainProgrammingLanguage)
        : clsEmployee(FirstName, LastName, Email, Phone, Title, Salary, Department)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    void SetMainProgrammingLanguage(string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }

    void Print()
    {
        cout << "\n______________________________________________\n";
        cout << "ID                         : " << ID();
        cout << "\nFirstName                 : " << FirstName();
        cout << "\nLastName                  : " << LastName();
        cout << "\nFull Name                 : " << FullName();
        cout << "\nEmail                     : " << Email();
        cout << "\nPhone                     : " << Phone();
        cout << "\nTitle                     : " << Title();
        cout << "\nSalary                    : " << Salary();
        cout << "\nDeDepartment              : " << Department();
        cout << "\nMain Programming Language : " << _MainProgrammingLanguage;
        cout << "\n______________________________________________" << endl;
    }
};

int main()
{

    clsDeveloper Developer1("Mohamed", "Mustafa", "read_email@gmail.com", "2498687875", "Web Developer", "100000.00", "Programming Advices","C++");


    Developer1.Print();
    Developer1.SendEmail("Hi", "You pray that is your path is not deficall to be saved , so it will be deficall and you will be saved to know that salivation is not from the path it from the GOD *");
    Developer1.SendSMS("Please Call Me Back  ASAP");

    return 0;
}