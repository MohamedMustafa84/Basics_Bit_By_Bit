#include <iostream>
using namespace std; 


// this is the Super class Or Base Class
class clsPerson{

    static int _ID;
    string _FirstName="";
    string _LastName="";
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

        int ID(){
            return _ID;
        }

        void SetFirstName(string firstName){
            _FirstName = firstName;
        }

        string GetFirstName(){
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

        string FullName(){
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

        void SendEmail(string Subject, string MessageBody){
            cout << "the following message send successfully to email :" << _Email;
            cout << "\nSubject : " << Subject;
            cout << "\nBody : " << MessageBody << endl;
        }

        void SendSMS(string Message){
            cout << "the following SMS sent successfully to phone : " << _Phone << endl;
    
            cout << Message << endl;
        }
};

int clsPerson::_ID = 0;


// this is the Derive Class OR SubClass
class clsEmployee:public clsPerson{
    string _Title="";
    string _Salary = "";
    string _Department = "";


public:
    clsEmployee(string FirstName, string LastName, string Email, string Phone, string Title, string Salary, string Department) 
    : clsPerson(FirstName, LastName, Email, Phone) //Send the parameters to the Super Class 
    {
        _Title = Title;
        _Salary = Salary;
        _Department = Department;
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
};

int main(){

    clsEmployee Employee1("Mohamed", "Mustafa", "read_email@gmail.com", "2498687875", "Web Developer", "100000.00", "Programming Advices");

    Employee1.Print();
    Employee1.SendEmail("Hi", "You pray that is your path is not deficall to be saved , so it will be deficall and you will be saved to know that salivation is not from the path it from the GOD *");
    Employee1.SendSMS("Please Call Me Back  ASAP");

    return 0;
}