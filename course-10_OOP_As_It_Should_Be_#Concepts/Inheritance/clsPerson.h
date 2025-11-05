#pragma once
#include <iostream>
using namespace std;

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