#pragma once 

#include <iostream> 
#include <string>
using namespace std ;

class clsPerson{
    string _FirstName="";
    string _LastName="";
    string _Email="";
    string _Phone = "";

    public :
        clsPerson(string FirstName, string LastName, string Email, string Phone){
            _FirstName = FirstName;
            _LastName = LastName;
            _Email = Email;
            _Phone = Phone;
        }

        string FirstName(){
            return _FirstName;
        }
        void SetFirstName(string FirstName)
        {
            _FirstName = FirstName;
        }

        string LastName()
        {
            return _LastName;
        }
        void SetLastName(string LastName)
        {
            _LastName = LastName;
        }
        string FullName(){
            return _FirstName + " " + _LastName;
        }

        string
        Email()
        {
            return _Email;
        }
        void SetEmail(string Email)
        {
            _Email = Email;
        }

        string Phone()
        {
            return _Phone;
        }
        void SetPhone(string Phone)
        {
            _Phone = Phone;
        }
};
 class slTEst{
    public :
        string test;
 };