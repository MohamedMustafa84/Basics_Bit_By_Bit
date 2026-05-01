#include <iostream>
using namespace std;

class clsPerson
{

private:
    int _ID = 1020;
    string _firstName;
    string _lastName;

public:
    // read Only Property coz we dont have  set Property
        int ID(){
            return _ID;
        }

    // property set
    void SetFirstName(string firstName)
    {
        _firstName = firstName;
    }

    void SetLastName(string lastName)
    {
        _lastName = lastName;
    }

    // property get

    string GetfirstName()
    {
        return _firstName;
    }
    string GetLastName()
    {
        return _lastName;
    }
};

int main()
{

    clsPerson person1;

    person1.SetFirstName("Mohamed");
    person1.SetLastName("Mustafa");

    cout << "ID : " << person1.ID() << endl;
    cout << "fist Name :" << person1.GetfirstName() << endl;
    cout << "Last Name :" << person1.GetLastName() << endl;

    cout << "My Name IS" << person1.GetfirstName() + " " + person1.GetLastName() << endl;

    return 0;
}